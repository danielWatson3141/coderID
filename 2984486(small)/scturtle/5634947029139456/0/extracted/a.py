import heapq

def change_at(outlets, b):
    ans = []
    for o in outlets:
        ans.append(o[:b] + ('0' if o[b] == '1' else '1') + o[b+1:])
    return ans


def main():
    cases = int(raw_input())
    for case in xrange(cases):
        n, l = map(int, raw_input().split())
        outlets = raw_input().split()
        devices = raw_input().split()

        d_set = set(devices)

        best = 10000
        for i in xrange(1 << l):
            os = outlets
            for b in xrange(l):
                if (1<<b) & i != 0:
                    os = change_at(os, b)
            #print set(os), d_set, i
            if set(os) == d_set and bin(i)[2:].count('1') < best:
                best = bin(i)[2:].count('1')

        print 'Case #{}: {}'.format(case+1, best if best != 10000 else 'NOT POSSIBLE')
main()
