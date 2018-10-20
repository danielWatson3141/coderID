import sys
import re

primes = [0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    nl = map(int, r.split(f.readline()[:-1]))
    outlet = r.split(f.readline()[:-1])
    device = r.split(f.readline()[:-1])
    cases.append({'n': int(nl[0]), 'l': int(nl[1]), 'ob': outlet, 'db': device})
  f.close()
  return cases
def toDec(bin):
  p = 1
  r = range(0, len(bin))
  r.reverse()
  res = 0
  for i in r:
    res += p*int(bin[i])
    p *= 2
  return res
def toBin(dec, n = 0):
  p = 2
  bin = []
  d = dec
  while 1:
    bin[0:0] = [d%2]
    d = d/2
    if d < 1:
      if n <= len(bin):
        break
  return bin
def flip(bin, pos):
  b = list(bin)
  for i in xrange(len(b)):
    b[i] = map(int, b[i])
    for j in xrange(len(b[i])):
      b[i][j] = (b[i][j] + pos[j]) % 2
  return b
def dostuff():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    case = cases[i]
    case['od'] = map(toDec, case['ob'])
    case['od'].sort()
    case['dd'] = map(toDec, case['db'])
    case['dd'].sort()
    #print case
    solved = False
    attempt = 0
    for attempt in xrange(2**case['l']):
      flipped = flip(case['ob'], toBin(attempt, case['l']))
      flipped = map(toDec, flipped)
      flipped.sort()
      solved = True
      for j in xrange(case['n']):
        if flipped[j] != case['dd'][j]:
          solved = False
          break
      if solved:
        break
    if solved:
      ab = toBin(attempt)
      num = 0
      for a in xrange(len(ab)):
        if ab[a] > 0:
          num += 1
      out += str(num)
    else:
      out += 'NOT POSSIBLE'
    print out
    o.write(out + '\n');
  o.close();
def main():
  if len(sys.argv) != 2:
    print 'Usage: python magicial.py <input>'
  else:
    dostuff()
if __name__ == '__main__':
  main()
    
