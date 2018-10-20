INF = 10*10

def check(I,O):
	for inp in I:
		if not(inp in O): 
			return False
	return True

def findMin(I,O,pos,changes):
	if pos == len(I[0]):
		if check(I,O):
			return changes
		else: return INF
	nch = findMin(I,O,pos+1,changes)
	change(O,pos)
	ch = findMin(I,O,pos+1,changes+1)
	change(O,pos)
	return min(ch,nch)

def change(O,pos):
	for out in O:
		if out[pos] == "1":
			out[pos] = "0"
		else:
			out[pos] = "1"
	return O
#O = [["0","0","0"],["0","0","1"],["0","1","0"]]
#I = [["0","1","0"],["0","1","1"],["0","0","0"]]
#print(O)
#print(check(I,O))
#print(change(O,1))
#print(check(I,O))

for T in range(int(input())):
	N,L = map(int, input().split())
	O = list(map(list, input().split()))
	I = list(map(list, input().split()))
	#print(O)
	#print(I)
	minimum = findMin(I,O,0,0)
	if minimum == INF:
		print ("Case #"+str(T+1)+": NOT POSSIBLE")
	else: 
		print ("Case #"+str(T+1)+": "+str(minimum))
