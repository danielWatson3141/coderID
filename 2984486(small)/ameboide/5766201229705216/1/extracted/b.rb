#retorna [hijos eliminados, hijos totales]
def numdel(g, root, parent, min)
	#return [min, min] if cur >= min
	children = g[root] - [parent]
	#puts "hijos de #{root}: #{children}"
	return [0, 0] if children.count == 0

	dels = children.map do |c|
		n = numdel(g, c, root, min)
		return [min, min] if n[0] >= min
		n
	end

	#puts "#{root}: #{dels}"

	case dels.count
	when 1 then [dels[0][1]+1, dels[0][1]+1]
	when 2 then [dels[0][0]+dels[1][0], dels[0][1]+dels[1][1]+2]
	else
		dels.sort!{|a,b| (b[1]-b[0]) - (a[1]-a[0])}

		d = dels[0][0]+dels[1][0] + dels.count - 2
		dels.drop(2).each{|x| d += x[1] }
		t = dels.count
		dels.each{|x| t += x[1] }
		[d, t]
	end
end


T = gets.to_i
(1..T).each do |caso|
	#puts "\n\n\n\n\ncaso #{caso}\n\n"
	n = gets.to_i
	g = {}
	(1..n-1).each do
		(x, y) = gets.split.map(&:to_i)
		g[x] ||= []
		g[x] << y
		g[y] ||= []
		g[y] << x
	end
	#puts g

	min = n
	g.keys.each do |r| 
		#puts "\nraiz #{r}"
		x = numdel(g, r, nil, min)[0]
		#puts "resultado: #{x}"
		min = [min, x].min
	end

	puts "Case ##{caso}: #{min}"
end