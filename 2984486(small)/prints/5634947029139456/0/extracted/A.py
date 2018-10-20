import sys

def program(filename):
	lines = open(filename).read().splitlines()
	f = open('results.out','w')

	num_cases = int(lines[0])
	casesize = 3
	currentline = 1
	# use this for debug prints
	debug = len(sys.argv) == 3 and sys.argv[2] == "false"

	for i in range(num_cases):
		# Format the lines for calls.
		firstrowpicked = lines[currentline].split()
		n = firstrowpicked[0]
		l = firstrowpicked[1]
		flows = lines[currentline + 1].split()
		devices = lines[currentline + 2].split()

		result = helper(n, l, flows, devices, 0, 0)
		if result == 999999999999999999999999999999999999999999999:
			answer = "NOT POSSIBLE"
		else:
			answer = str(result)
		f.write("Case #" + str(i+1) + ": " + answer + "\n")

		currentline = currentline + casesize

	f.close()

def helper(n, l, flows, devices, iteration, ans):

	devicesset = set(devices)

	if devicesset == set(flows):
		return ans

	if iteration >= int(l):
		return 999999999999999999999999999999999999999999999

	#flip
	newflows = []
	for i in range(int(n)):
		text = flows[i]
		if text[iteration] == '1':
			newflows.append(text[:iteration] + '0' + text[iteration+1:])
		else:
			newflows.append(text[:iteration] + '1' + text[iteration+1:])

	do = helper(n,l,newflows,devices,iteration+1,ans+1)


	#dont flip
	dont = helper(n,l,flows,devices,iteration+1,ans)

	return min(do, dont)

def main():
	program(sys.argv[1])

if __name__ == "__main__":
    main()
