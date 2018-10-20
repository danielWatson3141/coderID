fin = file("C-small-attempt2.in", "rU")
fout = file("C-small-attempt2.out", "w")

nruns = int(fin.readline().strip())
for i in xrange(nruns):
    line = fin.readline().strip().split()

    n = int(line[0])

    perm = [int(x) for x in fin.readline().strip().split()]

    ninc = 0
    for j in xrange(1, len(perm)/2):
    	if perm[j] > perm[j-1]:
    		ninc += 1

    result = "GOOD"
    if ninc > n/4:
    	result = "BAD"

    strout = "Case #" + str(i+1) + ": " + str(result) + "\n"
    #print strout
    fout.write(strout)
fin.close()
fout.close()
