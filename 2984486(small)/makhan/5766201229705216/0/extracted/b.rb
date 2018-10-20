def count_children(node, edges)
  e = edges[node]
  e.each{|n| edges[n].delete(node)}
  result = 1
  e.each{|n| result += count_children(n,edges)}
  e.each{|n| edges[n] << node}
  return result
end

def root(node, edges)
  if edges[node].length == 0
    return 0
  elsif edges[node].length == 2
    a,b = edges[node]
    edges[a].delete(node)
    edges[b].delete(node)
    result = root(a, edges) + root(b, edges)
    edges[a] << node
    edges[b] << node
    return result
  elsif edges[node].length == 1
    a = edges[node][0]
    edges[a].delete(node)
    result = count_children(a, edges)
    edges[a] << node
    return result
  else
    delete_cost = {}
    fix_cost = {}
    cost_diff = {}
    edges[node].each do |n|
      edges[n].delete(node)
      delete_cost[n] = count_children(n, edges)
      fix_cost[n] = root(n, edges)
      cost_diff[n] = delete_cost[n]-fix_cost[n]
      edges[n] << node
    end

    sorted = cost_diff.sort_by{|k,v| v}.reverse
    a = sorted[0][0]
    b = sorted[1][0]

    result = sorted[2..-1].map{|k,v| v}.inject(:+)
    result += fix_cost[a] + fix_cost[b]
    return result
  end
end

def solve
  n = gets.chomp.to_i

  edges = Array.new(n+1) {Array.new(0)}
  (1..n-1).each do |i|
    a,b = gets.chomp.split.map(&:to_i)
    edges[a] << b
    edges[b] << a
  end

  result = n
  (1..n).each do |node|
    result = [result, root(node,edges)].min
  end
  return result
end

t = gets.chomp.to_i
(1..t).each do |tc|
  result = solve
  puts "Case ##{tc}: #{result}"
end
