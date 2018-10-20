import numpy as np

problem = 'A-large'

fin = open(problem + '.in')
fout = open(problem + '.out', 'w')

def read_ints():
    return [int(x) for x in fin.readline().strip().split()]

def sortrows(a):
    return np.sort(a.view([('',a.dtype)]*a.shape[1]),0).view(a.dtype)

def minflips(outlets, devices, i):
    if (outlets[:,i] == devices[:,i]).all():
        if outlets.shape[1] > i+1:
            flips_off = minflips(outlets, devices, i+1)
        else:
            flips_off = 0
    else:
        flips_off = 999
    
    outlets_alt = outlets.copy()
    outlets_alt[:,i] ^= 1
    outlets_alt = sortrows(outlets_alt)
    if (outlets_alt[:,i] == devices[:,i]).all():
        if outlets.shape[1] > i+1:
            flips_on = 1 + minflips(outlets_alt, devices, i+1)
        else:
            flips_on = 1
    else:
        flips_on = 999
    
    return min(flips_off, flips_on)

T = read_ints()[0]
for caseno in range(1, T+1):
    print("Case number", caseno, "-------")
    N, L = read_ints()
    
    outlets = sortrows(np.array([[int(x) for x in s] for s in fin.readline().strip().split()]))
    devices = sortrows(np.array([[int(x) for x in s] for s in fin.readline().strip().split()]))
    print(outlets)
    print(devices)
#    sum_out = outlets.sum(axis=1)
#    sum_req = devices.sum(axis=1)
    
#    left_count_ok = (sum_out == sum_req)
#    flip_count_ok = ((N-sum_out) == sum_req)
#    ambiguous = left_count_ok & flip_count_ok
#    must_flip = flip_count_ok & ~left_count_ok
    
#    result = 0
#    switches = np.zeros(L, dtype=np.int8)
#    for i in range(L):
##        print(outlets, switches)
#        curr_outlets = sortrows(outlets ^ switches)
#        alt_switches = switches.copy()
#        alt_switches[i] = 1
#        alt_outlets = sortrows(outlets ^ alt_switches)
#        
#        if (devices[:,:i+1] == curr_outlets[:, :i+1]).all():
#            continue
#        elif (devices[:,:i+1] == alt_outlets[:, :i+1]).all():
#            switches = alt_switches
#            result += 1
#        else:
#            print(i, switches)
#            result = "NOT POSSIBLE"
#            break
    
    result = minflips(outlets, devices, 0)
    if result > 100:
        result = "NOT POSSIBLE"
    
    print(result)
    fout.write("Case #%d: %s\n" % (caseno, result))