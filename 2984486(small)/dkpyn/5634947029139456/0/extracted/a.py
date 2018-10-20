import sys

def rev(outlets, i):
    return [ ''.join(o[:i]) + str(1-int(o[i])) + ''.join(o[i+1:]) for o in outlets]

def is_all_match(outlets_origin, devices_origin):
    outlets = outlets_origin[:]
    devices = devices_origin[:]
    for d in devices_origin:
        if d in outlets:
            outlets.remove(d)
            devices.remove(d)
    return len(devices) == 0


MAX_C = 999999999
m = MAX_C

def ans(N, L, outlets, devices):
    global m
    m = MAX_C
    def _ans(outlets, devices, i, c):
        global m
        if is_all_match(outlets, devices):
            m = c
            return c
        if i==L or c>=m: 
            return
        _ans(outlets[:], devices, i+1, c)
        _ans(rev(outlets, i), devices, i+1, c+1)

    _ans(outlets[:], devices, 0, 0)
    return m if m < MAX_C else "NOT POSSIBLE"
    

with open(sys.argv[1]) as fr, open(sys.argv[1] + '.out', 'w') as fw:
    T = int(fr.readline())
    for i in xrange(T):
        no = i + 1
        (N, L) = map(int, fr.readline().replace('\n','').split(' '))
        outlets = fr.readline().replace('\n','').split(' ')
        devices = fr.readline().replace('\n','').split(' ')
        fw.write("Case #{no}: {ans}\n".format(no=no,ans=ans(N, L, outlets, devices)))

