from collections import defaultdict, deque
import sys

sys.setrecursionlimit(5000)

class Node(object):
    def __init__(self, val):
        self.val = val
        self.chils = []
        self.size = 1



T = int(raw_input())
for kei in xrange(T):
    N = int(raw_input())
    vals = set()
    adj = defaultdict(list)
    for i in xrange(N-1):
        f, t = [int(x) for x in raw_input().split()]
        vals.add(f)
        vals.add(t)
        adj[f].append(t)
        adj[t].append(f)
    # print(adj)
    vals = list(vals)
    nodes = {}
    for val in vals:
        nodes[val] = Node(val)
    min_rem = N-1
    for rootval in vals:
        root = nodes[rootval]
        st = [root]
        marked = set([rootval])
        def make_tree(u):
            u.l = u.r = None
            u.childs = []
            u.size = 1
            for v in adj[u.val]:
                if v in marked:
                    continue
                marked.add(v)
                nc = make_tree(nodes[v])
                u.childs.append(nc)
                u.size += nc.size
            return u
        def print_tree(u):
            print u.val, [v.val for v in u.childs], 'size=%d' % u.size, 'child=%d'%len(u.childs)
            for v in u.childs:
                print_tree(v)


        def make_bin_tree(root):
            tot = 0
            # for child in root.childs:
            #     tot += make_bin_tree(child)
            root.childs.sort(key=lambda x:-x.size)
            # print('the childs of %d is %d' % (root.val, len(root.childs),))
            if len(root.childs) == 1:
                diff = root.childs[0].size
                # print 'cut in %d: %d' % (root.val, diff)
                tot += diff
                # root.size -= diff
            elif len(root.childs) >= 2:
                diff = sum(child.size for child in root.childs[2:])
                # print 'cut in %d: %d' % (root.val, diff)
                tot += diff
                # root.size -= diff
                for child in root.childs[:2]:
                    tot += make_bin_tree(child)
            return tot

        root = make_tree(root)
        # print_tree(root)

        # while len(st):
        #     u = st.pop()
        #     u.l = u.r = None
        #     childs = 0
            
        # q = deque([root])
        # nrem = 0
        # while len(q):
        #     u = q.popleft()
        #     u.childs.sort(key=lambda x: x.childs)
        #     if len(u.childs) == 1:
        #         nrem += u.childs[0].size
        #     elif len(u.childs > 2):
        #         nrem += sum(u.childs[])
        res = make_bin_tree(root)
        # print 'res', res
        # print '*'*30
        min_rem = min(min_rem, res)
    print 'Case #%d: %d' % (kei+1,min_rem,)






