import sys
import re
import random

magic = 64

def generatecases(n, l):
  cases = []
  for i in xrange(n):
    a = [i for i in xrange(l)]
    for k in xrange(l):
      p = random.randint(0, l-1)
      buf = a[k]
      a[k] = a[p]
      a[p] = buf
    cases.append({'n': n, 'arr': a})
  return cases
def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    n = int(f.readline())
    array = map(int, r.split(f.readline()[:-1]))
    cases.append({'n': n, 'arr': array})
  f.close()
  return cases
def dostuff():
  cases = readcases() # generatecases(1000, 1000)#
  o = open('out.txt', 'w')
  good = 0
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    case = cases[i]
    arr = case['arr']
    avg = avg1 = avg2 = avg3 = avg4 = 0
    avg = reduce(lambda x,y:x+y, arr) / len(arr)
    if len(arr) % 2:
      avg1 = reduce(lambda x,y:x+y, arr[0:len(arr)/2 + 1]) / (len(arr)/2 + 1)*4
      avg2 = reduce(lambda x,y:x+y, arr[len(arr)/2 - 1:]) / (len(arr)/2 + 1) *4
      avg3 = reduce(lambda x,y:x+y, arr[::2]) / (len(arr)/2 + 1)  *4
      avg4 = reduce(lambda x,y:x+y, arr[1::2]) / (len(arr)/2) *4
    else:
      avg1 = reduce(lambda x,y:x+y, arr[0:len(arr)/2 - 1]) / len(arr)/2 *4
      avg2 = reduce(lambda x,y:x+y, arr[len(arr)/2:]) / len(arr)/2 *4
      avg3 = reduce(lambda x,y:x+y, arr[::2]) / len(arr)/2 *4
      avg4 = reduce(lambda x,y:x+y, arr[1::2]) / len(arr)/2 *4
    if abs(avg - avg1) >= case['n']/magic + 1 or abs(avg - avg2) >= case['n']/magic + 1 or abs(avg - avg3) >= case['n']/magic + 1 or abs(avg - avg4) >= case['n']/magic + 1:
      out += 'BAD'
      print avg, avg1, avg2, avg3, avg4
    else:
      out += 'GOOD'
      good += 1
    print out
    o.write(out + '\n');
    print good, len(cases)
  o.close();
def main():
  if len(sys.argv) != 2:
    print 'Usage: python magicial.py <input>'
  else:
    dostuff()
if __name__ == '__main__':
  main()
    
