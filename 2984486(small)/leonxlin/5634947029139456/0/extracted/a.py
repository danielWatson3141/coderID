
file_in = open('a.in', 'r')
file_out = open('a.out', 'w')

n_case = int(file_in.readline())

def hsh(aa):
    ans = 0
    for s in aa:
        ans = ans ^ hash("".join([str(b) for b in s]) + "oops")
    return ans
    

for i_case in range(n_case):
    N, L = (int(n) for n in file_in.readline().split())
    outlets = [[int(c) for c in s] for s in file_in.readline().split()]
    devices = [[int(c) for c in s] for s in file_in.readline().split()]
    o_counts = [sum([s[i] for s in outlets]) for i in range(L)]
    d_counts = [sum([s[i] for s in devices]) for i in range(L)]

    best_possible = sum([1 for i in range(L) if o_counts[i]==d_counts[i]])
    possible = sum([1 for i in range(L) if o_counts[i]==d_counts[i] 
        or o_counts[i]==N - d_counts[i]]) == L
    
    def go(i):
        # print "trying ", i
        # print outlets
        # print devices

        n_flip = 777

        if i == L:
            if hsh(outlets) == hsh(devices):
                return 0
            return 777

        if o_counts[i] == d_counts[i]:
            g = go(i+1)
            if g != 777:
                n_flip = g

        if o_counts[i] == N - d_counts[i]:
            for s in outlets:
                s[i] = 1 - s[i]

            g = go(i+1)
            if g != 777:
                n_flip = min(n_flip, g + 1)

            for s in outlets:
                s[i] = 1 - s[i]

        return n_flip

    ans = "NOT POSSIBLE"
    if possible:
        ans = str(go(0))
    if ans == "777":
        ans = "NOT POSSIBLE"

    file_out.write("Case #%d: %s\n" % (i_case + 1, ans))

file_in.close()
file_out.close()
