working = []
outlets = []
devices = []
nchanges = [999999999999]

def bitchange(bitarr, nbit):
    if (nbit != len(bitarr)):
        newbitarr1 = bitarr[:]
        newbitarr2 = bitarr[:]
        bitchange(newbitarr1, nbit+1)

        newbitarr2[nbit] = '1'
        bitchange(newbitarr2, nbit+1)
        return

    noutlets = outlets[:]
    bitnum = int(''.join(bitarr), 2)
    for i in xrange(len(noutlets)):
        noutlets[i] = noutlets[i] ^ bitnum
    noutlets.sort()

    #print "bitnum =", bitnum, "bitarr =", bitarr, "nbit =", nbit
    #print "outlets =", outlets
    #print "noutlets =", noutlets
    #print "devices =", devices

    matchflag = 1
    for i in xrange(len(noutlets)):
        if noutlets[i] != devices[i]:
            matchflag = 0
            break

    if matchflag:
        nchange = 0
        for i in bitarr:
            if i == '1':
                nchange += 1
        if nchange < nchanges[0]:
            nchanges[0] = nchange


fin = file("A-small-attempt0.in", "rU")
fout = file("A-small-attempt0.out", "w")

nruns = int(fin.readline().strip())
for i in xrange(nruns):
    line = fin.readline().strip().split()

    n = int(line[0])
    l = int(line[1])
    nchanges[0] = 999999999999

    outlets = fin.readline().strip().split()
    devices = fin.readline().strip().split()
    outlets = [int(x, 2) for x in outlets]
    devices = [int(x, 2) for x in devices]
    devices.sort()

    bitarr = []
    for j in xrange(l):
        bitarr.append('0')
    bitchange(bitarr, 0)

    result = "NOT POSSIBLE"
    if nchanges[0] < 999999999999:
    	result = nchanges[0]
    strout = "Case #" + str(i+1) + ": " + str(result) + "\n"
    #print strout
    fout.write(strout)
fin.close()
fout.close()
