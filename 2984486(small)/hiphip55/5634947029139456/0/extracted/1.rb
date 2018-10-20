n = gets.to_i
ans = []
n.times do |i|
	bool = false
	x,y = gets.split.map(&:to_i)
	a = gets.split.map{|z| z.to_i(2)}
	b = gets.split.map{|z| z.to_i(2)}
	data = (0..(2**y-1)).to_a.sort_by{|z| (z.to_s(2)).count("1")}
	data.each do |z|
		c = a.dup
		c = c.map{|zz| zz ^ z}
		if c.sort == b.sort
			bool = true
			ans.push(z.to_s(2).count("1"))
			break
		end
	end
	if bool == false
		ans.push("NOT POSSIBLE")
	end
end
n.times do |i|
	puts "Case ##{i+1}: #{ans[i]}"
end