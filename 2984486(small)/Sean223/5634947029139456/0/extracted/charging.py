'''
Created on Apr 25, 2014

@author: Sean
'''
fin = open('A-small.in', 'r')
finput = fin.readlines()
fin.close()

it = iter(finput)

numbCases = (int)(it.next())

output = ""

for case in xrange(numbCases):
    [n, L] = (it.next()).split()
    n = int(n)
    L = int(L)
    
    outlets = [list(j) for j in ((it.next()).split())]
    devices = [list(j) for j in ((it.next()).split())]
    
    minSwitches = 10000000000000
    
    testDevices = [newDevice[:] for newDevice in devices[1:]]
    testDevices.sort()
    device = devices[0]
    
    
    
    for i in xrange(n):
        #assign the first device to outlet outletNum
        
        outlet = outlets[i][:]
        
        testOutlets = [newOutlet[:] for newOutlet in outlets]
        
        testOutlets.pop(i)
        
        switches = ['0' for j in xrange(L)]
        
        for i in xrange(L):
            if not (outlet[i] == device[i]):
                switches[i] = '1'
        
        for tO in testOutlets:
            for i in xrange(L):
                if (switches[i] == '1'):
                    if (tO[i] == '0'):
                        tO[i] = '1'
                    else:
                        tO[i] = '0'
        
        testOutlets.sort()
        
        works = True
        
        for i in xrange(0, n-1):
            if not works:
                break
            for j in xrange(L):
                if not (testOutlets[i][j] == testDevices[i][j]):
                    works = False
                    break
                
        #print testOutlets, testDevices, works
        
        if works:
            newCount = switches.count('1')
            if (newCount < minSwitches):
                minSwitches = newCount
    
    
    if (minSwitches > 1000):
        output += "Case #%d: NOT POSSIBLE\n" % (case+1)
    else:
        output += "Case #%d: %d\n" % (case+1, minSwitches)
        
    
fout = open('small.txt', 'w')
fout.write(output)
fout.close