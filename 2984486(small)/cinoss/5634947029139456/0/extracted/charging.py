import sys
fname = "A-small-attempt0.in.txt"
# fname = "B-large.in"
# fname = "sample.in"
fi = open(fname)
fo = open("fo.txt","w")
def visit(k):
	global changed, min_changed
	if min_changed == pos_min:
		return
	if k == l:
		global pair
		# print changed
		avail = [True]*n
		for i in range(n):
			found = False
			for j in range(n):
				if init[i] == final[j] and avail[j]:
					avail[j] = False
					found = True
					break
			if not found:
				return
		if changed < min_changed:
			min_changed = changed
		return
	if count_init[k] == count_final[k]:
		visit(k+1)
	if count_init[k] == n-count_final[k]:
		for i in range(n):
			init[i][k] = 1-init[i][k]
		changed += 1
		visit(k+1)
		changed -= 1
		for i in range(n):
			init[i][k] = 1-init[i][k]
	
for test in range(int(fi.readline())):
	n,l = [int(x) for x in fi.readline().strip().split()]
	init = [[int(x) for x in y] for y in fi.readline().strip().split()]
	final = [[int(x) for x in y] for y in fi.readline().strip().split()]
	finished = False
	count_init = []
	count_final = []
	for i in range(l):
		count_init.append(sum([int(x[i]) for x in init]))
		count_final.append(sum([int(x[i]) for x in final]))
	pos_min = 0
	for i in range(l):
		if count_final[i]+count_init[i] == n and count_final[i] != count_init[i]:
			pos_min += 1
	print n,l,init,final
	print count_final, count_init,pos_min
	changed = 0

	min_changed = l+1
	visit(0)	
	if min_changed == l+1:
		print >>fo,"Case #%d: NOT POSSIBLE"%(test+1)
	else:
		print >>fo,"Case #%d: %d"%(test+1,min_changed)


