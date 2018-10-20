fin = file("in.txt","r")
fout = file("out.txt","w")

k = int(fin.readline())

def compare(a,b):
    a = map(int,a)
    b = map(int,b)
    out = ''
    for i in range(len(a)):
        out += str(abs(a[i]-b[i]))

    return out


for i in range(k):
    n,l = map(int,fin.readline().split())
    switches = fin.readline().strip().split()
    devices = fin.readline().strip().split()
    comp = [['' for j in range(n)] for l in range(n)]
    output = -1
    for d in range(n):
        for s in range(n):
            comp[d][s] = compare(switches[s],devices[d])

    for s in range(n):
        seen = []
        pattern = comp[0][s]
        finished = False
        for j in range(n):
            if pattern in comp[j]:
                t = comp[j].index(pattern)
                if t in seen:
                    break
                seen.append(t)
                if j == n-1:
                    finished = True
            else:
                break
        if finished:
            if(output >= 0):
                print i+1, seen, pattern, sum(map(int,pattern))
                output = min(output,sum(map(int,pattern)))
            else:
                print i+1, seen, pattern, sum(map(int,pattern))
                output = sum(map(int,pattern))
            
    if (output >=0):
        fout.write('Case #%d: %d\n'%(i+1,output))
    else:
        fout.write('Case #%d: NOT POSSIBLE\n'%(i+1))
    
fin.close()
fout.close()
