
def isWin(a, b):
  return set(a) == set(b)

def convertFlow(flow, result):
  diffs = differences(flow[0], result)
  #print "diffs", diffs, flow[0], result
  out = []
  for f in flow:
    f = list(f)
    for d in diffs:
      #print f, d
      if f[d] == '0':
        f[d] = '1'
      elif f[d] == '1':
        f[d] = '0'
    out.append(''.join(f))
  #print out
  return out, len(diffs)

def differences(line1, line2):
  out = []
  for i in range(len(line1)):
    if line1[i] != line2[i]:
      out.append(i)
  return out


if __name__ == "__main__":
  T = int(raw_input())
  #print "T", T

  for caseNum in range(T):
    print "Case #{0}:".format(caseNum + 1),

    #N = 3
    #L = 2
    #FLOW = ["01", "11", "10"]
    #RESULT = ["11", "00", "10"]


    [N,L] = [int(a) for a in raw_input().split(' ') if a != '']

    FLOW = raw_input().split(' ')
    RESULT = raw_input().split(' ')
    
    #print N, L, FLOW, RESULT

    if isWin(FLOW, RESULT):
      print 0
      continue

    results = []
    for n in range(N):
      testResult = RESULT[n]
      converted, diffs = convertFlow(FLOW, testResult)
      if isWin(converted, RESULT):
        results.append(diffs)
        continue
    if len(results) == 0:
      print "NOT POSSIBLE"
    else:
      print min(results)


