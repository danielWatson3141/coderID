'''
Created on Apr 25, 2014

@author: Sean
'''
fin = open('C-small.in', 'r')
finput = fin.readlines()
fin.close()

it = iter(finput)

numbCases = (int)(it.next())

output = ""

# from simulation in separate file
cutoff = 321164.194 + (333728.548 - 321164.194)/2

for case in xrange(numbCases):
    it.next()
    a = [int(j) for j in (it.next()).split()]
    total = 0
    for k in range(1000):
        total += abs(a[k] - k)
    if (total >= cutoff):
        output += "Case #%d: GOOD\n" % (case+1)
    else:
        output += "Case #%d: BAD\n" % (case+1)
    
fout = open('small.txt', 'w')
fout.write(output)
fout.close