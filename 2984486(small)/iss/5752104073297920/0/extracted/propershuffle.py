inp = open('C-small.in', 'r')
out = open('C-small.out', 'w')

def single():
    return inp.readline().strip()

def mult():
    return inp.readline().strip().split()

cases = int(inp.readline().strip())
total = 0.0

for r in range(cases):

    a = single()
    b = mult()

    chance = 0.0

    for x in range(len(b)):
        b[x] = float(b[x])

        if (b[x]-x > 666):
            chance += abs((b[x]-x)/333)

        elif (b[x]-x >= 0):
            chance -= abs(4/(b[x]-x+1))

        else:
            chance += abs(2/(b[x]-x))
        

    if (chance >= 100):
        print("Case #" + str(r+1) + ": " + "GOOD")
        out.write("Case #" + str(r+1) + ": " + "GOOD" + "\n")
    else:
        print("Case #" + str(r+1) + ": " + "BAD")
        out.write("Case #" + str(r+1) + ": " + "BAD" + "\n")

    total += chance

inp.flush()
out.flush()
inp.close()
out.close()
