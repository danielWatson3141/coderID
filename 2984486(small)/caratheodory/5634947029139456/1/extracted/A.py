# Google Code Jam 2014 Round 1A
# Problem A
# Shaotong Wang

def equiv(xs, ys):
    for x in xs:
        if x not in ys:
            return False
    return True

def flip_outlets(i, outlets):
    for j in xrange(0,len(outlets)):
        if outlets[j][i] == "0":
            outlets[j] = outlets[j][:i] + "1" + outlets[j][i+1:]
        else:
            outlets[j] = outlets[j][:i] + "0" + outlets[j][i+1:]

fin = open('A.in', 'r')
fout = open('A.out', 'w')

num_cases = int(fin.readline())

for case in range(1,num_cases+1):
    num_outlets, outlet_len = map(int, fin.readline().split())
    outlets = fin.readline().split()
    devices = fin.readline().split()
    
    min_flips = 5000000

    for outlet in outlets:
        flip = 0
        outlets_flipped = outlets[:]
        for i in xrange(0,len(outlet)):
            if outlet[i] != devices[0][i]:
                flip += 1
                flip_outlets(i, outlets_flipped)
        
        if equiv(outlets_flipped, devices):
            min_flips = min(min_flips,flip)

    fout.write("Case #" + str(case) + ": ")
    if min_flips == 5000000:
        fout.write("NOT POSSIBLE")
    else:
        fout.write(str(min_flips))
    fout.write("\n")
        
fin.close()
fout.close()

