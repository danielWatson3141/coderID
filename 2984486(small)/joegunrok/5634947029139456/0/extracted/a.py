
import sys
RL = lambda: sys.stdin.readline().strip()
IA = lambda: map(int, RL().split(" "))
LA = lambda: map(long, RL().split(" "))

T = int(sys.stdin.readline())

for CASE in range(T):
    N, L = IA()
    O = [int('0b%s'%o,2)  for o in IA()]
    D = set(sorted([int('0b%s'%d,2) for d in IA()]))
    answer = None
    fewest = 10
    for i in range(2**10):
        o = set([n ^ i for n in O])
        if len(D-o) == 0:
            c = 0
            for n in range(10):
                if i & (1<<n):
                    c += 1
            if c <= fewest:
                answer = c
                fewest = c
    if answer is None:
        answer = "NOT POSSIBLE"
    print "Case #%d: %s" % (CASE+1, answer)

