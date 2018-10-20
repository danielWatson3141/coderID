def main(input, cases):
  o = open("output.out", "w")
  for i in range(cases):
    case = int(input.readline())
    data = dict()
    for j in range(case-1):
      pair = read(input) 
      for j in pair:
        if j not in data:
          data[j] = 1
        else:
          data[j] = data[j] + 1

    neighbor = dict()
    neighbor["1"] = 0
    neighbor["2"] = 0
    neighbor["3"] = 0
    
    count = 0

    for j in data:
      if data[j] < 4:
        neighbor[str(data[j])] = neighbor[str(data[j])] + 1 
      else:
        count += 1
    output = solve(neighbor)
    output -= count
    o.write("Case #{num}: {ans}\n".format(num=str(1+i), ans=output))

def solve(neighbor):
  if neighbor["2"] > 1:
    return neighbor["2"] - 1
  return 0

def read(input):
  return input.readline().rstrip('\n').split(" ")
if __name__ == "__main__":
  file = open("input.in", "r")
  cases = int(file.readline())
  main(file, cases)
