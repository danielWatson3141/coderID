input = window.loadedInput
lines = input.split('\n')
l=0
testcase = +lines[l++]



for t in [1..testcase]
	n = +lines[l++]
	links = []
	if n is 1
		output "Case ##{t}: 0"
		continue
	for i in [1..n-1]
		link = lines[l++].split(/\s/)
		links[+link[0]] ?= []
		links[+link[0]].push +link[1]
		
		links[+link[1]] ?= []
		links[+link[1]].push +link[0]
			

	trace = (current, from)->
		children = _.reject links[current], (x)-> x is from
		len = children.length
		if len is 0
			return 1
		else if len is 1
			return 1
		else
			candidate = []
			for j in [0..len-1]
				candidate.push trace(children[j], current)
			candidate.sort()
			return 1 + candidate[len - 2] + candidate[len - 1]
			
			
		
	maxAnser = 0
	for i in [1..n]
		k = trace(i, i)
		maxAnser = k if k > maxAnser
		
	output "Case ##{t}: #{n - maxAnser}"
	
	