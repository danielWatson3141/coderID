def importCases(inputFileName):
    data = [i.strip() for i in open(inputFileName).readlines()]
    data = [x.split() for x in data]
    caseCount=int(data[0][0])
    # change based on how many lines there are in each case
    caseLength=2

    def extractCases(data, caseCount, caseLength):
        return [data[1+caseID*caseLength:1+(caseID+1)*caseLength] for caseID in range(caseCount)]
    
    cases=extractCases(data, caseCount, caseLength)
    return cases

c=importCases('C-sample.in')

import numpy

def processCase(case):
    [n]=[int(x) for x in case[0]]
    
    permutation=[int(x) for x in case[1]]
    zeros=list(numpy.subtract(permutation, range(n))).count(0)
    if zeros==0:
        return 'GOOD'
    elif zeros>=1:
        return 'BAD'
    #elif zeros==1:
        #return numpy.random.choice(['GOOD', 'BAD'])
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
