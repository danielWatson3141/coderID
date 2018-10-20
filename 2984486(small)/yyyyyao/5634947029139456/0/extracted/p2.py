def flip(num, outlets):
    _outlets = []
    for i in outlets:
        #print "b ", i
        #print "a ", i ^ num
        _outlets.append(i ^ num)
    return _outlets

def getBit(Leng, num):
    bitNum = 0
    for i in range(Leng):
        if num & (1 << i) != 0:
            bitNum += 1
    return bitNum

def getAnswer(x, devN, vLen, outlets, devs):
    #print "devN", devN, "vLen", vLen
    #print "outlets", outlets
    #print "devs", devs
    setDevs = set(devs)

    loop = pow(2, vLen)
    #print loop
    for i in range(loop):
        #print "i", i
        _outlets = flip(i, outlets)
        setOut = set(_outlets)
        if setOut == setDevs:
            #print "Answer", setOut, "num", getBit(vLen, i)
            print "Case #" + str(x) + ": " + str(getBit(vLen, i))
            return 

    
    print "Case #" + str(x) + ": NOT POSSIBLE"
    #    flip(0, outlets_int)
        

#files = open("./a.in")
files = open("./small.in")
#files = open("./hoge.in")

num = 0
probNum = 0
x = 1
flag = False
for line in files:
    num = num + 1
    if num == 1:
        probNum = int(line)
        continue

    if num % 3 == 2:
        bit = line.rsplit()
        devN = int(bit[0])
        vLen  = int(bit[1])
        outlets_int = []
        devs_int = []
    elif num % 3 == 0:
        outlets = line.rsplit()
        for i in outlets:
            outlets_int.append(int(i, 2))
    elif num % 3 == 1:
        devs = line.rsplit()
        #devs_int = map(int, outlets)
        for i in devs:
            devs_int.append(int(i, 2))
        getAnswer(x, devN, vLen, outlets_int, devs_int)
        x += 1
files.close()
