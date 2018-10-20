
number_of_flip = 0
min_flip = -1

def number_of_ones(depth, array_of_string) :
    count = 0
    for s in array_of_string :
        if s[depth] == '1' :
            count += 1
    return count

def flip(depth, array_of_string) :
    for s in array_of_string :
        if s[depth] == '1' :
            s[depth] = '0'
        elif s[depth] == '0' :
            s[depth] = '1'
        else :
            print ('Error')


def try_flip(depth, outlets, devices) :
    global number_of_flip
    global min_flip
    n = len(outlets)
    l = len(outlets[0])

    if depth == l :
        if min_flip == -1 or number_of_flip < min_flip :
            A = sorted(outlets)
            B = sorted(devices)
            if A == B :
                min_flip = number_of_flip
        return
    
    outlets_ones = number_of_ones(depth, outlets)
    devices_ones = number_of_ones(depth, devices)

    if outlets_ones == devices_ones :
        try_flip(depth + 1, outlets, devices )

    if n - outlets_ones == devices_ones :
        flip(depth, outlets)
        number_of_flip += 1
        try_flip(depth + 1, outlets, devices )
        number_of_flip -= 1
        flip(depth, outlets)

    
def solve(f) :
    global number_of_flip
    global min_flip
    number_of_flip = 0
    min_flip = -1
    line = f.readline().split()
    line = [ int(i) for i in line ]
    n = line[0]
    l = line[1]

    outlets = f.readline().split()
    outlets = [ list(outlet) for outlet in outlets ]
    devices = f.readline().split()
    devices = [ list(device) for device in devices ]

    try_flip(0, outlets, devices)


    

    if min_flip == -1 :
        return 'NOT POSSIBLE'
    else :
        return min_flip

if __name__ == '__main__' :
    with open('A-small-attempt0.in') as f:
        t = int(f.readline())
        for i in range(t) :
            print ('Case #{0}: {1}'.format(i + 1, solve(f)))
