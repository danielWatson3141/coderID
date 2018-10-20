import csv
from itertools import product

def getResult(n,l,have,result):
    flips = 0
    min_flips = 1000
    n,l = int(n),int(l)
    for item in product(range(2),repeat=l):
	num,changed = makeChanges(item,have)
	if changed == result and num < min_flips:
	    min_flips = num
    if min_flips == 1000:
	return 'NOT POSSIBLE'
    else:
	return min_flips

def makeChanges(vect, plugs):
    temp = set()
    #print vect,len(vect)
    for titem in plugs:
	t2 = list(titem)
	for i in range(len(vect)):
	    if vect[i] == 1:
		t2[i] = str(1-int(t2[i]))
	temp.add(''.join(t2))
    return sum(vect),temp
	
def readGraph(n,infile):
    counts = {}
    for i in range(n-1):
	for it in infile.next():
	    if it not in counts:
		counts[it] = 0
	    counts[it] += 1
    return counts
	

def fullTree(infile):
    reader = csv.reader(open(infile,'r'),delimiter=' ')
    t,t0 = int(reader.next()[0]),0
    while t0 < t:
	t0 += 1
	n = int(reader.next()[0])
	graph = readGraph(n,reader)
	#print graph
	if graph.values().count(1) == n-1:
	    rstr = n-1
	else:
	    rstr = graph.values().count(2)-1

	#rstr = getResult(n,l,have,want)
	#print 'Case #%s: %0.7f' % (t0,float(rstr))
	if rstr >= 0 :
	    print 'Case #%s: %s' % (t0,str(rstr))
	else:
	    print 'Case #%s: %s' % (t0,str(1))


if __name__ == '__main__':
    import argparse
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('infile',metavar='infile',type=str)
    args = ap.parse_args()
    fullTree(args.infile)
