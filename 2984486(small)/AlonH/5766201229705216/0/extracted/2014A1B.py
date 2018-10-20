def isFull(tree):
    flag = False
    for t in tree:
        if len(t) == 2:
            if flag:
                return False
            flag = True
    return True
f = open("B-small-attempt0.in","r")
o = open("B-small-answers.txt","w")
T = int(f.readline())
for t in range(1,T+1):
    n = int(f.readline())
    tree = []
    for i in range(n):
        tree.append([])
    for i in range(n-1):
        inp = [int(a) for a in f.readline().split()]
        tree[inp[0]-1].append(inp[1]-1)
        tree[inp[1]-1].append(inp[0]-1)
    count = -1
    for node in tree:
        if len(node) == 2:
            count +=1
    o.write("Case #"+str(t)+": "+str(count)+"\n")
o.close()
