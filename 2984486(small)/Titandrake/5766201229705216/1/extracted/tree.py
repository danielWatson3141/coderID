t = input()
# brute force it

# from python docs
from itertools import chain, combinations

def powerset(iterable):
  xs = list(iterable)
  # note we return an iterator rather than a list
  return chain.from_iterable( combinations(xs,n) for n in range(len(xs)+1) )

def find_degrees(start, ss, n):
    ss = set(ss)
    if len(ss) == n:
        return False
    if len(ss) == n -1:
        return True
    degrees = []
    for i in range(n):
        if i in ss:
            degrees.append(0)
        else:
            edges = set(start[i])
            degrees.append(len(edges - ss))
    fail = False
    ind = -1
    if degrees.count(2) != 1:
        return False
    else:
        ind = degrees.index(2)
   # print ss, ind
   # print degrees
    # check connectedness and degree
    visited = set()
    to_check = [ind]
    while to_check:
        i = to_check.pop()
        visited.add(i)
        next = set(start[i]) - ss
        #print ss, visited, i, next
        next = sorted(list(next - visited))
        if len(next) not in (0, 2):
            return False
        to_check.extend(next)
    return len(visited) == (n - len(ss))
  
def find_tree(start, n):
    for ss in powerset(list(range(n))):
        if find_degrees(start, ss, n):
            return len(ss)

def num_reachable(start, root, seen):
    visited = set()
    to_check = [root]
    while to_check:
        i = to_check.pop()
        visited.add(i)
        next = (set(start[i]) - visited) - seen
        #print ss, visited, i, next
        to_check.extend(list(next))
    return len(visited)
            
def check_with_root(start, root):
    removed = 0
    seen = set()
    curr = [root]
    while curr:
        curr_root = curr.pop()
        seen.add(curr_root)
        children = set(start[curr_root]) - seen
        if len(children) > 2:
            d = [(ch, num_reachable(start, ch, seen)) for ch in children]
            d.sort(key=lambda x: -x[1])
            removed += sum(x[1] for x in d[2:])
            curr.append(d[0][0])
            curr.append(d[1][0])
        elif len(children) < 2:
            removed += sum(num_reachable(start, ch, seen) for ch in children)
        else:
            curr.extend(list(children))
    return removed
    
def find_tree_2(tree):
    best = 100000
    for root in range(len(tree)):
        n = check_with_root(tree, root)
        best = min(best, n)
    return best
            
    
            
for case in range(1, t+1):
    n = input()
    tree = [ [] for _ in range(n) ]
    for _ in range(n-1):
        a, b = map(int, raw_input().split())
        tree[a-1].append(b-1)
        tree[b-1].append(a-1)
    print "Case #%d: %d" % (case, find_tree_2(tree))
    