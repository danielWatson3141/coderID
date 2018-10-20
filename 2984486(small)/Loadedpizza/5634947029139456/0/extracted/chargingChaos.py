# Codejam 2014 Round 1A - A: Charging Chaos

def flip(string, pattern): # assume char is 1 or 0
    result = list(string)
    length = len(result)
    for x in range(len(pattern)):
        if pattern[len(pattern) - x - 1] == "1":
            result[length - x - 1] = "0" if result[length - x - 1] == "1" else "1"
    return "".join(result)

f = open("A-small-attempt1.in", "rU")
output = open("A-small.out", "w")

for curr_case in range(1, int(f.readline()) + 1):
    num_outlets, length = map(int, f.readline().strip().split())
    outlets = sorted(f.readline().strip().split())
    devices = sorted(f.readline().strip().split())
    solution = -1

    flip_order = sorted(map(lambda x: bin(x)[2:], range(2 ** length)),
                        key = lambda x: x.count("1"))
    
    for pattern in flip_order:
        new_outlets = sorted([flip(x, pattern) for x in outlets])
        if new_outlets == devices:
            solution = pattern.count("1")
            break

    if solution != -1:
        print("Case #{}: {}".format(curr_case, solution))
        output.write("Case #{}: {}\n".format(curr_case, solution))
    else:
        print("Case #{}: NOT POSSIBLE".format(curr_case))
        output.write("Case #{}: NOT POSSIBLE\n".format(curr_case))

f.close()
output.close()

