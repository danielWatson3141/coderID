from collections import defaultdict
import collections
import functools

conn = None

class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)
      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)



numCases = input()
for caseNum in xrange(numCases):

    # build graph
    conn = defaultdict(list)
    for j in xrange(input()-1):
        a,b = map(int, raw_input().split())
        conn[a].append(b)
        conn[b].append(a)

    # find how many deleted nodes there are to make it a full binary tree
    @memoized
    def findDeleted(root, parent=None):
        global conn

        # print root, depth
        subTrees = [ findDeleted(neigh, root) for neigh in conn[root] if neigh != parent ]
        # print 'here'
        total = 1 + sum(( sub[0] for sub in subTrees ))  # total number of nodes in this subtree
        if len(subTrees) < 2:
            # print 'bop', root, total, total - 1
            return total, total - 1 # Discard everything but yourself

        # find the maximum two subs in regard to how many nodes they have left
        remaining = [ (tot-dele, tot, dele) for tot, dele in subTrees]
        remaining.sort()
        deleted =   remaining[-2][2] + remaining[-1][2]
        deleted += sum(( rem[1] for rem in remaining[:-2]))  # we deleted all nodes of the subtrees

        kept = 1 + remaining[-2][0] + remaining[-1][0]  # total number of remaining nodes
        # print 'boop: ', root, total, deleted, kept, subTrees#[ (total-deleted, total, deleted) for total, deleted in subTrees]
        assert total - deleted == kept

        return total, deleted

    minDeleted = min( (findDeleted(root)[1] for root in conn) )


    print 'Case #{0}: {1}'.format(caseNum+1, minDeleted)
