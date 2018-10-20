import sys
from copy import deepcopy

infty = 1000 

def switched(s):
    return ''.join(['0' if c == '1' else '1' for c in s ])


def count(s):
    return sum([1 if c == '1' else 0 for c in s])


def advance(out, dev, off, perm):
    if off >= len(out):
        return 0
    
    opt = infty
    
    perm_s  = deepcopy(perm)

    for k, b in enumerate(out[off]):
        # unswitch
        perm[k] = [ x for x in perm[k] if dev[off][x] == b]
        # switch
        perm_s[k] = [ x for x in perm_s[k] if dev[off][x] != b]


    c1 = count(out[off])
    c2 = count(dev[off])
    
    if all([p for p in perm]) and (c1 == c2):
        opt = advance(out, dev, off+1, perm)
    if all([p for p in perm_s]) and (c1 == len(out[off]) - c2):
        opt = min(opt, 1 + advance(out, dev, off+1, perm_s))
        
    return opt

def resolve(outlets, devices):
    out = map(lambda x : ''.join(x), zip(*outlets))
    dev = map(lambda x : ''.join(x), zip(*devices))
    
    perm = [ range(len(outlets)) for _ in range(len(outlets)) ]
    opt = advance(out, dev, 0, perm)
    if opt >= infty:
        return 'NOT POSSIBLE'
    return opt
    
                  
input_file = sys.stdin
#output_file = sys.stdout
output_file = open('output', 'w')

T = int(input_file.readline())

for i in range(1, T + 1):
    print i
    N, L =  map(int, input_file.readline().split())
    outlets = map(list, input_file.readline().split())
    devices = map(list, input_file.readline().split())
    
    sol = 'Case #%d: %s\n' % (i, resolve(outlets, devices)) 
    
    output_file.write(sol)


    

