#!/usr/bin/python

import sys, datetime

minDel = checked = None

def search(vertices, edges, deleted):
    global minDel, checked
    if minDel != None and len(deleted) >= minDel:
        return
    if deleted in checked:
        return
    checked.add(deleted)
    neigh = {v:set() for v in vertices}
    for a,b in edges:
        neigh[a].add(b)
        neigh[b].add(a)
    roots = set()
    invalid = set()
    for v in vertices:
        if len(neigh[v]) == 2:
            roots.add(v)
        elif len(neigh[v]) not in (1,3):
            invalid.add(v)
    if not invalid and len(roots) == 1:
        if minDel == None or len(deleted) < minDel:
            minDel = len(deleted)
        return
    if len(roots) > 1:
        invalid.update(roots)
    for v in invalid:
        edges2 = []
        for e in edges:
            if v not in e:
                edges2.append(e)
        vertices2 = list(vertices)
        vertices2.remove(v)
        search(vertices2, edges2, tuple(sorted(deleted+(v,))))
        for w in neigh[v]:
            edges2 = []
            for e in edges:
                if w not in e:
                    edges2.append(e)
            vertices2 = list(vertices)
            vertices2.remove(w)
            search(vertices2, edges2, tuple(sorted(deleted+(w,))))


def solve(n, edges):
    global minDel, checked
    minDel = None
    checked = set()
    search(range(n), edges, ())
    return minDel if minDel != None else n-1




def main():
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

        n = int(inputFile.readline().strip())
        edges = []
        for i in xrange(n-1):
            a, b = map(int, inputFile.readline().strip().split())
            edges.append((a-1, b-1))

        string = 'Case #%d: %d' % (testCaseNumber, solve(n, edges))

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
