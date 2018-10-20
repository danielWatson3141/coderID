# Problem A-small

import sys
import itertools

# O(N^2)
def is_soln (avail_ef, need_ef):
    for ef in need_ef:
        if ef not in avail_ef:
            return(False)
    return(True)
            

# O(N * size(mybits))
def flip_bits(myef, mybits):
    outef = []
    for ef in myef:
        newef = list(ef)
        for bit in mybits:
            if ef[bit] == '0':
                newef[bit] = '1'
            else:
                newef[bit] = '0'
        outef += ["".join(newef)]
    
    return(outef)

# Do we have a solution with nbits flipped
def soln(avail_ef, need_ef, S, nbits):
    L = list(itertools.combinations(S,nbits))
    for combo in L:
        outef = flip_bits(avail_ef, list(combo))
        if is_soln (outef, need_ef):
            return(True)

def main():
    infile = open(sys.argv[1], 'r')
    outfile = open(sys.argv[2], 'w')

    line = infile.readline()
    T = int(line)

    for t in range(1,T+1):
        N, L = infile.readline().strip("\n").split(" ")
        N = int(N)
        L = int(L)
        avail_ef = infile.readline().strip("\n").split(" ")
        need_ef = infile.readline().strip("\n").split(" ")

        if is_soln (avail_ef, need_ef):
            outfile.write("Case #{0}: 0\n".format(t))
            print("Case #{0}: 0\n".format(t))
            continue
        
        possible = False
        S = range(0,L)    
        for b in range(1,L+1):
            if soln(avail_ef, need_ef, S, b):
                outfile.write("Case #{0}: {1}\n".format(t, b))
                print("Case #{0}: {1}\n".format(t, b))
                possible = True
                break
        if not possible:
            outfile.write("Case #{0}: NOT POSSIBLE\n".format(t))
            print("Case #{0}: NOT POSSIBLE\n".format(t))

    infile.close()
    outfile.close()

if __name__ == '__main__':
    main()
