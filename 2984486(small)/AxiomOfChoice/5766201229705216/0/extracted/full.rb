def works(g, u, v, bad)
	if (bad >> v) & 1 == 1 then
		return -1
	end
	sz, tot = 1, 0
	g[v].each do |w|
		if w == u or (bad >> w) & 1 == 1 then
			next
		end
		child = works(g, v, w, bad)
		if child == -1 then
			return -1
		end
		sz += child
		tot += 1
	end
	if tot == 2 or tot == 0 then
		return sz
	end
	return -1
end

def solve()
	n = gets.to_i
	g = Array.new(n) { Array.new() }
	(n - 1).times do
		x, y = gets.split.map { |a| a.to_i - 1 }
		g[x] << y
		g[y] << x
	end

	ans = n
	(1 << n).times do |bad|
		sz = bad.to_s(2).count('1')
		n.times do |root|
			if works(g, -1, root, bad) == n - sz then
				ans = [ans, sz].min
			end
		end
	end

	return ans
end

t = gets.to_i
t.times do |i|
	puts 'Case #%d: %d' % [i + 1, solve]
end
