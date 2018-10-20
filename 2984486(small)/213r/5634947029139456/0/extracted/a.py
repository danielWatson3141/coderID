import sys 
def check(iw, jw):
    s = "" 
    for i in xrange(len(iw)):
        s += str(int(iw[i]) ^ int (jw[i]))    
    return s         

def do(flow, dev):
    c = 0
    for iw in flow:
        ary = [] 
        for jw in dev:
           ary.append(check(iw, jw)) 
        if c > 0: save = save & set(ary)
        else: save = set(ary) 
        if len(save) == 0: return "NOT POSSIBLE" 
        c += 1
    num = 1e10
    for iw in save: num = min(num, list(iw).count("1"))  
    return num    

t = int(raw_input())
for i in xrange(t):
    n, l = map(int ,raw_input().split())
    flow = map(str ,raw_input().split())
    dev = map(str ,raw_input().split())
    print "Case #{}: {}".format(i+1,do(flow, dev)) 
