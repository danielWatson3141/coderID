import math
problem = "A"
inf = open("../data/" + problem + ".in", "r")
outputs = []
outf = open("../data/" + problem + ".out", "w")
datasets = int(inf.readline())
scores = []
for dataset in range(datasets):
  ncases = int(inf.readline())
  data = map(int, inf.readline().strip().split(" "))
  #print data
  score = 0.0
  for i in range(ncases):
    if data[i] > i:
      offby = data[i] - i
      left = ncases - i
      tscore = (left - offby) / 1000.0
      score += tscore
  scores.append([score, dataset])
scores.sort(key=lambda x:x[0])
correct = 0
for i in range(datasets):
  mscore = 0.0
  for j in range(datasets):
    if scores[j][1] == i:
      if j > datasets / 2:
        out = 'BAD'
      else:
        out = 'GOOD'
      mscore = scores[j][0]
      break;
  #outputs.append("Case #" + str(i + 1) + ": " + str(mscore) + " " + out)
  outputs.append("Case #" + str(i + 1) + ": " + out)
  
  if out == 'BAD' and i < datasets / 2:
    correct += 1
  elif out == 'GOOD' and i >= datasets / 2:
    correct += 1
outf.write("\n".join(outputs))
print "\n".join(outputs)
print correct 
