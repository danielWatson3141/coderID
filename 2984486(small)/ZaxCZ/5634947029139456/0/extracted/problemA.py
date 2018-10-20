repeat = 1
N = 4
L = 3

fxs = open("C:\Users\Petr\Downloads\A-small-attempt01.in", "r")

repeat = int(fxs.readline())

for count in range(repeat):
######repeat this####

    NL = fxs.readline()
    N = NL.split()[0]
    L = int(NL.split()[1])

    outlets = fxs.readline().split()[:]
    devices = fxs.readline().split()[:]
    flipCfg = []


    for i in range(2**L):
        flipCfg.append(str(bin(i)).replace("0b", ""))
        if len(flipCfg[i]):
            for k in range(L - len(flipCfg[i])):
                flipCfg[i] = "0" + flipCfg[i]



    out = "500"
    devices1 = devices[:]
    outlets1 = outlets[:]


    for x in range(2**L):

        no = 0
        devices1 = devices[:]
        outlets1 = outlets[:]

        o = 0
        for outlet in outlets:
            f = 0

            s = ""
            for flip in flipCfg[x]:


                if flip == "1":

                    if outlet[f] == "1":
                        s += "0"

                    else:
                        s += "1"
                    no +=1

                else: s += outlet[f]
                f += 1

                outlets1[o] = s
            o += 1

        if set(outlets1).intersection(set(devices1)) == set(devices1):
            z = list(flipCfg[x])
            out1 = 0
            for l in z:
                out1 += int(l)
            if out1 < int(out):
                out = str(out1)



    if out == "500":
        out = "NOT POSSIBLE"
    lst = ["Case #", str(count + 1), ": ", out]
    print  "".join(lst)
