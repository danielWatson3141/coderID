import sys

def main():
    infile, outfile = sys.argv[1:3]
    with open(infile, 'r') as inp:
      with open(outfile, 'w') as out:
        T = int(inp.readline())
        for case in range(1, T+1):
            (N, L) = (int(i) for i in inp.readline().split())
            outlets = [int(i, 2) for i in inp.readline().split()]
            devices = [int(i, 2) for i in inp.readline().split()]
            out.write('Case #{}: {}\n'.format(case, find_solution(N, L, outlets, devices)))


def find_solution(N, L, Out, Dev):
    b = [[0 for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(N):
            b[i][j] = Out[i]^Dev[j]
    min_bits = L+1
    for j in range(N):
        mask = b[0][j]
        exist = True
        for i in range(1, N):
            if mask not in b[i]:
                exist = False
                break
        if not exist:
            continue
        bits = calcBits(mask)
        if bits < min_bits:
            min_bits = bits
    return min_bits if min_bits <= L else 'NOT POSSIBLE'

def calcBits(n):
    count = 0
    while (n):
        count += n & 1
        n >>= 1
    return count

if __name__ == '__main__':
    main()
