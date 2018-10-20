def solve(graph, n):    
    def allSubSets(k):
        if k==0:
            return ['']
        prev = allSubSets(k-1)
        current = []
        for el in prev:
            current.append('0'+el)
            current.append('1'+el)
        return current
    def deleteNode(graph, node):
        graph.pop(node)
        for el in graph:
            if node in graph[el]:
                graph[el].remove(node)
                
    def isFullBT(graph):
        roots = 0
        for el in graph:
            k = len(graph[el])
            if k==2:
                roots+=1
            if k>=4 or roots>=2:
                return False
        return True
    tries = allSubSets(n)
    for t in tries:
        graphc = graph.copy()
        for i in range(len(t)):
            if t[i]=='1':
                deleteNode(graphc, str(i+1))
        if isFullBT(graphc):
            return t.count('1')


grap = {'4':[5, 2, 6],
        '1':[2, 3],
        '3':[1, 7],
        '5':[4],
        '2':[4, 1],
        '6':[4],
        '7':[3]
        }
    

fin = open('B-small-attempt0.in')
fout = open('output.out', 'w')

lineNb=0
T = 0
for line in fin:
    if lineNb==0:
        lineNb+=1
        continue
    if lineNb==1:
        n = int(line.strip())
        graph = {}
        for i in range(1, n+1):
            graph[str(i)]=[]
    if lineNb>=2 and lineNb<n:
        a = line.strip().split(" ")
        graph[a[0]].append(int(a[1]))
        graph[a[1]].append(int(a[0]))
    if lineNb==n:
        T+=1
        a = line.strip().split(" ")
        graph[a[0]].append(int(a[1]))
        graph[a[1]].append(int(a[0]))
        lineNb=0
        #print("graph is ", graph)
        fout.write("Case #"+str(T)+": "+str(solve(graph, n))+"\n")
    lineNb+=1
    
fout.close()
