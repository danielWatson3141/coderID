import math

if 1:
    f_in = open('C-small-attempt5.in', 'r')
    f_out = open('C-small.out', 'w')
else:
    f_in = open('C-large.in', 'r')
    f_out = open('C-large.out', 'w')

T = int(f_in.readline())
for case_id in range(T):
    N = int(f_in.readline().strip())
    A = [int(x) for x in f_in.readline().strip().split()]
    count = 0
    for i in range(N):
        count+=A[i]*(0.75-i*1./1000)*(0.75-i*1./1000)
    print count
    if count<71500:
        f_out.write("Case #"+str(case_id+1)+": BAD\n")
    else:
        f_out.write("Case #"+str(case_id+1)+": GOOD\n")
#        

    