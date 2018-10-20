import itertools

i_file = open("input.txt", "r")
o_file = open("output.txt", "w")

def flip(i, outlets):
    result = []
    for outlet in outlets:
        bit = outlet[i]
        if bit == "0":
            result.append(outlet[:i] + "1" + outlet[i+1:])
        else:
            result.append(outlet[:i] + "0" + outlet[i+1:])
    return result

cases = int(i_file.readline().strip())
for case in range(cases):
    n, l = i_file.readline().strip().split()
    n = int(n)
    l = int(l)
    outlets = i_file.readline().strip().split()
    required = i_file.readline().strip().split()
    min_flips = -1

    combinations = list(itertools.product(*["01"] * l))
    for c in combinations:
        outlets_copy = outlets[:]
        flips = c.count("1")
        for i in range(len(c)):
            if c[i] == "1":
                outlets_copy = flip(i, outlets_copy)
        for r in required:
            if r in outlets_copy:
                outlets_copy.remove(r)
        if len(outlets_copy) == 0:
            if min_flips == -1 or flips < min_flips and min_flips != -1:
                min_flips = flips

    if min_flips != -1:
        o_file.write("Case #"+str(case+1)+": "+str(min_flips)+"\n")
    else:
        o_file.write("Case #"+str(case+1)+": NOT POSSIBLE\n")

i_file.close()
o_file.close()