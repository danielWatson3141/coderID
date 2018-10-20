#!/usr/bin/python

import sys, datetime

flows = devices = minL = n = l = None

def search(sets, j, c):
    global minL
    if j == l:
        if minL == None or c < minL:
            minL = c
        return
    s1 = set(filter(lambda i:flows[i][j] == '0', xrange(n)))
    s2 = set(xrange(n)).difference(s1)
    sets1 = []
    for i in xrange(n):
        if devices[i][j] == '0':
            s = sets[i].intersection(s1)
            if s:
                sets1.append(s)
            else:
                sets1 = None
                break
        else:
            s = sets[i].intersection(s2)
            if s:
                sets1.append(s)
            else:
                sets1 = None
                break
    if sets1:
        search(sets1, j+1, c)
    sets2 = []
    for i in xrange(n):
        if devices[i][j] == '1':
            s = sets[i].intersection(s1)
            if s:
                sets2.append(s)
            else:
                sets2 = None
                break
        else:
            s = sets[i].intersection(s2)
            if s:
                sets2.append(s)
            else:
                sets2 = None
                break
    if sets2:
        search(sets2, j+1, c+1)


def solve():
    global minL
    minL = None
    search([set(range(n)) for i in xrange(n)], 0, 0)
    return 'NOT POSSIBLE' if minL == None else minL




def main():
    global flows, devices, n, l
    if len(sys.argv) < 2:
        print 'Please provide input file'
        print 'Usage: %s inputfile [outputfile]' % sys.argv[0]
        return
    timestart = datetime.datetime.now()

    try:
        inputFile = open(sys.argv[1])
    except:
        print 'Failed to read input file %s' % sys.argv[1]
        return
    try:
        outputFile = open(sys.argv[2], 'w') if len(sys.argv) >= 3 else None
    except:
        print 'Failed to create output file %s' % sys.argv[2]
        return

    testCases = int(inputFile.readline().strip())

    print '-----------------'
    print 'Test cases: %d ' % testCases
    print 'No output file' if len(sys.argv) < 3 else 'Writing to %s' % sys.argv[2]
    print '-----------------'

    for testCaseNumber in range(1, testCases+1):

        n, l = map(int, inputFile.readline().strip().split())
        flows = inputFile.readline().strip().split()
        devices = inputFile.readline().strip().split()

        string = 'Case #%d: %s' % (testCaseNumber, solve())

        print string
        if outputFile:
            outputFile.write(string + '\n')

    print '-----------------'
    print 'Written to %s' % sys.argv[2] if outputFile else 'No output file'
    print 'Elapsed time: %s' % (datetime.datetime.now() - timestart)
    print '-----------------'

    inputFile.close()
    if outputFile:
        outputFile.close()

if __name__=='__main__':
    main()
