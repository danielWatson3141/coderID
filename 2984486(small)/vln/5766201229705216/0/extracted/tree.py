import sys

N = 0

def main():
    global N
    infile, outfile = sys.argv[1:3]
    with open(infile, 'r') as inp:
      with open(outfile, 'w') as out:
        T = int(inp.readline())
        for case in range(1, T+1):
            N = int(inp.readline())
            tree = [[] for i in range(N)]
            for i in range(N-1):
                (X, Y) = (int(k) for k in inp.readline().split())
                tree[X-1].append(Y-1)
                tree[Y-1].append(X-1)
            out.write('Case #{}: {}\n'.format(case, find_solution(tree)))


def find_solution(tree):
    global N
    if isBinaryTree(tree):
        return 0
    count = N+1
    for i in range(N):
        if len(tree[i]) == 1:
            tree2 = [tree[k][:] for k in range(len(tree))]
            item = tree2[i][0]
            tree2[item].remove(i)
            tree2[i].remove(item)
            if isBinaryTree(tree2):
                new_count = 1
                if new_count < count:
                    count = new_count
            elif len(tree2[item]) != 1:
                continue
            else:
                new_count = recurse(tree2, item)+1
                if new_count < count:
                    count = new_count
    return count

def recurse(tree, item):
    global N
    count = N+1
    tree2 = [tree[k][:] for k in range(len(tree))]
    item2 = tree2[item][0]
    tree2[item2].remove(item)
    tree2[item].remove(item2)
    if isBinaryTree(tree2):
        new_count = 1
        if new_count < count:
            count = new_count
    elif len(tree2[item2]) != 1:
        return (N+1)
    else:
        new_count = recurse(tree2, item2)+1
        if new_count < count:
            count = new_count
    return count

def isBinaryTree(tree):
    global N
    n2 = 0
    for i in range(N):
        if len(tree[i]) > 3:
            return False
        if not tree[i]:
            continue
        if len(tree[i]) == 2:
            n2 += 1
            if n2 > 1:
                return False
    return (n2 == 1)

if __name__ == '__main__':
    main()
