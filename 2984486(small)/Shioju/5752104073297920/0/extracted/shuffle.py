import sys

def solve(permutation,N):
  ok = 0
  band = N/10
  for i in range(1,N):
    if permutation[i]<i+10:# and permutation[i]>i-band:
      ok+=1
  #print ok
  if ok>N/2:
    return 'GOOD'
  else:
    return 'BAD'


def main():
  T = int(sys.stdin.readline())
  for i in range(T):
    N = int(sys.stdin.readline())
    permutation = [int(x) for x in sys.stdin.readline().split()]
    result = solve(permutation,N)
    
    print "Case #%d: %s" % (i+1, result)

main()