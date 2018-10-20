import sys
from copy import copy, deepcopy
import itertools


def isMatch(stateo, deviceso):
    devices = copy(deviceso)
    state = copy(stateo)
    while devices:
        device = devices.pop()
        for i in range(len(state)):
            if list(device) == list(state[i]):
                state.pop(i)
                break
        else:
            return False
    return True


def onesMatch(state, devices):
    for i in range(len(state[0])):
        if countOnes(state, i) != countOnes(devices, i):
            return False
    return True


def countOnes(state, bit):
    return len(filter(lambda flow: flow[bit] == '1', state))


def flip(state, bit):
    for i in range(len(state)):
        if state[i][bit] == '0':
            state[i][bit] = '1'
        else:
            state[i][bit] = '0'


def solve(N, L, originalstate, devices):
    state = map(list, copy(originalstate))
    count = 0
    skips = []
    for i in range(L):
        sones = countOnes(state, i)
        dones = countOnes(devices, i)
        if sones == dones:
            skips.append(i)
            continue
        else:
            #elif N - sones == dones:
            count += 1
            flip(state, i)

    solved = isMatch(state, devices)
    if solved:
        return count
    if not solved and onesMatch(state, devices):
        # possible solution
        copystate = deepcopy(state)
        mincount = False
        for i in range(1, len(skips)):
            for flips in itertools.combinations(skips, i):
                count += len(flips)
                for bit in flips:
                    flip(state, bit)
                if isMatch(state, devices):
                    if not mincount:
                        mincount = count
                    elif count < mincount:
                        mincount = count
                count -= len(flips)
                state = deepcopy(copystate)
        if mincount:
            return mincount

    return "NOT POSSIBLE"
    return count if isMatch(state, devices) else "NOT POSSIBLE"


if __name__ == '__main__':
    lines = sys.stdin.readlines()
    i = 1
    case = 1
    while i < len(lines):
        N, L = map(int, lines[i].strip().split())
        state = lines[i + 1].strip().split()
        devices = lines[i + 2].strip().split()
        sol = solve(N, L, state, devices)

        print "Case #%d: %s" % (case, sol)
        case += 1
        i += 3
