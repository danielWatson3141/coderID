def importCases(inputFileName):
    data = [i.strip() for i in open(inputFileName).readlines()]
    data = [x.split() for x in data]
    caseCount=int(data[0][0])
    # change based on how many lines there are in each case
    caseLength=3

    def extractCases(data, caseCount, caseLength):
        return [data[1+caseID*caseLength:1+(caseID+1)*caseLength] for caseID in range(caseCount)]
    
    cases=extractCases(data, caseCount, caseLength)
    return cases

def processCase(case):
    (n, l)=[int(x) for x in case[0]]
    
    t=[int(x,2) for x in case[1]]
    s=sorted([int(x,2) for x in case[2]])

    minSwitches=float("inf")
    
    import itertools
    
    for mask in range(0, 2**l):
        t_masked=map(lambda x: x^mask, t)
        t_masked.sort()
        if t_masked==s:
            binaryMask="{0:b}".format(mask)
            minSwitches=min([minSwitches, binaryMask.count('1')])
    if minSwitches==float("inf"):
        return 'NOT POSSIBLE'
    else:
        return str(minSwitches)
            
##        caseText='Case #'+str(caseID)+': '
##        return caseText+str(solution)+'\n'

def exportOutput(inputFileName):
    cases=importCases(inputFileName)
    output='\n'.join(['Case #'+str(caseID+1)+': '+processCase(case) for (caseID, case) in enumerate(cases)])
    outputFileName=inputFileName.replace('.in','-output.txt')
    f=open(outputFileName, 'wb')
    f.write('')
    f.writelines(output)
    f.close()
