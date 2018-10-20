import sys

def flip(l, n):
    flipper = 1 << n
    for i in range(len(l)):
        l[i] ^= flipper
    return

def recurse(outlets, required, cur):
    if cur < 0:
        if set(outlets) ^ set(required):
            return -1
        else:
            return 0
    num1 = recurse(outlets, required, cur - 1)
    flip(outlets, cur)
    num2 = recurse(outlets, required, cur - 1)
    flip(outlets, cur)
    num2 = num2 + 1 if num2 != -1 else num2
    if num1 == -1:
        return num2
    elif num2 == -1:
        return num1
    else:
        return min(num1, num2)


def solve():
    outletNum, length = map(int, sys.stdin.readline().split())
    outlets = list(map(lambda x: int(x, 2), sys.stdin.readline().split()))
    required = list(map(lambda x: int(x, 2), sys.stdin.readline().split()))
    num = recurse(outlets, required, length - 1)
    if num != -1:
        return str(num)
    else:
        return 'NOT POSSIBLE'

if __name__ == '__main__':
    cases = int(sys.stdin.readline().split()[0])
    for i in range(cases):
        print('Case #%d: %s' % (i + 1, solve()))
