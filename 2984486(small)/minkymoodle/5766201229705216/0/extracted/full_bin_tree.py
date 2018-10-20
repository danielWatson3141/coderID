

IN = 'B-small-attempt0.in'
OUT = 'out.txt'

def main():
    in_f = open(IN, 'r')
    out_f = open(OUT, 'w')
    T = int(in_f.readline())
    for case in range(1, T+1):
        N = int(in_f.readline())
        edges = [[] for i in range(N)]
        for i in range(N-1):
            x, y = map(int, in_f.readline().split())
            x -= 1
            y -= 1
            edges[x].append(y)
            edges[y].append(x)
        s = solve(N, edges)
        out_f.write('case #' + str(case) + ': ')
        out_f.write(str(s) + '\n')
    in_f.close()
    out_f.close()

def solve(N, e):

    deletes = []
    for r in range(N):
        if len(e[r]) == 0:
            return 0
        elif len(e[r]) == 1:
            deletes.append(N-1)
            continue
        # number of children is 2 or 3
        subdels = []
        subsizes = []
        for i in range(len(e[r])):
            child = e[r][i]
            subdels.append(trim_subtree(r, child, e))
            subsizes.append(num_nodes(r, child, e))
        if len(subdels) == 2:
            deletes.append(sum(subdels))
        else:
            # 3 children
            opt1 = subdels[0] + subdels[1] + subsizes[2]
            opt2 = subdels[0] + subdels[2] + subsizes[1]
            opt3 = subdels[1] + subdels[2] + subsizes[0]
            deletes.append(min(opt1, opt2, opt3))

    return min(deletes)

def trim_subtree(p, n, e):
    children = get_children(p, n, e)
    if len(children) == 0:
        return 0
    elif len(children) == 2:
        d1 = trim_subtree(n, children[0], e)
        d2 = trim_subtree(n, children[1], e)
        return d1 + d2

    # single child
    return num_nodes(n, children[0], e)

def num_nodes(p, n, e):
    children = get_children(p, n, e)
    if len(children) == 0:
        return 1
    num = 1
    for c in children:
        num += num_nodes(n, c, e)
    return num

def get_children(p, n, e):
    children = [c for c in e[n] if c != p]
    return children


main()








