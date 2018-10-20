def flip_set(a, b):
    return sum((1 << i) for i in xrange(len(a)) if a[i] != b[i])


def flip(h, s):
    ret = ['a'] * len(h)
    for x in xrange(len(h)):
        if s & (1 << x):
            ret[x] = '1' if h[x] == '0' else '0'
        else:
            ret[x] = h[x]
    return ''.join(ret)


def solve(needs, haves):
    n, l = len(needs), len(needs[0])
    res = 123123
    for x in xrange(n):
        fset = flip_set(needs[0], haves[x])
        haves_t = [flip(h, fset) for h in haves]
        haves_t.sort()
        needs_t = needs[:]
        needs_t.sort()

        if needs_t == haves_t:
            res = min(res, sum(1 for x in xrange(l) if (fset & (1 << x))))

    return (str(res) if res < 123123 else 'NOT POSSIBLE')


def main():
    num_cases = int(raw_input())
    for cas in xrange(1, num_cases + 1):
        n, l = map(int, raw_input().split())
        haves = raw_input().split()
        needs = raw_input().split()

        print "Case #%d: %s" % (cas, solve(haves, needs))


if __name__ == '__main__':
    main()
