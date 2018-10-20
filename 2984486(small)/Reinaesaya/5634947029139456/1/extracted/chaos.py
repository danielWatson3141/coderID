# Sean Liu
# Charging Chaos

def comparestrings(string1, string2):
    string = ""
    for i in range(len(string1)):
        if string1[i] == string2[i]:
            string = string+'1'
        else:
            string = string+'0'
    return string

def countzeroes(string):
    num = 0
    for x in string:
        if x == '0':
            num += 1
    return num

f = open("A-large.in", "r")
g = open("output.txt", "w")

T = int(f.readline())

for i in range(T):
    
    params = f.readline().split()
    N = int(params[0])
    L = int(params[1])

    outlets = f.readline().split()
    devices = f.readline().split()

    num = 100000
    switches = []

    for d in devices:
        switches.append(comparestrings(outlets[0],d))
    for o in outlets:
        switches1 = []
        for d in devices:
            switches1.append(comparestrings(o,d))
        newswitches = []
        for s in switches:
            if s in switches1:
                newswitches.append(s)
        switches = newswitches[:]

    for s in switches:
        y = countzeroes(s)
        if y < num:
            num = y

    if num > L:
        g.write("Case #{}: NOT POSSIBLE\n".format(i+1))
    else:
        g.write("Case #{}: {}\n".format(i+1, num))

f.close()
g.close()
