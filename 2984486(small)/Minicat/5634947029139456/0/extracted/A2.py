import itertools

f_in = open("A-small-attempt1.in", 'r')
f_out = open("A-small-attempt1.out", 'w')

def get_int():
    return int(f_in.readline().rstrip())

def get_ints():
    line = f_in.readline().rstrip().split()
    new = []
    for thing in line:
        new.append(int(thing))
    return new

T = get_int()

def get_counts(stuff, N, L):
    things = []
    # Return array of [# zeroes, # ones] for each position
    for i in range(0, L):
        temp = [0, 0]
        for j in range(0, N):
            if stuff[j][i] == '0':
                temp[0] += 1
            else:
                temp[1] += 1
        things.append(temp)
    return things

def recursive_perms(pre, post, stuff):
    if len(post) == 0:
        stuff.append(pre)
    else:
        if post[0] == 2:
            a = pre[:]
            a.append(0)
            b = pre[:]
            b.append(1)
            recursive_perms(a, post[1:], stuff)
            recursive_perms(b, post[1:], stuff)
        else:
            c = pre[:]
            c.append(post[0])
            recursive_perms(c, post[1:], stuff)            
        
def other(a):
    if a == "0":
        return "1"
    elif a == "1":
        return "0"
    return "X"

def apply_perm(initial, perm):
    temp = []
    for thing in initial:
        tempthing = ""
        for i in range(0, len(thing)):
            if perm[i] == 1:
                tempthing = tempthing + other(thing[i])
            else:
                tempthing = tempthing + thing[i]
        temp.append(tempthing)
    return temp

for case in range(1, T + 1):
    line = f_in.readline().rstrip().split()
    N = int(line[0])
    L = int(line[1])
    initial = f_in.readline().rstrip().split()
    wanted = f_in.readline().rstrip().split()

    initialc = get_counts(initial, N, L)
    wantedc = get_counts(wanted, N, L)

    switches = 0
    switchlist = []
    for i in range(0, L):
        a = initialc[i]
        b = wantedc[i]
        if a[0] == a[1]:
            # Might need to switch, might not
            switchlist.append(2)
        # OK if same
        elif a[0] == b[0] and a[1] == b[1]:
            switchlist.append(0)
        # OK if need a switch
        elif a[1] == b[0] and a[0] == b[1]:
            switchlist.append(1)
        else:
            # Impossible
            switches = "NOT POSSIBLE"
            break
    #print switchlist

    if switches != "NOT POSSIBLE":
        # Brute force from here?
        permutations = []
        recursive_perms([], switchlist, permutations)

        wantedset = set(wanted)

        minswitches = -1
        
        for perm in permutations:
            # Need to try and match up. First, apply permutation
            applied = apply_perm(initial, perm)
            # Now see if this matches wanted
            if wantedset == set(applied):
                # How many switches?
                cat = 0
                for thing in perm:
                    cat += int(thing)
                if minswitches == -1 or cat < minswitches:
                    minswitches = cat
        if minswitches != -1:
            switches = minswitches
        else:
            switches = "NOT POSSIBLE"
    
    f_out.write("Case #{0}: {1}\n".format(case, switches))

f_in.close()
f_out.close()
