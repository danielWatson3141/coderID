#!/usr/bin/env python

from collections import deque

FILENAME = 'A-small-attempt0.in'

def load_dataset(q):
    ignore = q.popleft()
    i = q.popleft().split(' ')
    d = q.popleft().split(' ')


    initial = i
    devices = d

    return (initial, devices)

def load_from_file():
    result = None

    with open(FILENAME) as f:
        result = [line.rstrip('\n') for line in f]

    return deque(result)

def check(outlet, device):
    size = len(outlet)

    for x in xrange(0, size):
        if outlet[x] != device[x]:
            return false

    return true

def flip(outlets, key):
    size = len(outlets)
    length = len(outlets[0])

    big_stuff = []
    for x in xrange(0, size):
        result = []
        item = outlets[x]

        for y in xrange(0, length):
            if key[y] != '0':
                #flip
                if item[y] == '0':
                    result.append('1')
                else:
                    result.append('0')
            else:
                result.append(item[y])

        big_stuff.append(''.join(result))

    return big_stuff

def match(outlet, device):
    size = len(outlet)
    result = []
    flips = 0

    for x in xrange(0, size):
        if outlet[x] == device[x]:
            result.append('0')
        else:
            flips += 1
            result.append('1')

    return (''.join(result), flips)

def check_up(outlets, devices):
    mine = dict()

    for x in xrange(0, len(outlets)):
        mine[outlets[x]] = 1

    for y in xrange(0, len(devices)):
        if devices[y] in mine:
            del  mine[devices[y]]
        else:
            return False

    return len(mine) == 0

def main():
    data = load_from_file()
    number_of_cases = int(data.popleft())

    for x in range(0, number_of_cases):
        outlets = []
        devices = []
        (outlets, devices) = load_dataset(data)

        size = len(outlets)
        key = ''
        best = 10000
        status = False
        for y in xrange(0, size):
            flips = 0
            (key, flips) = match(outlets[y], devices[0])
            arrangement = flip(outlets, key)


            status = check_up(arrangement, devices)

            if status:
                if best > flips:
                    best = flips

        answer = ''
        if best == 10000:
            answer = 'NOT POSSIBLE'
        else:
            answer = best

        print 'Case #' + str(x+1) + ': ' + str(answer)


if __name__ == "__main__":
    main()
