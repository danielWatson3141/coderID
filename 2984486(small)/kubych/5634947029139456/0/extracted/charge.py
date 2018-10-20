for case in range(int(raw_input())):
    n, l = [int(i) for i in raw_input().split()]
    x = [int(i, 2) for i in raw_input().split()]
    y = [int(i, 2) for i in raw_input().split()]
    s = "0"
    st = ""
    for j in range(l):
        st += "1"
    k = int(st, 2)

    if len(set(x) - set(y)) == 0:
        print "Case #" + str(case + 1) + ": " + s
    else:
        possible = 0
        for j in range(k + 1):
            z = [int(j ^ i) for i in x]
            if len(set(z) - set(y)) == 0:
                s = str(bin(j).count("1"))
                possible = 1
                print "Case #" + str(case + 1) + ": " + s
                break
        if possible == 0:
                print "Case #" + str(case + 1) + ": " + "NOT POSSIBLE"
        
        
    