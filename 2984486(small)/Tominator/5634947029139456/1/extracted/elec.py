
import sys
def read(): sys.stdout.flush(); return sys.stdin.readline().strip()

def count_bits(x):
    return sum(1 for i in xrange(40) if x & (1 << i))

def run(L, flows, needed):
    best = 10000
    all_to_try = set(x^y for x in flows for y in needed)

    for i in all_to_try:
        if count_bits(i) < best:
            F = set(i ^ f for f in flows)
            if F == needed:
                best = count_bits(i)
                
    if best == 10000:
        return "NOT POSSIBLE"
    else:
        return best

tests = int(read())
for test in xrange(tests):
    sn, sl = read().split(" ")
    N, L = int(sn), int(sl)
    flows = set(eval("0b" + x) for x in read().split(" "))
    needed = set(eval("0b" + x) for x in read().split(" "))

    ans = run(L, flows, needed)
    print "Case #%d: %s" % (test+1, ans)
