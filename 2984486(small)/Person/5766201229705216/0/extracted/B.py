from sys import argv
import itertools

def deepcopy(l):
	return list(i[:] for i in l)

def isBroken(pairList, deletedNodes):
	covered = set([pairList[0][0], pairList[0][1]])
	added = True
	remainingPairs = pairList[:]
	while added:
		added = False
		for pair in pairList[1:]:
			if (pair[0] in covered or pair[1] in covered) and pair in remainingPairs:
				added = True
				covered.add(pair[0])
				covered.add(pair[1])
				remainingPairs.remove(pair)
	if covered != set(range(1, N+1)).difference(deletedNodes):
		# print 'Broken'
		return True
	# print 'Not Broken'
	return False

def isValid(pairList, deletedNodes):
	if len(pairList)==0:
		return False
	if isBroken(pairList, deletedNodes):
		return False
	numbers = set()
	doublecount=0
	double=0
	for i in range(1, N+1):
		count=0
		for pair in pairList:
			if i in pair:
				count+=1
				numbers.add(i)
		if count==2:
			doublecount+=1
			double = i
	# print set(range(1, N+1)).difference(numbers)
	# print set(deletedNodes)
	if set(range(1, N+1)).difference(numbers) != set(deletedNodes):
		print 'nodes don\'t line up'
		return False

	# print pairList
	# print doublecount
	# print double
	# print ''
	if doublecount != 1:
		return False
	return validate(pairList, double)

def validate(pairList, root):
	pairsToRemove=[]
	roots=[]
	for pair in pairList:
		if root in pair:
			pairsToRemove.append(pair)
			roots.append(pair[0] if pair[1]==root else pair[1])
	if len(pairsToRemove)==0:
		return True
	if len(pairsToRemove)==2:
		pairList.remove(pairsToRemove[0])
		pairList.remove(pairsToRemove[1])
		return validate(pairList, roots[0]) and validate(pairList, roots[1])
	return False

with open(argv[1]) as f:
	data = f.read().split('\n')

out=[]
for case in range(int(data.pop(0))):
	# raw_input()
	print case
	N = int(data.pop(0))
	pairs = list([map(int, data.pop(0).split()) for i in range(N-1)])

	if isValid(pairs, []):
		out.append(0)
		continue

	for r in range(1, N-1):
		for numbersToRemove in itertools.combinations(range(1, N+1), r):
			# print numbersToRemove
			testpairs = deepcopy(pairs)

			# print '!!!!!!!!!!!!!!!!!!!!!!!!1'
			# print testpairs
			pairsToRemove = []
			for pair in testpairs:
				for n in numbersToRemove:
					if n in pair:
						pairsToRemove.append(pair)

			# print pairsToRemove
			for pair in pairsToRemove:
				# print pair
				if pair in testpairs: testpairs.remove(pair)

			# print testpairs
			if isValid(testpairs, numbersToRemove):
				# print True
				out.append(r)
				# print 'YAY'
				break
			# print False
		else:
			continue
		break
	else:
		out.append(N-1)

with open(argv[2], 'w') as f:
	for i in range(len(out)):
		f.write('Case #%d: %s\n'%(i+1, out[i]))