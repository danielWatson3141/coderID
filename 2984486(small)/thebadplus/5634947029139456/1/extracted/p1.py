#!/usr/bin/python

f = open('input.in','r')
lines = f.readlines()
l = 0

def parseInt():
    global lines, l
    val = int(lines[l].strip())
    l += 1
    return val

def parseIntArray():
    global lines, l
    val = [ int(x) for x in lines[l].strip().split(' ') ]
    l += 1
    return val

def parseBinArray():
    global lines, l
    val = [ int(x,2) for x in lines[l].strip().split(' ') ]
    l += 1
    return val

def parseStrArray():
    global lines, l
    val = [ x for x in lines[l].strip().split(' ') ]
    l += 1
    return val


def solveCase(case_number, N, L, initial, desired):
#    print '#' * 70
#    print 'Case #',case_number,
#    print 'n',N,'l',L,'initial',initial,'desired',desired

    minSwitches = None
    for d in desired:
        mask = initial[0] ^ d

        # count the number of switches in the mask
        switches = bin(mask).count('1')
        if minSwitches and minSwitches < switches:
            continue    # not even worth pursuing

        # check if the mask is correct
        valid = True
        for i in initial:
            if i ^ mask not in desired:
                valid = False
                break

        if valid:
            minSwitches = switches


    if minSwitches != None:
        print 'Case #%d: %d' % (case_number, minSwitches)
    else:
        print 'Case #%d: NOT POSSIBLE' % case_number

testcases = parseInt()
case_number = 1
for testcase in xrange(testcases):
    # parse the input
    arr = parseIntArray()
    N = arr[0]
    L = arr[1]

    initial = parseBinArray()
    desired = parseBinArray()

    # determine the correct card
    solveCase(case_number, N, L, initial, desired)
    case_number += 1
    

