t = input()

def sxor(s1,s2):
    s3 = ''
    for i in range(len(s1)):
        if s1[i] == s2[i]:
            s3 += '0'
        else:
            s3 += '1'
    return s3

def transform(needs, outlets, key):
    newO = []
    for x in outlets:
        newO.append(sxor(x,key))
    return sorted(needs) == sorted(newO)

def mini(needs, outlets):
    mini = 1<<30
    for y in outlets:
        key = sxor(needs[0], y)
        if transform(needs, outlets, key):
            if key.count('1') < mini:
                mini = key.count('1')
    return mini

for i in range(t):
    n, l = map(int, raw_input().strip().split(' '))
    outlets = raw_input().strip().split(' ')
    needs = raw_input().strip().split(' ')
    mi = mini(needs, outlets)
    if mi == 1<<30:
        print 'Case #%d: NOT POSSIBLE' % (i + 1)
    else:
        print 'Case #%d: %d'  % (i + 1, mi)





