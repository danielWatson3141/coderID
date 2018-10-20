import itertools
from sys import stdin


def flipBits(items, bitToFlip):
    return [i ^ (2**bitToFlip) for i in items]
        
def checkItems(L, initialFlow, requiredFlow):
    for item in initialFlow:
        if item not in requiredFlow:
            return False

    return True  # All items found!

def findFlip(L, initialFlow, requiredFlow, startBit=0, numToFlip=1):
    flipped = initialFlow
    for bit in range(startBit, startBit+numToFlip):
        flipped = flipBits(flipped, bit)

    print "checking:", startBit, numToFlip, map(bin, flipped)
    if checkItems(L, flipped, requiredFlow):
        return numToFlip
       
        

def handleTest(case, lines):
    N, L = map(int, lines[0].split(" "))

    initialFlow = map(lambda i: int(i, 2), lines[1].split(" "))
    requiredFlow = map(lambda i: int(i, 2), lines[2].split(" "))

    # Handle case where its' already done
    if checkItems(L, initialFlow, requiredFlow):
        print "Case #%d: 0" % case
        return

    # Single bit flip
    # for bit in range(L):
    #     flippedItems = flipBits(initialFlow, bit)
    #     if checkItems(L, flippedItems, requiredFlow):
    #         print "Case #%d: 1" % case
    #         return
    for num in range(L):
        choices = itertools.combinations(range(L), num)

        for bits in choices:
            numFlips = 0
            flipped = initialFlow
            for bit in bits:
                flipped = flipBits(flipped, bit)
                numFlips += 1

            if checkItems(L, flipped, requiredFlow):
                print "Case #%d: %d" % (case, numFlips)
                return

    print "Case #%d: NOT POSSIBLE" % case
    return


if __name__ == '__main__':
    data = stdin.read().strip()
    lines = data.split("\n")

    numTests = int(lines[0])

    case = 1
    index = 1
    while index < len(lines):
        # 3 lines per test
        testLines = lines[index:index + 3]

        handleTest(case, testLines)

        case += 1
        index += 3
