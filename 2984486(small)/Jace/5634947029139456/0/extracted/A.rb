def display testCase, answer
	puts "Case #" << testCase.to_s << ": " << answer.to_s
end

def flip c, l
	return c.dup.map{|s| s ^ l}
end

def solve n, l, c, r
	
	best = l + 1
	
	for i in 0..("1"*l).to_i(2)
		f = flip(c, i)
		if (f - r).size == 0
			oneCount = i.to_s(2).count("1")
			if (oneCount < best)
				best = oneCount
			end
		end
	end

	if best < l + 1
		return best
	else
		return "NOT POSSIBLE"
	end
end

t = gets.chomp.to_i

for i in 1..t
	nl = gets.chomp.split(' ')
	n = nl[0].to_i
	l = nl[1].to_i

	current = gets.chomp.split(' ').map{|c| c.to_i(2)}
	require = gets.chomp.split(' ').map{|r| r.to_i(2)}

	display i, solve(n, l, current, require)
end
