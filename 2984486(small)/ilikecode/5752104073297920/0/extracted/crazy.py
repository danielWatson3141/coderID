#Worth a shot
def tester(list):
    l = len(list)-1
    total=0
    for i in range(l+1):
        if i<l/2:
            total+=list[i]*(10*i-10*l//4)
        else:
            total+=list[i]*(30*l//4-i*10)
    if total>10*l*l:
        return "BAD"
    else:
        return "GOOD"


input_text = open("input.in")
lines = input_text.readlines()
input_text.close()
currentLine=1
with open("output", "a") as outputfile:
    for num in range(0,int(lines[0])):
        arrayIn = [int(num) for num in lines[num*2+2].split(" ")]
        outputfile.write("Case #"+str(num+1)+": "+tester(arrayIn)+"\n")
