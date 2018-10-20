import string

file_name = "A-small-attempt1.in"

chargingInput = open(file_name, 'r')
data = string.split(chargingInput.read().strip(), '\n')
numCases = int(data[0])

def diffLoc(num1, num2, L):
    diffs = 0
    count = 0
    for i in range(L):
        if (num1 >> i)%2 != (num2 >> i)%2:
            diffs += 2**i
            count +=1
    return diffs, count

index = 1
for case in range(1,numCases+1):
    N, L = string.split(data[index],' ')
    N, L = int(N), int(L)
    chargList = [ sum([2**(L-1-i) * int(x[i]) for i in range(L)]) \
            for x in string.split(data[index+1]," ")]
    outletList =[ sum([2**(L-1-i) * int(x[i]) for i in range(L)]) \
            for x in string.split(data[index+2], " ")]
    index += 3
    minCount = 10000

    for chargedDevice in chargList:
        for outputDevice in outletList:
            diff, count = diffLoc(chargedDevice, outputDevice, L)
            if count > minCount:
                continue
            transformedInput = set([x ^diff for x in chargList])
            transformedOutput = set(outletList)
            if transformedInput == transformedOutput:
                minCount = count
    print "Case #" + str(case) +":",
    if minCount == 10000:
        print "NOT POSSIBLE"
    else:
        print minCount
