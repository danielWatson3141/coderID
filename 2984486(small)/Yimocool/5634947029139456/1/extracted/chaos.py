
BIG = 1000000007

# file_name = "A-small-attempt1"
file_name = "A-large"

f = open("../../../../" + file_name + ".in", "r")
# f = open("../test.txt")
w = open("../../../../" + file_name + ".out", "w")
time = int(f.readline())

for T in range(1, time + 1):
    w.write("Case #" + str(T) + ": ")
    N, L = map(int, f.readline().split())
    cur = f.readline().split()
    target = f.readline().split()
    min_moves = BIG
    for pos in target:
        changer = L * [False]
        for i in range(L):
            if cur[0][i] != pos[i]:
                changer[i] = True
        temp_set = set()
        for stuff in cur:
            temp = L * ['0']
            for i in range(L):
                if (changer[i] and stuff[i] == '0') or (not changer[i] and stuff[i] == '1'):
                    temp[i] = '1'
            temp_set.add(''.join(temp))
        equals = True
        for word in target:
            if not word in temp_set:
                equals = False
        if equals:
            min_moves = min(min_moves, sum(1 for p in changer if p))
            
    if min_moves == BIG:
        w.write("NOT POSSIBLE" + "\n")
    else:
        w.write(str(min_moves) + "\n")
    
