
def choose_best(sum_nodes, lst):
  sum_nodes -= 1
  min_to_throw = sum_nodes

  for i in xrange(0, len(lst)):
    for j in xrange(i+1, len(lst)):
      to_throw = lst[i][1] + lst[j][1] + (sum_nodes - lst[i][0] - lst[j][0])
      if to_throw < min_to_throw:
        min_to_throw = to_throw

  return to_throw

def travel(edges, src, node):
  sum_nodes = 1
  
  lst = []
  for x in edges[node]:
    if x != src:
       sum_x, min_to_remove_x = travel(edges, node, x)
       sum_nodes += sum_x
       lst.append((sum_x, min_to_remove_x))

  if len(lst) == 0:
    return sum_nodes, 0

  if len(lst) == 1:
    return sum_nodes, sum_nodes-1

  #if len(lst) > 2:
  #return sum_nodes, int(lst[0][1] + lst[1][1] + sum([lst[x][0] for x in xrange(2,len(lst))]))
  return sum_nodes, choose_best(sum_nodes, lst)
  

def count_remove_to_full_tree_root(N, edges, root):
  a,b = travel(edges, None, root)
  return b 

def count_remove_to_full_tree(N, edges):
  min_num_to_remove = N
  for root in xrange(1,N+1):
     num_to_remove = count_remove_to_full_tree_root(N, edges, root)
     if num_to_remove < min_num_to_remove:
       min_num_to_remove = num_to_remove

  return min_num_to_remove

if __name__ == '__main__':
  T = int(raw_input())

  for i in xrange(1,T+1):
    edges = {}
    N = int(raw_input())
    for j in xrange(1,N+1):
      edges[j] = []
    for j in xrange(N-1):
      x,y = tuple(int(t) for t in raw_input().split())
      edges[x].append(y)
      edges[y].append(x) 

    res = count_remove_to_full_tree(N, edges)
    print "Case #%s: %s" % (i, res)
    
