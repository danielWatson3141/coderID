inputFile=open("input.txt","r")
outputFile=open("output.txt","w")
T=int(inputFile.readline().strip())
for i in range(1,T+1):
    N,L=inputFile.readline().strip().split(" ")
    N=int(N)
    L=int(L)
    outlets=inputFile.readline().strip().split(" ")
    devices=inputFile.readline().strip().split(" ")
    size=int(len(outlets[0])*"1",2)
    outlets=[int(item,2) for item in outlets]
    devices=[int(item,2) for item in devices]
    found=False
    for ii in range(0,size):
        o=[item^ii for item in outlets]
        o=[item for item in o if item not in devices]
        if o==[]:
            r=bin(ii).count("1")
            outputFile.write("Case #"+str(i)+": "+str(r)+"\n")
            found=True
            break

    if found==False:
        outputFile.write("Case #"+str(i)+": "+"NOT POSSIBLE"+"\n")
