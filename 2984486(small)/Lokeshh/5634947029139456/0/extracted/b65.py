import collections
compare = lambda x, y: collections.Counter(x) == collections.Counter(y)

class my_str(str):
    def __lt__(a, b):
        n1, n2 = 0, 0
        for i in range(len(a)):
            if a[i] == '1':
                n1 += 1
            if b[i] == '1':
                n2 += 1
        return n1 <= n2

    def num(self):
        return sum([1 for i in self if i == '1'])

def genSwitches(l):
    return sorted(map(my_str,[bin(i)[2:].zfill(l) for i in range(2**l)]))

def switchBit(bit):
    if bit == '0':
        return '1'
    else:
        return '0'

def add(current, switch):
    newCurrent = ''
    for i in range(len(switch)):
        if switch[i] == '1':
            newCurrent += switchBit(current[i])
        else:
            newCurrent += current[i]
    return newCurrent

def switchIt(initFlow, switch):
    newFlow = []
    for current in initFlow:
        newFlow.append(add(current, switch))
    return newFlow

def doit(n, l, initFlow, reqFlow):    
    for switch in genSwitches(l):
        newFlow = switchIt(initFlow, switch)
        if compare(newFlow, reqFlow):
            return switch.num()
    return -1

res = []
testCases = input()
for i in range(testCases):
    n, l = map(int, raw_input().split())
    initFlow = raw_input().split()
    reqFlow = raw_input().split()
    res.append(doit(n, l, initFlow, reqFlow))

for i in range(len(res)):
    if res[i] == -1:
        print 'Case #' + str(i+1) + ': ' + 'NOT POSSIBLE'
    else:
        print 'Case #' + str(i+1) + ': ' + str(res[i])
               
