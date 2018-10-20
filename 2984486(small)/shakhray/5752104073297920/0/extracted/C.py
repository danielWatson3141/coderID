fin = open("input.txt", 'r')
fout = open("output.txt", 'w')

T = int(fin.readline())
ress = []
for i in range(T):
    N = int(fin.readline())
    perm = list(map(int, fin.readline().split()))
    sum1 = sum(perm[0:500])
    sum2 = sum(perm[500:])
    less = 0
    more = 0
    less_ = 0
    more_ = 0
    pairs = 0
    for p in range(500, 1000):
        j = perm.index(p)
        if j < 500:
            less += 1
        else:
            more += 1
    for p in range(500):
        j = perm.index(p)
        if j < 500:
            less_ += 1
        else:
            more_ += 1
    if abs(sum1 - sum2) < 9000:
        fout.write("Case #" + str(i + 1) + ": GOOD\n")
        ress.append("GOOD")
    else:
        fout.write("Case #" + str(i + 1) + ": BAD\n")
        ress.append("BAD")
o = 0
for elem in ress:
    if elem == 'GOOD':
        o += 1
print(o)