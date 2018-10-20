import sys
import collections
sys.setrecursionlimit(3000)
T = int(raw_input())
for t in xrange(1, T + 1):
    N = input()
    count = collections.Counter()
    neighbor = collections.defaultdict(list)
    for i in xrange(N - 1):
        src, dst = map(int, raw_input().split())
        count[src] += 1
        count[dst] += 1
        neighbor[src].append(dst)
        neighbor[dst].append(src)
#    print count
#    print neighbor
    def check(key, src):
#        print key, src
        ret = 0
        if src is None:
            ret += 1
            if count[key] >= 2:
                temp = []
                for n in neighbor[key]:
                    temp.append(check(n, key))
                temp.sort(reverse=True)
                ret += temp[0]
                ret += temp[1]
#                print key, src, temp
            return ret
        else:
            ret += 1
            if count[key] >= 3:
                temp = []
                for n in neighbor[key]:
                    if n == src:
                        continue
                    temp.append(check(n, key))
                temp.sort(reverse=True)
                ret += temp[0]
                ret += temp[1]
#                print key, src, temp
            return ret
        
    result = 10000000
    for key in count:
        result = min(result, N - check(key, None))
#        print key, check(key, None)
    print "Case #{0}: {1}".format(t, result)
