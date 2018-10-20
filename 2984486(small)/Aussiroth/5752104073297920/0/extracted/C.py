import math
import random

#any functions here


#main here
infile = open("Csmall1.in", "r")
outfile = open("Cout.txt", "w")
t = int(infile.readline().rstrip())
countbad=0
for z in range(1, t+1):
    #IO here
    N = int(infile.readline().rstrip())
    perm = infile.readline().split()
    perm = [int(i) for i in perm]
    weight = 0
    for i in range(0, len(perm)):
        if perm[i]>i:
            weight += (N/2)-(perm[i]-i)
        if perm[i]<=i:
            weight -= (N/2)-(i-perm[i])
    if weight>11000:
        print("BAD")
        output="BAD"
        countbad+=1
    else:
        print("GOOD")
        output="GOOD"
    #output here
    output = "Case #"+str(z)+": "+output+"\n"
    #print(output)
    outfile.write(output)
print(countbad)
infile.close()
outfile.close()
