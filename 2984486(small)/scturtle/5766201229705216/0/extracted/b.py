from itertools import combinations
from collections import defaultdict

def count(g, r):
    ans = 1
    q = [r]
    saw = set([r])
    while len(q):
        t = q.pop()
        for c in g[t]:
            if c not in saw:
                ans += 1
                saw.add(c)
                q.append(c)
    return ans

def assume_root(g, r):
    if len(g[r]) > 2:
        for c in g[r]: g[c].remove(r)
        best = 100000
        for a, b in combinations(g[r], 2):
            ans = assume_root(g, a) + assume_root(g, b) +\
                    sum(count(g, c) for c in g[r] if c != a and c != b)
            best = min(best, ans)
        for c in g[r]: g[c].add(r)
        return best
    elif len(g[r]) == 2:
        for c in g[r]: g[c].remove(r)
        ans2 = sum(assume_root(g, c) for c in g[r])
        for c in g[r]: g[c].add(r)
        return ans2
    elif len(g[r]) == 1:
        c = list(g[r])[0]
        g[c].remove(r)
        ans = count(g, c)
        g[c].add(r)
        return ans
    else:
        return 0

def main():
    cases = int(raw_input())
    for case in xrange(cases):
        n = int(raw_input())
        g = defaultdict(set)
        for i in xrange(n-1):
            a, b = map(int, raw_input().split())
            g[a].add(b)
            g[b].add(a)

        best = 10000
        for i in xrange(1, n+1):
            ans = assume_root(g, i)
            #print i, ans
            if ans < best:
                best = ans
                #print 'r', i, best

        print 'Case #{}: {}'.format(case+1, best)

main()
