fh = open("A-small-attempt6.in", "r")
fh2 = open("outputFinal.txt", "w")
testCases = fh.readline()

def getFlips(N, L, outlets, devices, n):
    count0s = 0
    dCount0s = 0

    for o in outlets:
        if o[n] == "0":
            count0s += 1

    for d in devices:
        if d[n] == "0":
            dCount0s += 1

    if count0s == N / 2 and N % 2 == 0 and dCount0s == N / 2 and N % 2 == 0: #Try both
        if n == L - 1:
            if set(outlets) == set(devices):
                return 0
            if set([o[:n] + str(1 - int(o[n])) + o[n + 1:] for o in outlets]) == set(devices):
                return 1
            return "NOT POSSIBLE"
        
        ans1 = getFlips(N, L, outlets, devices, n + 1)
        ans2 = getFlips(N, L, [o[:n] + str(1 - int(o[n])) + o[n + 1:] for o in outlets], devices, n + 1)
        if ans1 == "NOT POSSIBLE":
            ans1 = 1000
        if ans2 == "NOT POSSIBLE":
            ans2 = 1000
        minNumber = min(ans1, ans2 + 1)
        if minNumber > 500:
            return "NOT POSSIBLE"
        return minNumber

    elif count0s == dCount0s: #Don't flip
        if n == L - 1:
            if set(outlets) == set(devices):
                return 0
            return "NOT POSSIBLE"
        
        return getFlips(N, L, outlets, devices, n + 1)
    elif count0s == N - dCount0s: #Flip
        if n == L - 1:
            if set([o[:n] + str(1 - int(o[n])) + o[n + 1:] for o in outlets]) == set(devices):
                return 1
            return "NOT POSSIBLE"
            
        ans = getFlips(N, L, [o[:n] + str(1 - int(o[n])) + o[n + 1:] for o in outlets], devices, n + 1)
        if ans == "NOT POSSIBLE":
            return "NOT POSSIBLE"
        return (ans + 1)
    else:
        return "NOT POSSIBLE"
    

for i in xrange(int(testCases)):
    nextline = fh.readline()
    N = int(nextline.split()[0])
    L = int(nextline.split()[1])
    outlets = fh.readline().split()
    devices = fh.readline().split()
    
    ans = str(getFlips(N, L, outlets, devices, 0))
    #print ("Case #" + str(i + 1) + ": " + ans + "\n")

    print outlets
    print devices
    print ans

    fh2.write("Case #" + str(i + 1) + ": " + ans + "\n")
    

fh.close()
fh2.close()
    
    
    
        
