import collections
import sys


if len(sys.argv) == 1:
    sys.stdin = open("A.in")
else:
    sys.stdin = open(sys.argv[1])


def to_ints(s):
    return map(int, s.split())


def get_ints():
    return to_ints(raw_input())

n_cases = input()

for case in xrange(1, n_cases + 1):
    num, length = get_ints()
    outlets = [int(s, 2) for s in raw_input().split()]
    devices = [int(s, 2) for s in raw_input().split()]

    flips = collections.defaultdict(set)

    for device in devices:
        for outlet in outlets:
            flips[device ^ outlet].add(device)

    try:
        result = min(bin(flip).count("1")
                       for flip, deviceset in flips.iteritems()
                       if len(deviceset) == len(devices))
    except ValueError:
        result = "NOT POSSIBLE"

    print "Case #%d: %s" % (case, result)
