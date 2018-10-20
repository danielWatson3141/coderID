import sys

def stringListToIntList(stringList):
    result = list()
    for number in stringList:
        result.append(int(number))

    return result

def stringListToCharLists(stringList):
    result = list()
    for number in stringList:
        result.append(list(number))

    return result

f = open("A-small-attempt0.in", 'r')
o = open("Output2.txt", 'w')

T = int(f.readline())

for X in range(1, T+1):
    N, L = stringListToIntList(f.readline().split())
    #current = f.readline().strip().split()
    #ideal = f.readline().strip().split()
    current = stringListToCharLists(f.readline().strip().split())
    ideal = stringListToCharLists(f.readline().strip().split())
    bitCountsIdeal = list()
    bitCountsCurrent = list()
    needFlip = list()
    impossible = False

    for i in range(L):
        bitCountsIdeal.append(0)
        bitCountsCurrent.append(0)
        for j in range(N):
            if ideal[j][i] == "1":
                bitCountsIdeal[i] += 1
            if current[j][i] == "1":
                bitCountsCurrent[i] += 1

        if bitCountsIdeal[i] != bitCountsCurrent[i] and bitCountsIdeal[i] != (N - bitCountsCurrent[i]):
            impossible = True
        else:
            if bitCountsIdeal[i] != bitCountsCurrent[i]:
                needFlip.append(True)
            else:
                needFlip.append(False)

    def satisfied():
        outlets = list(range(N))
        for device in range(N):
            found = False
            index = -1
            for i, outlet in enumerate(outlets):
                if ideal[device] == current[outlet]:
                    found = True
                    index = i
                    break
            if found:
                del outlets[index]
            else:
                return False

        return True
        
    def flip(i):
        for j in range(N):
            if current[j][i] == "1":
                current[j][i] = "0"
            else:
                current[j][i] = "1"

    def recursiveFlipCheck(i, flips):
        if satisfied():
            return flips
        elif i == L:
            return sys.maxsize
        else:
            flipped = sys.maxsize
            notFlipped = sys.maxsize
            flip(i)
            #print(current)
            flipped = recursiveFlipCheck(i+1, flips+1)
            flip(i)
            #print(current)

            notFlipped = recursiveFlipCheck(i+1, flips)

            return min((flipped, notFlipped))

    result = ""
    if impossible:
        result = "NOT POSSIBLE"
    else:
        minFlips = sys.maxsize
        result = str(recursiveFlipCheck(0, 0))
        

    #print(ideal)
    #print(bitCountsIdeal)

    print("Case #", X, ": ", result, sep='')
    o.write("Case #" + str(X) + ": " + result + "\n")

o.close()
