'''
Created on 2014-04-24

@author: Tiger
'''
#bad, right is bigger
cntB =0
def getAverage(l):
    left =0
    for i in range(0,len(l)/2):
        left+=l[i]
    
    right =0
    for i in range(len(l)/2,len(l)):
        right+=l[i]
    
    return left,right

def getAns(case, permute):
    global cntB
    permute = map(int,permute)
    left,right = getAverage(permute)
    #print right,left
    t= float(right)/float(left)
    if right-left >7000:
        print "Case #"+str(case)+": BAD"
        cntB+=1
    else:
        print "Case #"+str(case)+": GOOD"

f = open ("C-small-attempt5.in","r")
case =1
tests = f.readline().strip()
for i in range(int(tests)):
    n = f.readline()
    permute = f.readline().strip().split()
    
    getAns(case, permute)
    
    
    case+=1
print cntB