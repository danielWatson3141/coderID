fxs = open("C:\Users\Petr\Downloads\C-small-attempt1.in", "r")

repeat = int(fxs.readline())

for count in range(repeat):
######repeat this####

    N = fxs.readline() ###### 1000
    P = fxs.readline().split()[:]

    a=0
    b=0

    for x in range(500):
        a+= int(P[x])
        b+= int(P[-x])

    if a-b > 5000:
        out = "BAD"
    elif a-b <-5000:
        out = "BAD"
    else: out = "GOOD"


    lst = ["Case #", str(count + 1), ": ", out]
    print  "".join(lst)
