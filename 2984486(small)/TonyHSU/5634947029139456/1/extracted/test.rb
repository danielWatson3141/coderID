INF = 10000000

case_n = gets.chomp.to_i

def oppo(c)
	if c == "0"
		"1"
	elsif c == "1"
		"0"
	end
end
def sol(given, target, n, length)
	min = INF
	(0...n).each do |i|
		# choose a row and try match target[0]
		this_one = []
		given.each do |s|
			this_one << s.dup
		end
		times = 0
		(0...length).each do |c|
			if target[0][c] != this_one[i][c]
				times += 1

				# change all this_one[k][c]
				(0...n).each do |j|
					this_one[j][c] = oppo(this_one[j][c])
				end
			end
		end

		# check whether its OK
		if target.sort == this_one.sort && min > times
			min = times
		end
	end
	if min == INF
		return "NOT POSSIBLE"
	else
		return min
	end
end

(1..case_n).each do |i|
	n, length = gets.chomp.split.map{|t| t.to_i}

	given = gets.chomp.split
	target = gets.chomp.split
	print "Case ##{i}: #{sol(given, target, n, length)}\n"

end
