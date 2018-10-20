
def change_num(i):
    ans = 0
    while i:
        ans += i % 2
        i /= 2
    return ans

def change(a, c):
    ans = [[int(y) for y in x] for x in a]
    j = 0
    while c:
        if c % 2:
            for x in ans:
                x[j] = 1 - x[j]
        c /= 2
        j += 1
    ans = [''.join(map(str, x)) for x in ans]
    return sorted(ans)

def solve():
    n, l = map(int, raw_input().split())
    a = raw_input().split()
    b = raw_input().split()

    b.sort()

    ans = l + 1

    for i in xrange(2**l):
        c = change_num(i)
        if c >= ans:
            continue

        x = change(a, i)
        if x == b:
            ans = c

    if ans == l + 1:
        return 'NOT POSSIBLE'
    return ans

def main():
    t = int(raw_input())
    for i in xrange(1, t+1):
        print 'Case #%s: %s' % (i, solve())

if __name__ == '__main__':
    main()
