from copy import deepcopy
from itertools import permutations

def reader(inpC):
    caseList = []
    p = 0
    lines = inpC.readlines(3)
    devices, switches = map(int, lines[0].split(' '))
    initFlow, elecNeeded = map(fixBool, lines[1].split(' ')), map(fixBool, lines[2].split(' '))

        
    return int(devices), int(switches), list(initFlow), list(elecNeeded)


def fixBool(str):
    return [True if b == "1" else False for b in str]

def solver(dependents, start = 0, flipped = 0, rF = None):
    #print ("Call:")
    #print (start, flipped, rF)
    if rF is None:
        rF = []
    devices, switches, initFlow, elecNeeded = dependents
    if 0:
        print ("-" * 20)
        b = bruteCheck(initFlow, elecNeeded)
        print ("X: " + str(b))
        return b
    elecNum = len(initFlow[0])
    devNum = (devices)

    rF = []

    mins = []
    for i in range(start, elecNum):
        devC = countOn(elecNeeded, i)
        swiC = countOn(initFlow, i)
        #print (devC, swiC)
        compSwi = devNum - swiC

        if swiC != devC and compSwi != devC:
            return "NOT POSSIBLE"
        if compSwi == devC and compSwi != swiC:
            
            flipSwitch(initFlow, i)
            rF.append(i)
            flipped += 1
        if compSwi == swiC and compSwi == devC:
            sF = deepcopy(initFlow)
            flipSwitch(sF, i)
            t = solver((devices, switches, sF, elecNeeded), i+1, flipped+1, deepcopy(rF))
     
            if t == "NOT POSSIBLE":
                continue
            else:
                
                mins.append(t)
            
            

    if compareRes(initFlow, elecNeeded):
        if len(mins) > 0:
            return min(min(mins), flipped)
        else:
            return flipped
    else:
        if len(mins) > 0:
            return min(mins)
        return "NOT POSSIBLE"
    
        
def bruteCheck(devices, switches):
    sb = deepcopy(switches)
    if len(switches[0]) > 7:
        return "TM"
    m = float("inf")
    best = None
    for comb in permutations(list(range(len(switches[0])))):
        i = 0
        switches = deepcopy(sb)
        for s in comb:
            if i > m:
                break
            #print (devices, switches)
            if compareRes(devices, switches):
                m = min(m, i)
                best = list(comb)
                break
            flipSwitch(switches, s)
            i+= 1
    print (best)
    switches = deepcopy(sb)
    if m > 0 and m < 10000:
        for b in best[:m]:
            flipSwitch(switches, b)
    print ([stringify(s) for s in switches])
    print ([stringify(s) for s in devices])
    if str(m) == "inf":
        return "NOT POSSIBLE"
    return m
def compareRes(dev, swi):
    newD, newS = [stringify(d) for d in dev], [stringify(s) for s in swi]

    return set(newD) == set(newS)

def stringify(devSwi):
    a = ""
    for v in devSwi:
        a += "1" if v else "0"
    return a
def countOn(devSwitch, n):
    i = 0
    for devS in devSwitch:
        if devS[n]:
            i+= 1
    return i

def rec(devices, switches, initFlow, elecNeeded):
    pass
def flipSwitch(switches, n):
    for switch in switches:
        switch[n] = not switch[n]

def maxActiveDevices(devices, switches):
    i = 0
    for device in devices:
        for switch in switches:
            if canActive(switch, device):
                i += 1
    return i

def canActive(switch, device):
    for s, d in zip(switch, device):
        if s != d:
            return False
    return True
    


from GCJ import GCJ
GCJ(reader, solver, "./", "a").run()
