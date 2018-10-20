def solve(start, goal):
    def flip(string, i):
        cstring=''
        for k in range(len(string)):
            if k==i:
                if string[k]=='0':
                    cstring+='1'
                else:
                    cstring+='0'
            else:
                cstring+=string[k]
        return cstring
    
    def allSubSets(n):
        if n==0:
            return ['']
        prev = allSubSets(n-1)
        current = []
        for el in prev:
            current.append('0'+el)
            current.append('1'+el)
        return current
    g=set(goal)
    tries = allSubSets(len(start[0]))
    for t in tries:
        startc = start.copy()
        for i in range(len(t)):
            if t[i]=='1':
                for k in range(len(startc)):
                    startc[k]=flip(startc[k], i)
        s = set(startc)
        if len(s.intersection(g))==len(g):
            return t.count('1')
    return "NOT POSSIBLE"


    

fin = open('A-small-attempt0.in')
fout = open('output.out', 'w')

lineNb=0
for line in fin:
    if lineNb==0 or lineNb%3==1:
        lineNb+=1
        continue
    if lineNb%3==2:
        start = line.strip().split(" ")
    if lineNb%3==0:
        goal = line.strip().split(" ")

        fout.write("Case #"+str(lineNb//3)+": "+str(solve(start, goal))+"\n")
    lineNb+=1
    
fout.close()
