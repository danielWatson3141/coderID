import itertools

def num_difs(diff):
  return len([x for x in diff if x=='1'])

def op(x):
  if x == '1':
    return '0'
  return '1'

def apply_diff(N,L, grp, diff):
  new_grp = set()
  for val in grp:
    new_val = ""
    for i in xrange(L):
      if diff[i] == '1':
         new_val += op(val[i])
      else:
         new_val += val[i]

    new_grp.add(new_val)
  return new_grp 

def num_switches(N, L, initial, wanted):
  initial = set(initial)
  wanted = set(wanted)

  min_diff_size = L+1
  for diff in itertools.product('01', repeat=10):
    diff_size = num_difs(diff)
    applied = apply_diff(N,L,initial,diff)
    if applied == wanted:
      if diff_size < min_diff_size:
        min_diff_size = diff_size

  return min_diff_size
    

if __name__ == '__main__':
  T = int(raw_input())

  for i in xrange(1,T+1):
    N,L = tuple(int(x) for x in raw_input().split())
    initial = tuple(x for x in raw_input().split())
    wanted = tuple(x for x in raw_input().split())

    assert len(initial) == N
    assert len(wanted) == N

    res = num_switches(N,L,initial,wanted)
    if res < L+1:
      print "Case #%s: %s" % (i, res)
    else:
      print "Case #%s: NOT POSSIBLE" % i
