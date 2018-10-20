def read_input(file_name):
    with open(file_name, "r") as fid:
        T = int(fid.readline())
        P = []
        for t in range(T):
            N, L = (float(x) for x in fid.readline().split())
            test_case = {
                "ini": fid.readline().split(),
                "req": fid.readline().split()
            }
            P.append(test_case)
    return T, P


def flip_switch(line, n):
    output = []
    for l in line:
        output.append("".join([str(1 - int(l[t])) if t == (n - 1) else l[t] for t in range(len(l))]))
    return output


def compare_lines(ini, req):
    ini.sort()
    req.sort()
    return ini == req


def solve_problem(P):
    Pini = P["ini"][:]
    nb = len(P["ini"][0])
    maxmv = bin((2 ** nb) - 1)[2:]
    moves = 0
    ans = []
    while bin(moves)[2:] != maxmv:
        if compare_lines(P["ini"], P["req"]):
            ans.append(sum(int(x) for x in bin(moves)[2:]))
        moves += 1
        n = nb
        P["ini"] = Pini[:]
        for x in bin(moves)[:1:-1]:
            if x == "1":
                P["ini"] = flip_switch(P["ini"], n)
            n -= 1
    if len(ans) > 0:
        return "%d" % min(ans)
    return "NOT POSSIBLE"


if __name__ == "__main__":
    import os
    path = os.path.realpath(".")
    # file_name = os.path.join(path, "example.in")
    file_name = os.path.join(path, "A-small-attempt1.in")
    # file_name = os.path.join(path, "A-large.in")
    T, P = read_input(file_name)
    with open(file_name[:-2] + "out", "w") as fid:
        for t in range(T):
            solution = solve_problem(P[t])
            fid.write("Case #%d: %s\n" % (t + 1, solution))