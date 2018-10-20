def solve(N, edges):
    """ solve the problem """

    #print(N, edges)
    #root = 2
    all_scores = []
    for root in range(1, N+1):
        stack1 = [{'parent': 0, 'cur': root}]
        stack2 = []
        #print(stack)
        #for edge in edges:
        while stack1:
            node = stack1.pop()

            parent = node['parent']
            cur = node['cur']
            if node['parent'] == 0:
                childs = edges[cur]
            else:
                childs = edges[cur] - {parent}

            for c in childs:
                stack1.append({'parent': cur, 'cur': c})

            node['childs'] = childs
            stack2.append(node) 

        #print(stack2)
        scores = {}
        for node in reversed(stack2):
            cur = node['cur']
            childs = node['childs'] 

            if len(childs) == 0 or len(childs) == 1:
                scores[cur] = 1
                continue
                
            child_scores = [scores[c] for c in childs]
            child_scores.sort()
            score = child_scores[-2] + child_scores[-1] + 1
            scores[cur] = score
            
        #print(root, scores)
        #print( max( scores.values() ) )
        #print()
        all_scores.append( max(scores.values()) )

    return N - max(all_scores)


def parse():
    """ parse input """

    N = int(input())
    edges = {}
    #for i in range(N-1):
    #    a, b = map(int, input().split(' ')) 
    #    edges.append((a, b))
    #    edges.append((b, a))
    for i in range(N-1):
        a, b = map(int, input().split(' ')) 
        if a not in edges: edges[a] = set()
        edges[a].add(b)
        if b not in edges: edges[b] = set()
        edges[b].add(a)

    return N, edges


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))


if __name__ == '__main__':

    main()
