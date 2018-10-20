'''
Created on Apr 26, 2014

@author: szalivako
'''

def compare(s1, s2):
    ans = []
    for i in range(len(s1)):
        if (s1[i] != s2[i]):
            ans.append(i)
    return ans

T = int(raw_input())
for ti in range(T):
    n, l = map(int, raw_input().split())
    
    a = raw_input().split()
    b = raw_input().split()
    
    r = [[] for i in range(n)]
    
    for i in range(n):
        for j in range(n):
            r[i].append(compare(a[i], b[j]))
    
    min = 10 ** 10        
    
    for i in range(n):
        cmp = r[0][i]
        cnt = 0
        for j in range(1, n):
            for t in range(n):
                if (cmp == r[j][t]):
                    cnt += 1
        
        if (cnt == n - 1):
            if (len(cmp) < min):
                min = len(cmp)
    
    #for ri in r:
    #    print ri
    
    if (min == 10 ** 10):
        min = 'NOT POSSIBLE'
    else:
        min = str(min)
    
    print 'Case #' + str(ti + 1) + ': ' + min
        