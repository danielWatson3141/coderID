import sys
import itertools
from random import randint

def check_good_bad(perm, n):
    points = 0
    for x in perm:
        if perm[x-1] == x:
            points+=1
        if perm[x-2] == x:
            points-=1
    return points


def bad_algorithm(n):
    a = range(n)
    for k, _ in enumerate(a):
        p = randint(0, n-1)
        a[k], a[p] = a[p], a[k]
    return a


def main(argv=sys.argv):

    count = int(sys.stdin.readline())
    res = []
    rez = 0
    for i in range(count):
        n = int(sys.stdin.readline())
        perm = map(int, sys.stdin.readline().split(' '))
        # Read inputs
        temp = check_good_bad(perm, n)
        rez += temp
        res.append(temp)
        middle = rez/count
    for i in range(count):
        sys.stdout.write(
            'Case #{0}: {1} \n'.format(
                i+1,
                'GOOD' if res[i] > middle else 'BAD'
            )
        )
if __name__ == '__main__':
    main()
