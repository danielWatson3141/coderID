import itertools

def solve(flows, goals):
    minswitches = 1000
    flows.sort()
    goals.sort()
    for i in range(len(flows)):
        a = [flows[i]] + flows[0:i] + flows[i+1:]
        switches = 0
        for j in range(len(a[0])):
            if a[0][j] != goals[0][j]:
                switches += 1
                for k in range(len(a)):
                    if a[k][j] == '0':
                        a[k] = a[k][:j] + '1' + a[k][j+1:]
                    else:
                        a[k] = a[k][:j] + '0' + a[k][j+1:]
        a.sort()
        if a == goals:
            if switches < minswitches:
                minswitches = switches
    return minswitches
    
f = open('A-large.in', 'r')
line = f.readline()
line = f.readline()
f2 = open('output.out', 'w')

line = 1
case = 1
while line:
    start = f.readline().replace('\n', '').split(' ')
    goal = f.readline().replace('\n', '').split(' ')
    s = solve(start, goal)
    a = ''
    if s == 1000:
        a = "Case #" + str(case) + ": NOT POSSIBLE\n"
    else:
        a = "Case #" + str(case) + ": " + str(s) + "\n"
    f2.write(a)
    print a,
    case += 1
    line = f.readline()



f.close()
f2.close()
