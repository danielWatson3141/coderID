import itertools

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
    def __init__(self,state,parent):
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
    visited = {startState} #initialize our visited set
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

def switchLargeState(case0, index):
    temp = []
    for smallState in case0:
        temp.append(switchState(smallState, index))
    return ' '.join(temp)

def switchState(state, index):
    temp = list(state)
    if temp[index] == '1':
        temp[index] = '0'
    elif temp[index] == '0':
        temp[index] = '1'
    newstate = "".join(temp)
    return newstate

def successors(state):
    #print "state to find succ for", state
    state = state.split()
    succ = []
    for index in range(len(state[0])):
        succ.append((switchLargeState(state, index)))
    #print "successors", succ
    return succ

txt = [line.strip() for line in open('input.txt').readlines()]
numCases = int(txt[0])
txt.pop(0)
cases = {} #{casenum: [[outlets], [device reqs]]}
for casenum in range(numCases):
    cases[casenum]= [txt[1],txt[2]]
    txt = txt[3:]
with open('output.txt','w') as output:
    for case in range(numCases):
        devices = cases[case][1]
        listdevices = devices.split()
        def goalTest(state):
            for outlet in state.split():
                if outlet not in listdevices:
                    return False
            return True
        try:
            output.write("Case #" + str(case+1) + ": " + str(len(breadthFirstSearch(successors, cases[case][0], goalTest))-1) + "\n")
        except:
            output.write("Case #" + str(case+1) + ": " + "NOT POSSIBLE" + "\n")
