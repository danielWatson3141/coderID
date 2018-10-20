from TreeNode import TreeNode


def get_size(nodes, index):
    for node in nodes:
        if node.index == index:
            cur = node
            break

    if len(cur.kids) == 0:
        return 1
    su = 1
    for kid in cur.kids:
        su += get_size(nodes, kid)
    return su


def main_recursion(nodes, cur_index):
    to_return = 0
    for node in nodes:
        if node.index == cur_index:
            cur = node
            break

    #no kids
    if len(cur.kids) == 0:
        return 0
    #it has kids..
    removes = []
    for kid in cur.kids:
        removes.append([kid, main_recursion(nodes, kid)])
    if len(cur.kids) == 2:
        return removes[0][1]+removes[1][1]
    elif len(cur.kids) == 1:
        return get_size(nodes, cur.kids[0])
    elif len(cur.kids) > 2:
        sizes = [[kid, get_size(nodes, kid)] for kid in cur.kids]
        sizes.sort(key = lambda x: x[1])
        for index in range(len(cur.kids)-2):
            to_return += get_size(nodes, sizes[index][0])
        a_i = sizes[len(cur.kids)-2][0]
        b_i = sizes[len(cur.kids)-1][0]
        for i in range(len(removes)):
            if removes[i][0] == a_i or removes[i][0] == b_i:
                to_return += removes[i][1]
    return to_return


def build_tree(cur_index, father, connect):
    kids = []
    for con in connect:
        a = con[0]
        b = con[1]
        if cur_index == a and not b == father:
            kids.append(b)
        elif cur_index == b and not a == father:
            kids.append(a)
    nodes = [TreeNode(cur_index, father, kids)]
    for kid in kids:
        nodes.extend(build_tree(kid, cur_index, connect))
    return nodes


def handle_root(root_index, N, connect):
    return main_recursion(build_tree(root_index, 0, connect), root_index)
    #print '-------'
    #buil = build_tree(root_index, 0, connect)
    #for i in range(len(buil)):
    #    print buil[i]
    #return 0


def do_case(case, rfile, wfile):
    N = int(rfile.readline().strip())
    minimums = []
    connect = []
    for connection in range(N-1):
        nodes = map(int, rfile.readline().strip().split())
        connect.append([nodes[0], nodes[1]])
    for root_index in range(N):
        minimums.append(handle_root(root_index+1, N, connect))

    #print to file
    wfile.write('Case #'+str(case)+': '+str(min(minimums))+'\n')


def main():
    #open files
    rfile = file('Q2small.in', 'r')
    wfile = file('Q2small.out', 'w')

    num_of_cases = int(rfile.readline().strip())

    for case in range(num_of_cases):
        do_case(case+1, rfile, wfile)

if __name__ == '__main__':
    main()