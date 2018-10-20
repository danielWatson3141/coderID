def main(input, cases):
  o = open("output.out", "w")
  for i in range(cases):
    N,L = read(input)
    flow = read(input)
    sol = read(input)
    output = solve(N, L, flow, sol)
    o.write("Case #{num}: {ans}".format(num=str(i+1), ans=output))

def read(input):
  return input.readline().rstrip('\n').split(" ")

def solve(N, L, flow, sln):
  stuff = []
  for curr in flow:
    diff = []
    for sol in sln:
      diff.append(getDiff(curr, sol))
    stuff.append(diff)

  possibleResults = []
  for i in range(len(stuff[0])):
    lt = []
    lt.append(i) 
    result = find(stuff, 1, stuff[0][i], lt)
    if result:
      possibleResults.append(result.count("0"))
  if len(possibleResults) == 0:
    return "NOT POSSIBLE\n"
  else:
    possibleResults.sort()
    return str(possibleResults[0]) + "\n"

def find(stuff, index, curr, lt):
  if len(lt) == len(stuff[0]):
    return curr

  for i in range(len(stuff[index])):
    if i not in lt and curr == stuff[index][i]:  
      lt.append(i)
      valid = find(stuff, index+1, curr, lt)
      if valid:
        return curr
      else:
        lt.pop()
  return None
  
def getDiff(curr, sol):
  string = ""
  for i in range(0, len(curr)):
    if curr[i] == sol[i]:
      string = string + "1"
    else:
      string = string + "0"
  return string

if __name__ == "__main__":
  file = open("input.in", "r")
  cases = int(file.readline())
  main(file, cases)
