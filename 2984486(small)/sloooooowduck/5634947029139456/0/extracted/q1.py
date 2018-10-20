__author__ = 'rcarino'
import sys, itertools


def findMin(cur, target):
    n_bits = len(cur[0])
    for perm in sorted(["".join(seq) for seq in itertools.product("01", repeat=n_bits)], key=lambda s: s.count('1')):
        perm = int(perm, 2)
        flip = ["{0:b}".format(int(s, 2) ^ perm).zfill(n_bits) for s in cur]
        if sorted(flip) == sorted(target):
            return '{0:b}'.format(perm).count('1')
    return 'NOT POSSIBLE'



with open(sys.argv[1]) as f:
    content = f.readlines()
    for i in range(int(content.pop(0))):
        content.pop(0)
        cur = content.pop(0).strip().split(' ')
        target = content.pop(0).strip().split(' ')
        print "Case #{0}: {1}".format(i+1, findMin(cur, target))
