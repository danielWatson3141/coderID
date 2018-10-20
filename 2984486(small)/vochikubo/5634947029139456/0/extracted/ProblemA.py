import sys
import string

def onesCount(a, b):
    az = a.count('1')
    bz = b.count('1')
    if az < bz:
        return -1
    elif az == bz:
        return 0
    else:
        return 1

def precompute(lwperms, maxN):
    for i in range(0,2<<maxN):
        s = bin(i)[2:]
        if len(s) < maxN:
            s = '0' * (maxN - len(s)) + s
        lwperms.append(s)
    lwperms.sort(onesCount)

def flip(ch):
    if ch == '0':
        return '1'
    else:
        return '0'

def invertCol(col, patterns, flipper):
    transpose = map(lambda a: "".join(a), zip(*patterns))
    transpose[col] = transpose[col].translate(flipper)
    return map(lambda a: "".join(a), zip(*transpose))

def makeDecisions(reqFlow, wallFlow, flipper, toDecide, nFlips):
    # If doesn't work, return -1

    # If we're done (made all choices)
    if len(toDecide) == 0:
        # Check to make sure we have everything
        if not set(reqFlow) == set(wallFlow):
            return -1
        else:
            return nFlips
#        for flow in wallFlow:
#            if not flow in reqFlow:
#                return -1
#        return nFlips
    else:
        # Make one decision.
        currDecision = toDecide[0]
        noFlipRes = makeDecisions(reqFlow, wallFlow, flipper, toDecide[1:], nFlips)
        flipRes = makeDecisions(reqFlow, invertCol(currDecision, wallFlow, flipper), flipper, toDecide[1:], nFlips + 1)
        if noFlipRes == -1 and flipRes == -1:
            return -1
        elif noFlipRes != -1 and flipRes == -1:
            return noFlipRes
        elif noFlipRes == -1 and flipRes != -1:
            return flipRes
        else:
            return min(noFlipRes, flipRes)
    

def do_test_case(ofile, curr_test_case, flipper, N, L, wallFlow, reqFlow):
    # print N, L, wallFlow, reqFlow
    # Get the counts of columns
    wallWeights = map(lambda s: s.count('1'), map(lambda a: "".join(a), zip(*wallFlow)))
    # Get counts of columns for required flow
    reqWeights = map(lambda s: s.count('1'), map(lambda a: "".join(a), zip(*reqFlow)))

    good = True

    # Find conflicting / imbalanced columns
    toDecide = []
    toFlip = []
    for index in range(0, L):
        reqW = reqWeights[index]
        wallW = wallWeights[index]
        if reqW == wallW: # Good to go
            pass
        elif reqW == N - wallW: # Need to flip
            toFlip.append(index)
        else: # Won't work
            good = False
            break

        if wallW == N - wallW: # Balanced
            toDecide.append(index)

    # We can do an invert with a double zip and a translate
    modWallFlow = wallFlow

    if not good:
        #print "No good."
        ofile.write("Case #" + str(curr_test_case) + ": NOT POSSIBLE\n")
    else:
        for ind in toFlip:
            modWallFlow = invertCol(ind, modWallFlow, flipper)
        nFlip = len(toFlip)

        # Print length of toDecide
        print "toDecide:", len(toDecide)
        decisions = makeDecisions(reqFlow, modWallFlow, flipper, toDecide, 0)
        if decisions == -1:
            #print "No good."
            ofile.write("Case #" + str(curr_test_case) + ": NOT POSSIBLE\n")
        else:
            #print "Answer: " + str(nFlip + decisions)
            ofile.write("Case #" + str(curr_test_case) + ": " + str(nFlip + decisions) + "\n")
                                  
    

def main():

    if len(sys.argv) != 3:
        print "Usage: ProblemA.py <input> <output>"
        exit()
    
    lowWeightPerms = []
    #precompute(lowWeightPerms, 15)
    flipper = string.maketrans("01", "10")

    with open(sys.argv[1], 'r') as ifile:
        with open(sys.argv[2], 'w') as ofile:
            ilines = ifile.readlines()
            ncases = int(ilines[0])
            ilines_idx = 1

            for curr_test_case in range(1, ncases + 1):
                [N, L] = map(lambda i: int(i), ilines[ilines_idx].split())
                wallFlow = ilines[ilines_idx + 1].split()
                reqFlow = ilines[ilines_idx + 2].split()
                ilines_idx += 3

                do_test_case(ofile, curr_test_case, flipper, N, L, wallFlow, reqFlow)

                
                
                

if __name__ == "__main__":
    main()
