#!/usr/bin/env ruby

fin = File.open "./A-small-attempt1.in", "r"
fout = File.open "./A-small-attempt1.out", "w"

def count1 a
	sum = 0
	while a > 0
		a &= a-1
		sum += 1
	end
	sum
end

case_amount = fin.readline.to_i
(1..case_amount).each {|i|
	n, l = fin.readline.split(' ').map(&:to_i)
	b = fin.readline.split(' ').map{|x|x.to_i(2)}
	a = fin.readline.split(' ').map{|x|x.to_i(2)}
	a.sort!
	result = 100000
	for t in b
		dist = a[0] ^ t
		c = b.map{|x|x^dist}.sort
		if a == c
			count = count1 dist
			if count < result
				result = count
			end
		end
	end
	if result == 100000
		result = 'NOT POSSIBLE'
	end

	fout.printf "Case ##{i}: %s\n", result
}

fin.close
fout.close
