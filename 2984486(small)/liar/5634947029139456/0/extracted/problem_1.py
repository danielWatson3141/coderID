def solve(problem):
    L, N, l1, l2 = problem
    # print(l1)
    # print(l2)
    l1 = sorted(int(s, 2) for s in l1)
    l2 = sorted(int(s, 2) for s in l2)

    bits = [1 << i for i in range(L)]
    X = sum(bits)
    solutions = [0]
    for b in bits:
        n1 = sum((x & b) == 0 for x in l1)
        n2 = sum((x & b) == 0 for x in l2)

        if n1 == n2:
            if n1 + n2 == N:
                solutions.extend([s ^ b for s in solutions])
        elif n1 + n2 == N:
            solutions = [s ^ b for s in solutions]

    def check(s):
        return sorted(x ^ s for x in l1) == l2

    solutions = [s for s in solutions if check(s)]
    if not solutions:
        return 'NOT POSSIBLE'

    return min(sum((s & b) != 0 for b in bits) for s in solutions)


def parse_problems():
    import fileinput
    fin = fileinput.input()

    def parse_number(type):
        line = next(fin)
        return type(line)

    def parse_list(type):
        line = next(fin)
        nums = line.split()
        return list(map(type, nums))

    T = parse_number(int)
    for _ in range(T):
        N, L = tuple(parse_list(int))
        l1 = parse_list(str)
        l2 = parse_list(str)
        yield L, N, l1, l2

def main():
    for i, p in enumerate(parse_problems()):
        ans = solve(p)
        print("Case #{}: {}".format(i + 1, ans))

if __name__ == '__main__':
    main()