
input = window.loadedInput
lines = input.split('\n')
l=0
testcase = +lines[l++]

for t in [1..testcase]
	[n, trash] = lines[l++].split(/\s/)
	n = +n
	seta = for x in lines[l++].split(/\s/)
		parseInt( x, 2 )
	setb = for x in lines[l++].split(/\s/)
		parseInt( x, 2)
	
	used = []
	count = (x)->
		cnt = 0
		while x>0
			if x%2 is 1
				cnt +=1
			x = parseInt(x/2)
		return cnt
	search = (ai, s)->
		if ai is n
			return s
		if ai is 0
			found = 999999999
			for bi in [0..n-1]
				used[bi] = yes
				ret = search(ai+1, seta[ai]^setb[bi])
				used[bi] = no
				if ret >= 0
					cnt = count(ret)
					if cnt < found
						found = cnt
			if found is 999999999
				return -1
			else
				return found
		else
			for bi in [0..n-1]
				if (seta[ai] ^ setb[bi] ^ s) is 0
					used[bi] = yes
					ret = search(ai+1, s)
					used[bi] = no
					if ret >= 0
						return ret
		
			return -1
						
				
		
		
				
	foundSwitch = search(0)
	if foundSwitch is -1
		output "Case ##{t}: NOT POSSIBLE"
	else
		output "Case ##{t}: #{foundSwitch}"

	
	