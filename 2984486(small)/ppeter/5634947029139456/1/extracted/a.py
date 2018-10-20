__author__ = 'peter'
import numpy as np
import sys

def f(char):
    if char=="0":
        return False
    else:
        return True

res=[]
with open("A-large.in","r") as inF:
    t= int(inF.readline())
    for it in xrange(t):
        n,m= map(int, inF.readline().split())

        slots= map(lambda x: map(lambda y: f(y),x),inF.readline().split())
        dev=  map(lambda x: map(lambda y: f(y),x),inF.readline().split())

        dev=sorted(dev)

        minSwitch= sys.maxint
        for ic in xrange(len(slots)):
            switch=[]
            cSlot= slots[ic]
            cDev= dev[0]

            for i in xrange(len(cDev)):
                switch.append(cDev[i]!=cSlot[i])
            newSlots=[]
            for currSlot in slots:
                newSlot=[]
                for i in xrange(len(currSlot)):
                    if switch[i]:
                        newSlot.append(not currSlot[i])
                    else:
                        newSlot.append(currSlot[i])
                newSlots.append(newSlot)
            newSlots=sorted(newSlots)

            ident= True
            for i in xrange(len(newSlots)):
                for j in xrange(len(newSlots[i])):
                    if newSlots[i][j]!= dev[i][j]:
                        ident=False
                        break
            if ident:
                count=0
                for curr in switch:
                    if curr:
                        count+=1
                minSwitch= min(minSwitch,count)
        if minSwitch==sys.maxint:
            res.append("NOT POSSIBLE")
        else:
            res.append(str(minSwitch))

with open("A-large.out","w") as outF:
    for i in xrange(t):
        outF.write("Case #%d: %s\n"%(i+1,res[i]))