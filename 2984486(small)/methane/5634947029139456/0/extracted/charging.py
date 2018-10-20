import sys


def check1(device, outlet, suffix, i, N, L):
    if i == L:
        return 0
    sel = 1 << i
    mask = (1 << (i+1)) - 1

    d_suffix = [mask & dx for dx in device]
    d_suffix.sort()

    n = n2 = None
    a_suffix = [suffix[i] | (sel & outlet[i]) for i in range(N)]
    if sorted(a_suffix) == d_suffix:
        n = check1(device, outlet, a_suffix, i+1, N, L)
        if n == 0:
            return 0

    a_suffix = [suffix[i] | (sel & ~outlet[i]) for i in range(N)]
    if sorted(a_suffix) == d_suffix:
        n2 = check1(device, outlet, a_suffix, i+1, N, L)
        if n2 is not None:
            n2 += 1

    if n is not None and n2 is not None:
        return min(n, n2)
    return n or n2


def solve(outlet, device, N, L):
    device.sort()
    return check1(device, outlet, [0]*N, 0, N, L)


def main():
    T = int(sys.stdin.readline())

    for t in range(1, T+1):
        N, L = map(int, sys.stdin.readline().split())
        outlet = [int(x, 2) for x in sys.stdin.readline().split()]
        device = [int(x, 2) for x in sys.stdin.readline().split()]
        y = solve(outlet, device, N, L)
        if y is None:
            y = 'NOT POSSIBLE'
        print("Case #{}: {}".format(t, y))

#test()
main()
