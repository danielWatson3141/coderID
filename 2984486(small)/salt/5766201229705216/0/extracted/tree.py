
def compare(item1, item2):
    if item1["g"]+item1["b"] < item2["g"]+item2["b"]:
        return -1
    elif item1["g"]+item1["b"] > item2["g"]+item2["b"]:
        return 1
    elif item1["b"] < item2["b"]:
        return -1
    elif item1["b"] > item2["b"]:
        return 1
    else:
        return 0

def travers(tree, fromEl, cur):
	#print "From %d to %d" % (fromEl,cur)
	answer = { "g": 0, "b": 0 }
	results = []
	for key in tree[cur].keys():
		if key != fromEl:
			#print "going to %d" % key
			re = travers(tree, cur, key)
			re["f"] = key
			results.append(re)

	if len(results) == 0:
		return { "g": 1, "b": 0 }
	if len(results) == 1:
		return { "g": 1, "b": (results[0]["g"] + results[0]["b"]) }


	so = sorted(results, cmp=compare)
	#print cur
	#print '+'
	#print so


	#print cur
	#print so

	bad = 0
	for i in range(len(so)-2):
		bad += so[i]["g"] + so[i]["b"]
	bad += so[-1]["b"] + so[-2]["b"]

	#print "Bad %d Good %d" % (bad, so[-1]["g"] + so[-2]["g"]) 
	return { "g": (so[-1]["g"] + so[-2]["g"] + 1), "b" : bad }

T = int(raw_input())
for t in range(T):
	#print t
	N = int(raw_input())
	tree = {}
	#if t == 45:
		#print N
	for n in range(N-1):
		#print n
		a = raw_input().split(' ')
		#if t == 45:
			#print "%s %s" % (a[0],a[1])
		b = []
		for el in a:
			b.append(int(el))
		if not b[0] in tree:
			tree[b[0]] = {}
		tree[b[0]][b[1]] = 1

		if not b[1] in tree:
			tree[b[1]] = {}
		tree[b[1]][b[0]] = 1

	minD = N+1

	for i in range(N):
		res = travers(tree,-1,i+1)
		if res["b"] < minD:
			minD = res["b"]
			#print "min %d i+1: %d" % (minD,i+1)

	#print travers(tree, 3, 1)
	
	print "Case #%d: %d" % (t+1,minD)

	
