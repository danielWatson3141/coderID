def flip(ch):
    return '1' if ch == '0' else '0'

INF = 1000000000

if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        N, L = [int(s) for s in raw_input().split()]
        outlets = [s for s in raw_input().split()]
        devices = [s for s in raw_input().split()]
        devices.sort()

        best = INF
        for i in xrange(0, 2**L + 1):
            cnt = 0
            ls = []
            flipped = outlets[:]
            for j in xrange(0, L):
                if i & (2 ** j):
                    cnt += 1
                    for k in xrange(len(flipped)):
                        flipped[k] = flipped[k][:j] + flip(flipped[k][j]) + flipped[k][j+1:]
            flipped.sort()
            if flipped == devices and best > cnt:
                best = cnt

        sol = str(best) if best < INF else "NOT POSSIBLE"
        print 'Case #%d: %s' % (caseno + 1, sol)
