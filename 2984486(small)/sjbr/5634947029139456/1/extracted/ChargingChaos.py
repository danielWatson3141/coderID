__author__ = 'Samuel'


def solve():
    f = open("../A-large.in", "r")
    T = int(f.readline())
    out = open("../output.txt", "w")

    for case in range(T):
        N, L = map(int, f.readline().split())
        outlets = [int(x, 2) for x in f.readline().split()]
        devices = [int(x, 2) for x in f.readline().split()]

        matrix = [[outlets[i] ^ devices[j] for j in range(N)] for i in range(N)]
        #print(matrix)

        val = 0
        rowsUsed = set()
        rows = []
        minBitsFlipped = 1000

        for count in range(N):
            for col in range(N):
                for row in range(N):
                    if col == 0:
                        val = matrix[count][col]
                        rowsUsed = set()
                        rows = []
                        rowsUsed.add(count)
                        rows.append(count)
                        break

                    if row not in rowsUsed and matrix[row][col] == val:
                        rowsUsed.add(row)
                        rows.append(row)
                        break
                if len(rows) != col + 1:
                    break

            if len(rows) == N:
                minBitsFlipped = min(minBitsFlipped, countBits(val))

        if minBitsFlipped < 1000:
            print("Case #%d: %d" % (case + 1, minBitsFlipped))
            out.write("Case #%d: %d\n" % (case + 1, minBitsFlipped))
        else:
            print("Case #%d: %s" % (case + 1, "NOT POSSIBLE"))
            out.write("Case #%d: %s\n" % (case + 1, "NOT POSSIBLE"))


def countBits(num):
    c = 0
    while num != 0:
        num &= num - 1
        c += 1
    return c


solve()