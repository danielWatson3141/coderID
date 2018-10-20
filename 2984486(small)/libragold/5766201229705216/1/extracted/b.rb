def solve(r, p, adj)
  scores = []
  adj[r].each do |u|
    scores << solve(u, r, adj) if u != p
  end
  if scores.length > 1
    scores.sort!
    return scores[-1] + scores[-2] + 1
  else
    return 1
  end
end

input = File.open('b.in', 'r')
output = File.new('b.out', 'w')

t = input.gets.to_i
for x in 1..t
  n = input.gets.to_i
  adj = []
  for i in 0...n
    adj[i] = []
  end
  for i in 1...n
    line = input.gets.split
    u = line[0].to_i
    v = line[1].to_i
    adj[u-1] << v-1
    adj[v-1] << u-1
  end
  ans = 0
  puts x
  for r in 0...n
    nodes = solve(r, nil, adj)
    if ans < nodes
      ans = nodes 
    end
  end
  output.puts "Case ##{x}: #{n-ans}"
end

input.close
output.close
