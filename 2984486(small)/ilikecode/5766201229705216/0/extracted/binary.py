def bestTree (num, paths):
    best=0
    besti = -2
    for i in range(1,num+1):
        m = measureTree(buildTree(num, i, paths, []))[0]
        if m > best:
            best=m
            besti = i
    return str(num-best)


def buildTree(num, root, paths, forbidden):
    tree = {}
    for path in paths:
        if path[0]==root and path[1] not in forbidden:
            tree[path[1]] = buildTree(num, path[1], paths, list(forbidden)+[root])
        if path[1]==root and path[0] not in forbidden:
            tree[path[0]] = buildTree(num, path[0], paths, list(forbidden)+[root])
    return tree


#hash on parent/child
def measureTree(tree):
    test=[]
    count = 0
    totalChildren=0
    for key, value in tree.items():
        m=measureTree(value)
        test+=[m]
        totalChildren+=m[0]+m[1]
        count+=1
    
    if count==0:
        return (1,0)
    if count==1:
        (keeps, removals)=test[0]
        return (1,totalChildren) 
    if count==2:
        (keeps1, removals1)=test[0]
        (keeps2, removals2)=test[1]
        return (1+keeps1+keeps2, removals1+removals2)

    best=0
    secondBest=0

    for testVal in test:
        if testVal[0] > best:
            secondBest = best
            best = testVal[0]
        elif testVal[0] > secondBest:
            secondBest = testVal[0]
    return (best+secondBest+1, totalChildren-best-secondBest)


input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
currentLine=1
with open("output", "a") as outputfile:
    for num in range(0,int(lines[0])):
        size = int(lines[currentLine])
        paths = [[int(pos) for pos in line.split(" ")] for line in lines[currentLine+1:currentLine+size]]
        currentLine= currentLine+size

        outputfile.write("Case #"+str(num+1)+": "+bestTree(size, paths)+"\n")
        
