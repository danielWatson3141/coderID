def gets
  STDIN.gets.strip
end

def connexions(edges)
  connexions = {}
  edges.each { |e| a, b = *e
  connexions[a] = connexions.has_key?(a) ? connexions[a] + 1 : 1
  connexions[b] = connexions.has_key?(b) ? connexions[b] + 1 : 1
    }
    connexions
end

def remove(edges, node)
  edges.reject { |e| e.include?(node) }
end

def remove_bugs(edges, node, c, n)
  # puts "woot"
   annexes = edges.select { |e| e.include?(node) }.flatten - [node]
   node = annexes.map { |e| [e, c[e]] }.sort_by { |e| e[1] }[0][0]
  [edges.reject { |e| e.include?(node) }, n + c[node]]
end

def analyse(edges, n)
  return n if  edges.size == 1
   edges
   c = connexions(edges)

  bugs =  c.select { |k, v| v > 3 }
  if bugs.size > 0
    return analyse(*remove_bugs(edges, bugs.keys.first, c, n))
  end

  roots =  c.select { |k, v| v == 2 }
  bugs =  c.select { |k, v| v >= 3 }.sort_by { |a| a.last }
  if roots.size == 1
    # p edges
    # puts "--"
    return n
  end
  if bugs.size > 0 && roots.size == 0
    return analyse(*remove_bugs(edges, bugs[-1].first, c, n))
  end
  todelete = roots.keys.map { |root| edges.select { |e| e.include?(root) }.flatten - [root] }.flatten.uniq
  node = todelete.map { |e| [e, c[e]] }.sort_by { |e| e[1] }[0][0]
  analyse(edges.reject { |e| e.include?(node) }, n + 1)
end

n = gets.to_i
n.times do |i|
  print "Case ##{i + 1}: "

  edges = []
  m = gets.to_i
  (m - 1).times {
    a, b = gets.split(" ").map(&:to_i)
    edges << [a, b]
  }
  puts analyse(edges, 0)
end