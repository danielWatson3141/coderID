# Qualification Round 2014
# Problem A. Magic Trick
# MichelJ

import sys
import logging
import StringIO
from itertools import chain

def echo(fn):
    def wrapped(*v, **k):
        name = fn.__name__
        logging.info( "Called %s(%s)" % (name, ", ".join(map(repr, chain(v, k.values())))) )
        res = fn(*v, **k)
        logging.info( "       %s(%s) returned %s" % (name, ", ".join(map(repr, chain(v, k.values()))),res) )
        return res
    return wrapped

def flip(o,f):
    return set(x^f for x in o)

def parity(f):
    return sum(int(x) for x in bin(f)[2:])

# Brute force

def solve1(n,l,outlets,devices):
    o = [int(x,2) for x in outlets]
    sd = set(int(x,2) for x in devices)
    minnf = 1000000000000
    for f in xrange(1<<l):
        fo = flip(o,f)
        if fo==sd:
            nf = parity(f)
            if nf<minnf:
                minnf=nf
    if minnf< 1000000000000:
        return str(minnf)
    return "NOT POSSIBLE"
            
    print n,l,outlets,devices
    
    
def main(data=None):
    if data is not None:
        sys.stdin = StringIO.StringIO(data)
    for tc in xrange(1, int(raw_input()) + 1):
        n,l = map(int, raw_input().split(' '))
        outlets = raw_input().split(' ')
        devices = raw_input().split(' ')
        print 'Case #%d: %s' % (tc, solve1(n,l,outlets,devices))
    if data is not None:
        sys.stdin = sys.__stdin__

sample="""3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01
"""


# Call main() only if run from command line, not from IDLE
if __name__ == "__main__":
    if True:
#    if '/' not in sys.argv[0] and '\\' not in sys.argv[0]:
        logging.basicConfig(level=logging.ERROR)
        sys.exit(main())
    else:
        logging.basicConfig(level=logging.INFO,format=" %(levelname)s: %(message)s")
