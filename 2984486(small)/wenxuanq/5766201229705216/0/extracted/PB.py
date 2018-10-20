
filein = open("PB.txt", "r")
out = open("PBout.txt", "w")
cases = int(filein.readline())
for QQ in xrange(cases):
    nodes = int(filein.readline().split()[0])
    M = [0]*(nodes+1)
    for i in xrange(nodes + 1):
        M[i] = []
    for i in xrange(nodes-1):
        line = filein.readline().split()
        M[int(line[0])].append(int(line[1]))
        M[int(line[1])].append(int(line[0]))
    count = 0
    for i in xrange(1,nodes+1):
        if len(M[i]) == 2:
            count += 1
                                 
    out.write("Case #" + str(QQ+1) + ": " + str(count - 1) + "\n")
            
filein.close()
out.close()
    
