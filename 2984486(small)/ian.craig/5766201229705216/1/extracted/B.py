import sys

def main():
	f = open(sys.argv[1])
	T = int(f.readline().strip())
	for i in range(1,T+1):
		# Read in
		N = int(f.readline().strip())
		nodes = {}
		for j in range(N-1):
			(a,b) = f.readline().strip().split()
			for x in [a,b]:
				if not x in nodes.keys():
					nodes[x] = MyNode(x)
			nodes[a].addLink(nodes[b])
			nodes[b].addLink(nodes[a])
		# Calculate branch lengths
		for k, n in nodes.iteritems():
			calcLengths(n, None)
		# Find best
		minCost = None
		for k, n in nodes.iteritems():
			cost = findBest(n)
			#print n.name, cost
			if minCost == None or cost < minCost:
				minCost = cost
		print "Case #%d: %d" % (i, minCost)

class MyNode:
	def __init__(self, name):
		self.name = name
		self.links = []
		self.linkCount = []
		
	def addLink(self, l):
		self.links.append(l)
		self.linkCount.append(-1)
		
def calcLengths(n, p):
	inds = range(len(n.links))
	if p:
		inds.pop(n.links.index(p))
	for i in inds:
		if n.linkCount[i] > -1:
			continue
		child = n.links[i]
		calcLengths(child, n)
		n.linkCount[i] = 1
		for ci in range(len(child.links)):
			if child.links[ci] == n:
				continue
			n.linkCount[i] += child.linkCount[ci]

def findBest(n):
	if len(n.links) == 1:
		return n.linkCount[0]
	elif len(n.links) >= 3:
		best = []
		options = []
		for i in range(len(n.links)):
			best.append(findBestFrom(n.links[i],n))
		for i in range(len(n.links)):
			for j in range(len(n.links)):
				if i == j:
					continue
				cut = sum(n.linkCount) - n.linkCount[i] - n.linkCount[j];
				options.append(best[i] + best[j] + cut)
		return min(options)
	else: #len = 2
		return findBestFrom(n.links[0],n) + findBestFrom(n.links[1],n)

def findBestFrom(n,p):
	if len(n.links) == 1:
		return 0
	pInd = n.links.index(p)
	oInd = range(len(n.links))
	oInd.pop(pInd)
	
	if len(oInd) == 1: # 1 branch
		return n.linkCount[oInd[0]]
	elif len(oInd) == 2: # 2 branches
		return findBestFrom(n.links[oInd[0]],n) + findBestFrom(n.links[oInd[1]],n)
	else:
		best = []
		options = []
		for i in range(len(oInd)):
			best.append(findBestFrom(n.links[oInd[i]],n))
		for i in range(len(oInd)):
			for j in range(len(oInd)):
				if i == j:
					continue
				cut = sum(n.linkCount) - n.linkCount[oInd[i]] - n.linkCount[oInd[j]] - n.linkCount[pInd];
				options.append(best[i] + best[j] + cut)
		return min(options)

if __name__ == '__main__':
	main()