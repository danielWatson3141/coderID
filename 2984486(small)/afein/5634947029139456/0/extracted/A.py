import sys
import itertools

def match(list1, list2):
    for item in list1:
        if item not in list2:
            return False
    return True

T = int(sys.stdin.readline())
for testcase in range(T):
    # per testcase
    N, L = map(int, sys.stdin.readline().split())
    devices = sys.stdin.readline().split()
    outlets = sys.stdin.readline().split()

    possible_flips = ["".join(seq) for seq in itertools.product("01", repeat=L)]
    result = "NOT POSSIBLE"

    for mask in possible_flips:
        new_devices = devices[:]
        new_outlets = outlets[:]
        for i in range(N):
            new_devices[i] = bin(int(new_devices[i],2) ^ int(mask,2))[2:].zfill(L)
        if match(new_devices, new_outlets):
            result = str(mask.count('1'))
            break

    print "Case #" + str(testcase + 1) + ": " + result


