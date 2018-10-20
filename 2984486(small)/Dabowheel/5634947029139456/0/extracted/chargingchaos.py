'''
Created on Apr 25, 2014

@author: Miguel Provencio
'''

from sys import stdin
from math import pow

def GetTestCases():
    line = stdin.readline().strip()
    return int(line)

class ChargingChaos:
    def __init__(self):
        pass
    
    def GetSizes(self):
        line = stdin.readline().strip()
        args = line.split(" ")
        self.N = int(args[0])
        self.L = int(args[1])
        
    def GetOutlets(self):
        line = stdin.readline().strip()
        args = line.split(" ")
        for i,val in enumerate(args):
            val = self.reverseString(val)
            args[i] = int(val,2)
        return set(args)
    
    def reverseString(self,s):
        return s[::-1]
    
    def GetInput(self):
        self.GetSizes()
        self.initial = self.GetOutlets()
        self.needed = self.GetOutlets()
        
    def Match(self,a,b):
        return a == b
    
    def Flip(self,flow,bits):
        return flow ^ bits
    
    def FlipSet(self,flowSet,bits):
        s = set()
        for x in flowSet:
            s.add(self.Flip(x,bits))
        return s
        
    def CountBitFlips(self,num):
        count = 0
        while num > 0:
            if (num & 1) == 1:
                count += 1
            num = num >> 1
        return count

    def TryFlips(self):
        self.possibleFlips = []
        self.flipCountSet = set()
        for i in xrange(int(pow(2,self.L))):
            flipCount = self.CountBitFlips(i)
            newSet = self.FlipSet(self.initial,i)
            if newSet == self.needed:
                self.possibleFlips.append(i)
                self.flipCountSet.add(flipCount)

        if len(self.possibleFlips) < 1:
            self.minFlips = "NOT POSSIBLE"
            return "NOT POSSIBLE"
        
        minFlips = self.L + 1
        for x in self.flipCountSet:
            if x < minFlips:
                minFlips = x
        self.minFlips = minFlips
        return minFlips
    
    def __str__(self):
        s = ""
        s += "N: %d\n" % self.N
        s += "L: %d\n" % self.L
        s += "Initial: %s\n" % self.initial
        s += "Needed: %s\n" % self.needed
        s += "possibleFlips: %s\n" % self.possibleFlips
        s += "flipCountSet: %s\n" % self.flipCountSet
        s += "minFlips: %s\n" % self.minFlips
        return s
    
    def Output(self,case):
        print "Case #%d: %s" % (case,self.minFlips)

if __name__ == "__main__":
    for i in range(GetTestCases()):
        case = i + 1
        cc = ChargingChaos()
        cc.GetInput()
        cc.TryFlips()
        cc.Output(case)