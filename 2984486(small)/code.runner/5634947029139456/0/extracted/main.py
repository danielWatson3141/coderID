import sys
import copy

def solve(infile, outfile):
  num_tests = int(infile.readline().strip())
  for test_num in range(num_tests): 
    _, l = infile.readline().strip().split(' ')
    l = int(l)
    original_flow = set()
    required_flow = set()
    flow = infile.readline().strip()
    for x in flow.split(' '): 
      original_flow.add(int(x, 2))
    flow = infile.readline().strip()
    for x in flow.split(' '): 
      required_flow.add(int(x, 2))
    if original_flow.issubset(required_flow): 
      outfile.write("Case #%d: 0\n" % (test_num+1))
      continue
    solutions = []
    for x in range(1, 2**l+1): 
      intermediate_set = set()
      for y in original_flow: 
        intermediate_set.add(y^x)
      if required_flow.issubset(intermediate_set): 
        solutions.append(x)
    if not solutions: 
      outfile.write("Case #%d: NOT POSSIBLE\n" % (test_num+1))
    else: 
      solutions.sort(key = lambda x : bin(x)[2:].count('1'))
      outfile.write("Case #%d: %d\n" % (test_num+1, bin(solutions[0])[2:].count('1')))

if __name__ == "__main__": 
  filename = sys.argv[1]
  with open(filename, "r") as infile: 
    with open(filename + ".out", "w") as outfile:
      solve(infile, outfile)
  print("Done!")
