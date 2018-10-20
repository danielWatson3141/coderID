
import sys
RL = lambda: sys.stdin.readline().strip()
IA = lambda: map(int, RL().split(" "))
LA = lambda: map(long, RL().split(" "))

T = int(sys.stdin.readline())

for CASE in range(T):
    N, L = IA()
    O = [int('0b%s'%o,2)  for o in IA()]
    D = set(sorted([int('0b%s'%d,2) for d in IA()]))
    min = 50
    if len(D-set(O)) == 0:
        min = 0
    else:
        for i in range(N):
            b = list(D)[0] ^ O[i]
            o = set([x ^ b for x in O])
            if len(o-D) == 0:
                c = 0
                for i in range(L+1):
                    if b & (1<<i):
                        c+=1
                if c < min:
                    min = c
    answer = min if min < 50 else "NOT POSSIBLE"
    print "Case #%d: %s" % (CASE+1, answer)

