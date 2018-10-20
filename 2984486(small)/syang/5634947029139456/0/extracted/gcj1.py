#!/usr/bin/env python
from sys import argv

def getStats(l):
    length = len(l[0])
    
    stats = []
    for i in range(length):
        stats.append(sum([int(w[i]) for w in l]))
    return stats

def compare(stata, statb, dn):
    length = len(stata)
    
    results = []
    for i in range(length):
        if stata[i] == statb[i]:
            if stata[i] + statb[i] == dn:
                results.append(-1)
            else:
                results.append(0)
        else:
            if stata[i] + statb[i] == dn:
                results.append(1)
            else:
                results.append(-2)
    return results

def trySwitches(outlets, devices, pos, alter = False):
    #print 'all pos:', pos    
    nos = []
    for outlet in outlets:
        nos.append(outlet)
        
    for j in range(len(nos)):
        for i in pos:
            outlet = nos[j]
            nos[j] = outlet[:i] + str((int(outlet[i]) + 1) % 2) + outlet[i+1:]
        
        if alter:
            outlets[j] = nos[j]
    nos.sort()    
    
    nds = []
    for outlet in devices:
        nds.append(outlet)
    nds.sort()
    
    for i in range(len(nos)):
        for j in pos:
            if not nos[i][j] == nds[i][j]:
                return
    
    return outlets

def testSwitches(outlets, devices, pos):    
    nos = []
    for outlet in outlets:
        nos.append(outlet)
        
    for j in range(len(nos)):
        for i in pos:
            outlet = nos[j]
            nos[j] = outlet[:i] + str((int(outlet[i]) + 1) % 2) + outlet[i+1:]
    nos.sort()    
    
    nds = []
    for outlet in devices:
        nds.append(outlet)
    nds.sort()
    
    for i in range(len(nos)):
        if not nos[i] == nds[i]:
            return
    
    #print 'tested to be valid'
    #print nos
    #print nds
    return outlets

def subsets(my_set):
    result = [[]]
    for x in my_set:
        result = result + [y + [x] for y in result]
    return result

if __name__ == '__main__':
    fn = argv[1]
    f = open(fn)
    
    n = int(f.readline().strip())
    for i in range(n):
        dn, ln = f.readline().strip().split()
        dn = int(dn)
        ln = int(ln)
        #print dn, ln
        
        outlets = f.readline().strip().split()
        devices = f.readline().strip().split()
        #print outlets
        #print devices
        
        
        stata, statb = getStats(outlets), getStats(devices)
        #print stata, statb
        results = compare(stata, statb, dn)
        
        test = [result for result in results if result == -2]
        if test:
            print 'Case #%d: NOT POSSIBLE' % (i + 1)
            continue
        
        if True:
            maybeswitch = [0 if result == 0 else 1 for result in results]
            #print 'maybeswitch:', maybeswitch, results
            npos = []
            for j in range(len(maybeswitch)):
                if maybeswitch[j] == 1:
                    npos.append(j)
            npos.sort()
            ssnpos = subsets(npos)
            ssnpos.sort(key = lambda x: len(x))
            
            found = False
            #print outlets
            #print devices
            for snpos in ssnpos:
                if testSwitches(outlets, devices, snpos):
                    print 'Case #%d: %d' % (i + 1, len(snpos))
                    #print snpos
                    #print 'case found'
                    found = True
                    break
            if not found:
                print 'Case #%d: NOT POSSIBLE' % (i + 1)
            continue
        
        
        
        #print 'results:', results
        switches = [1 if result == dn else 0 for result in results]
        pos = []
        for j in range(len(switches)):
            if switches[j] == 1:
                pos.append(j)
        pos.sort()
        #print 'results:', results
        
        #print outlets
        #print 'this is pos:', pos
        if not trySwitches(outlets, devices, pos, True):
            print 'Case #%d: NOT POSSIBLE' % (i + 1)
            #print devices
            continue
        #print outlets
        
        maybeswitch = [1 if result == -1 else 0 for result in results]
        #print 'maybeswitch:', maybeswitch, results
        npos = []
        for j in range(len(maybeswitch)):
            if maybeswitch[j] == 1:
                npos.append(j)
        npos.sort()
        #print 'npos:', npos
        
        ssnpos = subsets(npos)
        ssnpos.sort(key = lambda x: len(x))
        
        found = False
        #print outlets
        #print devices
        for snpos in ssnpos:
            if testSwitches(outlets, devices, snpos):
                print 'Case #%d: %d' % (i + 1, len(pos) + len(snpos))
                #print snpos
                #print 'case found'
                found = True
                break
        if not found:
            print 'Case #%d: NOT POSSIBLE' % (i + 1)
        #print outlets
        #print test
        #print compare(stata, statb)
