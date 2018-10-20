import itertools

INPUT_FILE = 'input.txt'
OUTPUT_FILE = 'output.txt'

def flipSwitch(outletFlow, switches):
    outletFlowTemp = outletFlow[:]
    for switch in switches:
        switch = int(switch)
        for i in range(len(outletFlowTemp)):
            if(outletFlowTemp[i][switch] == '0'):
                outlet = list(outletFlowTemp[i])
                outlet[switch] = '1'
                outletFlowTemp[i] = ''.join(outlet)
            else:
                outlet = list(outletFlowTemp[i])
                outlet[switch] = '0'
                outletFlowTemp[i] = ''.join(outlet)
    return outletFlowTemp

def charging(outletFlow, deviceFlow):
    outletFlowTemp = outletFlow[:]
    outletFlowTemp.sort()
    for device in deviceFlow:
        if device in outletFlow:
            outletFlowTemp.remove(device)
    return len(outletFlowTemp)

def function1(outletFlow, deviceFlow, eleLen):
    deviceFlow.sort()
    output = 0
    eleTempLength = ""
    for i in range(eleLen):
        eleTempLength += str(i)
    allCharged = False

    leftDevice = charging(outletFlow, deviceFlow)
    if leftDevice == 0:
        allCharged = True

    while not allCharged:
        output += 1
        changeList = itertools.combinations(eleTempLength, output)
        for flip in changeList:
            tempOutletFlow = flipSwitch(outletFlow, flip)
            leftDevice = charging(tempOutletFlow, deviceFlow)
            if leftDevice == 0:
                allCharged = True
                break
        if output == eleLen:
            break

    if leftDevice != 0:
        return "NOT POSSIBLE"
    return output

def mainFunciton():
    inputFile = open(INPUT_FILE, 'r')
    outputFile = open(OUTPUT_FILE, 'w')
    noTestCase = int(inputFile.readline())
    
    for i in xrange(noTestCase):
        
        #INPUT
        line = inputFile.readline().rstrip('\n').split(' ')
        noDevice = int(line[0])
        eleLen = int(line[1])
        outletFlow=inputFile.readline().rstrip('\n').split(' ')
        deviceFlow=inputFile.readline().rstrip('\n').split(' ')
        
        #COMPUTATION
        funOutput = function1(outletFlow, deviceFlow, eleLen)
        
        #OUTPUT
        outputLine =  "Case #" + str(i+1) + ": "
        outputLine += str(funOutput)
        outputFile.write(outputLine + '\n')
    
    inputFile.close()
    outputFile.close()

if __name__ == '__main__':
    mainFunciton()