import random

def main(ifn='cin.txt',ofn='cout.txt'):
    with open(ofn,'w') as ouf:
        for tnoc in xrange(1,121):
            ouf.write("Case #%d: " %(tnoc))
            if random.randint(0,1)==0:
                ouf.write("BAD\n")
            else:
                ouf.write("GOOD\n")
