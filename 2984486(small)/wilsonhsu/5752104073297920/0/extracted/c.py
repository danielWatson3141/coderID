import math

def load_data(datafile):
	f = open(datafile)
	data = []
	for line in f:
		data.append([float(x) for x in line.split()])

	return data

def solve(perm, thresh, data):
	total = 0
	N = len(perm)
	for i in range(N):
		total += data[perm[i]][i]

	if total > thresh:
		return "BAD"
	else:
		return "GOOD"

def solve_all(test_id):
	inputfile = test_id + '.in'
	outputfile = test_id + '.out'
	datafile = 'data2.txt'

	f = open(inputfile)
	g = open(outputfile, 'w')

	T = int(f.readline())

	data = load_data(datafile)
	
	for i in range(T):
		N = int(f.readline())
		thresh = -N*math.log(N)

		perm = [int(x) for x in f.readline().split()]
	
		output = solve(perm, thresh, data)

		g.write("Case #{}: {}\n".format(i+1, output))

	f.close()
	g.close()

if __name__ == '__main__':
#	solve_all('sample')
#	solve_all('test')
	solve_all('C-small-attempt0')
