import math

#any functions here
    
#main here
infile = open("Asmall.txt", "r")
outfile = open("Aout.txt", "w")
t = int(infile.readline().rstrip())
for z in range(1, t+1):
    #IO here
    raw = infile.readline().split()
    raw = [int (i) for i in raw]
    n, l = raw[0], raw[1]
    elecflow = infile.readline().split()
    device = infile.readline().split()
    solution=0
    cansolve = True
    for i in range(0, l):
        elec0=0
        elec1=0
        device0=0
        device1=0
        for each in elecflow:
            if each[i]=='0':
                elec0+=1
            else:
                elec1+=1
        for each in device:
            if each[i]=='0':
                device0+=1
            else:
                device1+=1
        if device0!=elec0:
            if device0==elec1 and device1==elec0:
                solution+=1
            else:
                if device0!=elec0:
                    cansolve = False
    if cansolve==False:
        solution = "NOT POSSIBLE"
    
    #output here
    output = "Case #"+str(z)+": " + str(solution) + "\n"
    print(output)
    outfile.write(output)

infile.close()
outfile.close()
