def read_line(l):
    return l.split()
    
def solve(outlets, devices, i=0):
    if i == len(outlets[0]):
        return len(outlets[0]) + 10
    if sorted(outlets) == sorted(devices):
        return 0
    else:
        outlets2 = switch(outlets, i)
        if sorted(outlets2) == sorted(devices):
            return 1
        return min(solve(outlets, devices, i+1), 1 + solve(outlets2, devices, i+1))
    
def switch(outlets, i):
    return [outlet[:i] + ('0' if outlet[i] == '1' else '1') + outlet[i+1:] for outlet in outlets]
    
def ssolve(outlets, devices):
    s = solve(outlets, devices, i=0)
    if s > len(outlets[0]):
        return "NOT POSSIBLE"
    else:
        return '%d' % s
 
        
def readint(f):
    return int(f.readline()[:-1])
        
f = open('/Users/jolleon/Downloads/A-small-attempt0.in')
ntests = readint(f)
for i in xrange(ntests):
    f.readline()
    outlets = f.readline()[:-1].split()
    devices = f.readline()[:-1].split()
    print outlets
    print 'Case #%d: %s' % (i+1, ssolve(outlets, devices))
    