#!/usr/bin/env python


def dfs(root):
    global graph, visited
    visited.add(root)
    #print '@', root
    adj = [v for v in graph[root] if v not in visited]
    #print adj
    #print visited
    if len(adj) < 2:
        return 1
    scores = sorted(map(dfs, adj))
    #print scores, '\t', scores[-2:]
    return sum(scores[-2:]) + 1

if __name__ == '__main__':
    fin = open('bin_tree.in')
    TEST_COUNT = int(fin.readline())
    # print TEST_COUNT

    fout = open('bin_tree.out', 'w')
    for test in range(TEST_COUNT):
        n = int(fin.readline().strip())
        #print n
        graph = {}
        for i in range(n):
            graph[i] = set([])
        for i in range(n - 1):
            u, v = map(int, fin.readline().strip().split(' '))
            graph[u - 1].add(v - 1)
            graph[v - 1].add(u - 1)

        #print graph

        max_size = 1
        for root in graph:
            if len(graph[root]) >= 2:
                #print 'root = ', root
                visited = set([])
                curr_size = dfs(root)
                #print 'curr_size = ', curr_size
                max_size = max(max_size, curr_size)

        answer = 'Case #%d: %d' % (test + 1,  n - max_size)
        print answer
        fout.write(answer + '\n')

    fout.close()
