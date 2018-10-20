import copy

def app(num,src):
	#print src
	co = 0
	for i in range(len(num)):
		bi = num[i]
		if bi == "1":
			co += 1
			for s in src:
				if s[i] == "1":
					s[i] = "0"
				else:
					s[i] = "1"
	src.sort()
	return (src, co)

def solve():
	T = int(raw_input())
	Tid = 1
	
	while Tid <= T:
		s = raw_input().split()
		N = int(s[0])
		L = int(s[1])
		src = raw_input().split()
		src = map(list,src)
		dst = raw_input().split()
		dst = map(list,dst)
		dst.sort()
		mval = L+1
		for i in range(1<<L):
			num = str(bin(i)[2:])
			di = L - len(num)
			num = (di * "0") + num
			res = app(num,copy.deepcopy(src))
			#print (num,res,dst)
			if res[0] == dst:
				if res[1] < mval:
					mval = res[1]
		if mval == L+1:
			print "Case #%d: %s" % (Tid, "NOT POSSIBLE")
		else:
			print "Case #%d: %d" % (Tid, mval)
		Tid += 1

if __name__ == "__main__":
	solve()
