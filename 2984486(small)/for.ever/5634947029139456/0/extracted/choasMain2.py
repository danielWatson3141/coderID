import itertools
import copy
txt = [line.strip() for line in open('smallinput.in').readlines()]
output = open('smalloutput.txt','w')
caseCount = int(txt.pop(0))
cases = []
for i in range(caseCount):
    cases.append(txt[3*i:3*i+3])

def switcher(soutlet,nC): 
    successors = []    
    for index in range(nC):
        newsout = []
        for outlet in soutlet.split():
            if outlet[index] == '0':
                new = '1'
            else:
                new = '0'
            outlet = outlet[:index] + new + outlet[index+1:]
            newsout.append(outlet)
            #print newsout
        successors.append(' '.join(newsout))
    return successors

class Queue:
    def __init__(self):
        self.data = []
    def push(self, item):
        self.data.append(item)
    def pop(self):
        return self.data.pop(0)
    def isEmpty(self):
        return len(self.data) == 0

class SearchNode:
    def __init__(self, state, parent):
        self.state = state
        self.parent = parent

    def path(self):
        if self.parent == None:
            return [self.state]
        else:
            return self.parent.path() + [self.state]

def breadthFirstSearch(successors, startState, goalTest):
    if goalTest(startState):
        return [startState]
    startNode = SearchNode(startState, None)
    agenda = Queue()
    agenda.push(startNode)
    visited = {startState}
    while not agenda.isEmpty():
        parent = agenda.pop()
        for childState in successors(parent.state):
            child = SearchNode(childState, parent)
            if goalTest(childState):
                return child.path()
            elif childState not in visited:
                visited.add(childState)
                agenda.push(child)
    return None

for ind in range(caseCount):       
    case = cases[ind]
    casestart = case[0].split()
    numOutlets = int(casestart[0])
    numCurrents = int(casestart[1])
    statusOutlets = case[1]
    devicesReq = case[2]
    devicesReq2 = devicesReq.split()
    #devicesPerm = [''.join(x) for x in itertools.permutations(devicesReq)]
    def specialswitcher(soutlet):
        return switcher(soutlet,numCurrents)
    def goalTest(x):
        newDevices = copy.deepcopy(devicesReq2)
        xDevices = x.split()
        for x in xDevices:
            try:
                ind = newDevices.index(x)
                newDevices.pop(ind)
            except:
                return False
        if len(newDevices) == 0:
            return True
        else:
            return False 
    path = breadthFirstSearch(specialswitcher, statusOutlets, goalTest)
    print "numCurrents", numCurrents+1, path     
    if path == None:#d or len(path)>numCurrents:
        out = "NOT POSSIBLE"
        print out
        output.write('Case #'+ str(ind+1)+': '+str(out)+'\n')
    else:
        out = len(path) -1
        print out
        output.write('Case #'+ str(ind+1)+': '+str(out)+'\n')
    
