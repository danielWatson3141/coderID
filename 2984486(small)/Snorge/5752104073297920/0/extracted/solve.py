import sys
sys.setrecursionlimit(100000)

# functions

# get the file
f = open(sys.argv[1])

count = int(f.readline().strip())

# to list
for i in range(count):
    good = True
    N = int(f.readline().strip())
    A = f.readline().strip().split()
    a = [int(b) for b in A]

    neg = 0
    same = 0
    one = 0
    for k in range(N):
        if a[k] == k:
            same += 1
        if k+1 < N and a[k+1] == k:
            one += 1
        if k-1 >= 0 and a[k-1] == k:
            neg += 1
    if neg > 1:
        good = False
    elif same >= 2:
        good = False
    elif one >= 2:
        good = False
    else:
        good = True

            
    
    if good:
        print("Case #" + str(i+1) + ": GOOD")
    else:
        print("Case #" + str(i+1) + ": BAD")

    
