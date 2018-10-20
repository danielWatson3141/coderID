import copy

def change_num(i):
    ans = 0
    while i:
        ans += i % 2
        i /= 2
    return ans

def change(a, c):
    ans = copy.deepcopy(a)
    j = 1
    while c:
        if c % 2:
            cds = ans[j]
            for cd in cds:
                ans[cd].discard(j)
            del ans[j]
        c /= 2
        j += 1
    return ans

def test(x):
    root = None
    for k, v in x.items():
        d = len(v)
        if d == 2:
            if root is not None:
                return False
            root = k
        if d == 0:
            return False

    if root is None:
        return False

    ans = test_root(x, root, None)

    return ans

def test_root(x, r, p):
    c = x[r]
    if len(c) + int(p is None) not in (1, 3):
        return False
    for y in c:
        if y == p:
            continue
        if not test_root(x, y, r):
            return False
    return True

def solve():
    n = input()
    d = {}
    for _ in xrange(n-1):
        x, y = map(int, raw_input().split())
        d.setdefault(x, set())
        d[x].add(y)
        d.setdefault(y, set())
        d[y].add(x)

    ans = n
    for i in xrange(2**n):
        c = change_num(i)
        if c >= ans:
            continue

        x = change(d, i)
        if test(x):
            ans = c

    return ans

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s' % (i, solve())

if __name__ == '__main__':
    main()
