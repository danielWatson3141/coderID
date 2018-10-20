# drummer2322
# corbin.mc96@gmail.com
# GCJ 2014 1A
# 25 Apr 2014

from sys import argv

if len(argv) > 1:
	type_of_case = argv[1]+'_'
else:
	type_of_case = ''

lines = [line.strip() for line in open(type_of_case+'input.in')];
output = open(type_of_case+'output.out','w')


def switching_pattern_for(outlet, device):
	# print "outlet", outlet
	# print "device", device
	result=[]
	for i in range(len(outlet)):
		if outlet[i] == device[i]:
			result.append("0")
		else:
			result.append("1")
	# print result
	return result

def apply_switching_pattern(outlet, switching_pattern):
	result=[]
	for i, letter in enumerate(switching_pattern):
		if letter == "0":
			result.append(outlet[i])
		else:
			if outlet[i]=="1":
				result.append("0")
			if outlet[i]=="0":
				result.append("1")
	return result

for t in range(1,int(lines.pop(0))+1):
	print t
	minimum_switches = float("inf")

	number_of_outlets, number_of_switches = map(int,lines.pop(0).split())
	outlets = map(list, map(str,lines.pop(0).split()))
	devices = map(list, map(str,lines.pop(0).split()))

	for i, device in enumerate(devices):
		switching_pattern = switching_pattern_for(outlets[0],device)

		if switching_pattern.count("1")>=minimum_switches:
			# print "line 53"
			continue
		for j, outlet in enumerate(outlets):
			print "switching_pattern", switching_pattern
			print "outlet", outlet
			print apply_switching_pattern(outlet,switching_pattern)
			if apply_switching_pattern(outlet,switching_pattern) in devices:
				continue
			else:
				break
		else:
			minimum_switches = switching_pattern.count("1")



	if minimum_switches == float("inf"):
		minimum_switches = "NOT POSSIBLE"

	output.write("Case #%i: %s\n"%(t, minimum_switches ))

output.close()