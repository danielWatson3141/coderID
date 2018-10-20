from collections import deque
from itertools import permutations
def check(initial,final,N):
    for i in xrange(N):
        if final[i] in initial:
            index = initial.index(final[i])
            temp = initial[i]
            initial[i] = initial[index]
            initial[index] = temp
    count = 0  
    for i in xrange(N):
        if initial[i] == final[i]:
            count += 1
    if count == N:
        return True
    else:
        return False

filein = open("PA.txt", "r")
out = open("PAout.txt", "w")
cases = int(filein.readline())
for QQ in xrange(cases):
    line1 = filein.readline()
    N = int(line1.split()[0])
    L = int(line1.split()[1])
    initial2 = filein.readline().split()
    final = filein.readline().split()
    ans = -1
    
    for s in xrange(0,L+1):
        if ans < 0:
            perms = set(permutations(str(1)*s + str(0)*(L-s)))
            perms = list(perms)
            for perm in perms:
                initial = initial2[:]
                for j in xrange(len(perm)):
                    if perm[j] == '1':
                        for i in xrange(N):
                            initial[i] = initial[i][0:j] + str((int(initial[i][j]) + 1)%2) + initial[i][j+1:]
                if (check(initial,final,N)):
                    ans = s
                    break


        
    if ans >= 0:
        out.write("Case #" + str(QQ+1) + ": " + str(ans) + "\n")
    else:
        out.write("Case #" + str(QQ+1) + ": " + "NOT POSSIBLE\n")
            
filein.close()
out.close()
    
