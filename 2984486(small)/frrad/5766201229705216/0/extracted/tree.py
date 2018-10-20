#!/usr/bin/env python
import sys

#############
##Functions##
#############

def tree(adj, ans, siz, a,b):
    if (a,b) in ans: 
        return ans[(a,b)]

    if len(adj[b]) == 1 :
        ans[(a,b)] = 0
        return 0

    kill = size(adj, siz, a,b) -1

    if len(adj[b]) ==2 : return kill

    can = 9999999999999999999999    

    for left in adj[b]:
        for right in adj[b]:
            if left >= right: continue
            if left == a or right == a: continue

            here = tree(adj, ans, siz, b, left) + tree(adj, ans,siz, b, right) + kill - size(adj, siz , b, left ) - size(adj, siz, b, right)
            can = min(can, here)


    ans[(a,b)] = can
    return can


def size(adj, siz, a,b):
    if (a,b) in siz:
        return siz[(a,b)]

    ans = 0

    for asdf in adj[b]:
        if asdf != a:
            ans += size(adj, siz, b, asdf)

    ans +=1 

    siz[(a,b)] = ans 
    return ans

##############
##File Input##
##############
path = 'input.in'
if len(sys.argv)>1: path = sys.argv[1]

try:
    f = open(path, 'r')
except:
    quit("Error opening file: %s" % path)

data = f.read().splitlines()
f.close()

#Trim extra data from end of file
while data[-1] == '':
    data = data[:-1]
while data[0] == '':
    data = data[1:]

trials = int(data[0])

########
##Main##
########
data = data[1:]
trial = 0
#while trial == 0:
while len(data) > 0:
    spec = map(int, data[0].split(" "))
    specl = spec[0]-1
    x = data[1:specl + 1]
    data = data[specl + 1:]
    trial += 1


    nodes = spec[0]



    print "Case #%d: " %trial,



    adj = list()
    for i in range(nodes +1):
        adj.append( set())



    for con in x:
        [a,b] = map(int, con.split())

        adj[a].add(b)
        adj[b].add(a)

#    print adj

    treel = dict()

    siz = dict()

    
    comp = 9999999999999

    for root in range(1, nodes +1):
        pasta = 0
        for z in adj[root]:
            pasta += size(adj, siz, root, z)

        for b in adj[root]:
            for c in adj[root]:
                if b==c : continue
                here = pasta - size(adj,siz,root,b) - size(adj,siz,root,c) + tree(adj,treel,siz,root,b) + tree(adj,treel,siz, root,c)
                comp = min(comp, here)
                
                


    print min(comp, nodes -1)
