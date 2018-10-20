
def dfs(node, last, graph)
	nbr = graph[node]
	cost_change = Array.new
	discard_all = 0
	keep_all = 0
	nbr.each do |n|
		if n != last then
			discard, keep = dfs(n, node, graph)
			discard_all += discard
			keep_all += keep
			cost_change.push(discard-keep)
		end
	end
	cost_change = cost_change.sort{ |x,y| y <=> x}
	
	if cost_change.size == 0 then
		return [1, 0]
	elsif cost_change.size == 1 then
		return [discard_all + 1, discard_all]
	else
		return [discard_all+1, discard_all - cost_change[0] - cost_change[1] ]	
	end
end

def solve(graph)
	ans = 99999
	graph.each do |key, value|
		dis, keep = dfs(key, -1, graph)
		if keep < ans then
			ans = keep
		end
	end
	return ans
end

gets.to_i.times do |nCase|
	nNode = gets.to_i
	g = Hash.new()
	nNode.times do |i| g[i] = Array.new end
	1.upto(nNode-1) do
		a, b = gets.split.map(&:to_i)
		g[a-1].push(b-1)
		g[b-1].push(a-1)
	end
	
	puts "Case ##{nCase+1}: #{solve(g)}"
end