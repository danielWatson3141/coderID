T = gets.to_i
(1..T).each do |caso|
	(n, l) = gets.split.map(&:to_i)
	outs = gets
	devs = gets.split

	min = nil
	d1 = devs.first
	(0..n-1).each do |i|
		outs2 = outs.split
		oi = outs2[i]
		s = 0
		(0..l-1).each do |j|
			if oi[j] != d1[j]
				outs2.map!{|o| o[j] = o[j] == '0' ? '1' : '0'; o}
				s += 1
			end
		end
		
		if devs.all?{|d| outs2.include? d}
			min = s if !min || s < min
		end
	end

	puts "Case ##{caso}: #{min || 'NOT POSSIBLE'}"
end