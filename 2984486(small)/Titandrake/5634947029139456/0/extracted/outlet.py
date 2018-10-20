t = input()

def flip(s, i):
    return s[:i] + ('0' if s[i] == '1' else '1') + s[i+1:]

def find_outlet(outlets, devices, l):
    # For arbitrary device, try matching to every outlet
    # this will determine all other outlets
    devices.sort()
    d = devices[0]
    best = 10000000
    for i in xrange(len(outlets)):
        indices = []
        for j in xrange(l):
            if d[j] != outlets[i][j]:
                indices.append(j)
        copy = list(outlets)
        for j in xrange(len(outlets)):
            for index in indices:
                copy[j] = flip(copy[j], index)
        copy.sort()
        if copy == devices:
            best = min(best, len(indices))
    return best if best != 10000000 else 'NOT POSSIBLE'
        
for case in range(1, t+1):
    n, l = map(int, raw_input().split())
    outlets = raw_input().split()
    devices = raw_input().split()
    print "Case #%d: %s" % (case, find_outlet(outlets, devices, l))