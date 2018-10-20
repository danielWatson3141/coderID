__author__ = 'MRajendran'
from itertools import *

class ChargingChaos:
    def readProblem(self, f):
        s = f.readline().split()
        self.numPlugs = int(s[0])
        self.socketLength = int(s[1])

        self.plugs = sorted([int(x,2) for x in f.readline().split()])
        self.switches = [int(x,2) for x in f.readline().split()]

    def result(self):
        a = range(self.socketLength)
        for i in range(self.socketLength + 1):
            for combination in combinations(a,i):
                switchCombo = 0
                for s in list(combination):
                    switchCombo = switchCombo | (1 << s)
                if self.works(switchCombo):
                    return i

        return 'NOT POSSIBLE'

    def works(self, switchCombo):
        newSwitch = sorted([switch ^ switchCombo for switch in self.switches])
        return self.plugs == newSwitch

fi = 'small'
f = open(fi +'.in')
o = open(fi + '.out','w')
cases = int(f.readline())
result = []

for i in range(cases):
    m = ChargingChaos()
    m.readProblem(f)
    result.append(m.result())

index = 1
for r in result:
    o.write("Case #{0}: {1}\n".format(index,r))
    index += 1