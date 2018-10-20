'''
Created on Apr 12, 2014

@author: ononon1
'''


fname = "../Perm4.txt"
f = open(fname, 'r')
fout = open(fname.replace(".txt","_out.txt"), 'w')
s = f.readline()
#print(s)
for i in range(1,(int(s)+1)):
    num = int(f.readline())
    res = list(map(int,f.readline().split()))

    print(i,res)
    count = 0;
    for j in range(1,num-1):
        if(abs(res[j]-res[j-1])==abs(res[j+1]-res[j])):
            count = count +1
        if(res[j] == j):
            count = num
        if(abs(res[j]-j) < 10):
            count = count +1
    if(count > num/10):
        ans = "BAD"
    else:
        ans = "GOOD"
    fout.write("Case #"+str(i)+": "+ ans +"\n")




