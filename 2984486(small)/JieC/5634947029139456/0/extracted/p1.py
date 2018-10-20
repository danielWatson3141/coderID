import sets
fin_name = "p1_input.in"
fin_name = "A-small-attempt1.in"
fout_name = "p1.out"
with open(fin_name) as fin:
    content = fin.readlines()
fout = open(fout_name, 'r+')



def flip(str, i):
	str_arr = list(str)
	if str_arr[i] == "1":
		str_arr[i] = "0"
	else:
		str_arr[i] = "1"
	return ''.join(str_arr)

def flipBitsList(list1, pattern, N, L):
	temp = list1
	for d in range(0,N):
		temp[d] = flipBits(list1[d], pattern, L)
	return temp
	
def flipBits(str,pattern,L):
	
	txt = list(str)
	for i in range(0,L):
		if pattern[i] == "1":
			if txt[i] == "1":
				txt[i] = "0"
			else:
				txt[i] = "1"
	#print "   ",str, pattern,"".join(txt)
	return "".join(txt)
	
def toBinary(n, L):
	getBin = lambda x, n: x >= 0 and str(bin(x))[2:].zfill(n) or "-" + str(bin(x))[3:].zfill(n)
	return getBin(n,L)

def sumList(list):
	total = 0
	for i in list:
		total = total + int(i)
	return total

num_cases = content[0]
case_index = 0
lines_per_case = 3
for case_index in range(0,int(num_cases)): 
	line1 = content[case_index * lines_per_case + 1].strip()
	line2 = content[case_index * lines_per_case + 2].strip()
	line3 = content[case_index * lines_per_case + 3].strip()
	N = int(line1.split(" ")[0])
	L = int(line1.split(" ")[1])
	initial = line2.split(" ")
	final = line3.split(" ")
	
	flips = 100000
	
	for l in range(0,pow(2,L)):
		init = initial
		pattern = list(toBinary(l,L))
		flipped = flipBitsList(line2.split(" "), pattern, N, L)
		#print "F=",final, "I=",initial, "P=",pattern, "F=",flipped
		if set(flipped) == set(final):
			if sumList(pattern) < flips:
				flips = sumList(pattern)
	print flips
	if flips == 100000:
		fout.write("Case #"+str(case_index+1)+": NOT POSSIBLE\n")
	else:
		fout.write("Case #"+str(case_index+1)+": " + str(flips)+"\n")
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	