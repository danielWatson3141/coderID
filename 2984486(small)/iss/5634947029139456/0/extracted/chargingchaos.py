import itertools

inp = open('A-small.in', 'r')
out = open('A-small.out', 'w')

def single():
    return inp.readline().strip()

def mult():
    return inp.readline().strip().split()

def flip(begin1, switches):
    begin = begin1[:]
    
    for switch in switches:
        for a in range(len(begin)):
            if begin[a][switch] == '0':
                begin[a] = begin[a][:switch] + '1' + begin[a][switch+1:]
            else:
                begin[a] = begin[a][:switch] + '0' + begin[a][switch+1:]
        
    begin.sort()
    return begin

def test(begin, devices, l):
    shortest = -1

    x = list(range(l))
    for a in range(1, l+1):
        y = list(itertools.combinations(x, a))
        for p in y:
            p = list(p)
            if flip(begin, p) == devices:
                return len(p)
    
    return shortest    

cases = int(inp.readline().strip())

for r in range(cases):
    a = mult()
    n = int(a[0])
    l = int(a[1])
    
    begin = mult()
    devices = mult()

    begin.sort()
    devices.sort()

    if (begin != devices):
        b = test(begin, devices, l)
    else:
        b = 0
    
    if (b == -1):
        print("Case #" + str(r+1) + ": " + "NOT POSSIBLE")
        out.write("Case #" + str(r+1) + ": " + "NOT POSSIBLE" + "\n")    
    else:
        print("Case #" + str(r+1) + ": " + str(b))
        out.write("Case #" + str(r+1) + ": " + str(b) + "\n") 


inp.flush()
out.flush()
inp.close()
out.close()
