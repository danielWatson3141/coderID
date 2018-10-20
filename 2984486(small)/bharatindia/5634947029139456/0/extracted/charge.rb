no_of_inputs = gets.to_i
for tmp in 1..no_of_inputs
	(n,l) = gets.split.map {|i| i.to_i}
	i1=gets.split.map {|i| i.to_i(2)}
	i2=gets.split.map {|i| i.to_i(2)}
	i1 = Array.new(i1)
	i2 = Array.new(i2)

	o = Array.new(n) {Array.new(n)} 
	for t1 in 0..(n-1)
		for t2 in 0..(n-1)
			 x = i1[t1] ^ i2[t2]
			 y = x.to_s(2)
			 o[t1][t2] = y
			 #print "#{y} " 
		end
		#puts
	end
	x = Array.new
	for t3 in 0..(n-1)
		if t3 == 0
			x = o[t3]
			next
		end
		x = o[t3] & x
	end
	if x.empty?
		puts "Case ##{tmp}: NOT POSSIBLE" 
	else
		y = x.collect{|i| i.to_i}
		z = y.min
		z = z.to_s
		z=z.count('1')
		puts "Case ##{tmp}: #{z}" 
	end



end