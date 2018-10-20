import sys
import copy
import itertools

##############################################################################
class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned 
   (not reevaluated).
   '''
   def __init__(self, func):
      self.func = func
      self.cache = {}
   def __call__(self, *args):
      try:
         return self.cache[args]
      except KeyError:
         value = self.func(*args)
         self.cache[args] = value
         return value
      except TypeError:
         # uncachable -- for instance, passing a list as an argument.
         # Better to not cache than to blow up entirely.
         return self.func(*args)
   def __repr__(self):
      '''Return the function's docstring.'''
      return self.func.__doc__
   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      return functools.partial(self.__call__, obj)


x_array = []
@memoized
def check_whether(inpu, out, i, N, L):
    #print inpu, out, i, N, L
    if i == 0:
        for x in inpu:
            if x in out:
                del out[x]

        if len(out) == 0:
            return 0
        else:
            return None
    else:
        perms = list(itertools.combinations(x_array, i))
        #print perms

        for p in perms:
            #print "For: ", p
            y = {}
            inp = copy.deepcopy(inpu)
            for x in inp:
                #print "Inp: ", x
                xx = []
                for zzz in x:
                    xx.append(zzz)
                for ind in p:
                    #print "Ind: ", ind
                    if x[ind] == "1":
                        xx[ind] = "0"
                    else:
                        xx[ind] = "1"
                x = "".join(xx)
                #print "After switch: ", x
                y[x] = True
            
            out_cpy = copy.deepcopy(out)
            #print "After using P:", p, inp, out_cpy
            for x in y:
                if x in out_cpy:
                    del out_cpy[x]

            if len(out_cpy) == 0:
                return i
    
    return None

f = open(sys.argv[1], "r")
lines = f.readlines()
f.close()

cases = int(lines[0])
case_no = 0

index = 1
while(case_no != cases):
    case_no += 1
    N = int(lines[index].split(" ")[0])
    L = int(lines[index].split(" ")[1])
    
    x_array = []
    for i in range(L):
        x_array.append(i)

    index += 1
    
    initial = {}
    for x in lines[index].strip().split(" "):
        initial[x] = True
    
    index += 1
    output = {}
    for x in lines[index].strip().split(" "):
        output[x] = True

    #print initial, output
    result = None
    for i in range(L):
        result = check_whether(copy.deepcopy(initial), copy.deepcopy(output), i, N, L)
        if result is not None:
            break

    if result is None:
        result = "NOT POSSIBLE"

    index += 1
    print "Case #" + str(case_no) + ": " + str(result)
