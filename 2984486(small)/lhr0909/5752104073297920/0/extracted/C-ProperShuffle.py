from itertools import *


def solve(filename):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')

    goodcount = 0
    badcount = 0
    T = int(fin.readline())
    for case in xrange(T):
        answer = ""
        #data read
        N = int(fin.readline())
        numbers = map(int, fin.readline().strip().split(' '))
        #print numbers
        #if x in i'th spot, that means i can't be in x'th spot.
        #i can't be at i'th spot
        for i in xrange(N):
            x = numbers[i]
            if x == i:
                answer = "BAD"
                badcount += 1
                break
            # if numbers[x] == i:
            #     answer = "BAD"
            #     badcount += 1
            #     break
        if answer == "":
            answer = "GOOD"
            goodcount += 1
        print answer
        fout.write(('Case #%d: ' % (case + 1)) + str(answer) + '\n')
        print goodcount, badcount

    fin.close()
    fout.close()

if __name__ == "__main__":
    solve("C-small-attempt1")