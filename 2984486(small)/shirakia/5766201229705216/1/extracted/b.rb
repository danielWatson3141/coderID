require 'pp'

PATH = 'b_'
case 2
when 0 then filepath = PATH + 'input_sample.txt'
when 1 then filepath = PATH + 'input_small.txt'
when 2 then filepath = PATH + 'input_large.txt'
end

def make_rank(nodes, root)
  rank=Array.new(nodes.size)
  rank[root] = 0
  current_rank = 1
  next_children = nodes[root]
  while true
    children = next_children
    next_children = []

    children.each do |child|
      p rank
      rank[child] = current_rank
      next_children.push nodes[child]
    end
  end
  rank
end

def dfs(nodes, me, parent)
  # p [nodes, me, parent]
  children = Marshal.load(Marshal.dump(nodes[me]))
  children.delete(parent)
  if children.length == 0
    return 1
  elsif children.length == 1
    return 1
  elsif children.length == 2
    return dfs(nodes, children.first, me) + dfs(nodes, children.last, me) + 1
  else
    result = []
    children.each do |child|
      result.push dfs(nodes, child, me)
    end
    return result.sort.last(2).inject(:+) + 1
  end
end

def fun(nodes, root)
  # make_rank(nodes, root)
  nodes.length - dfs(nodes, root, -1)
end

open(filepath) do |file|
  test_case_size = file.gets.to_i
  test_case_size.times do |problem_num|
    n = file.gets.to_i
    #x = Array.new(n-1)
    #y = Array.new(n-1)

    nodes = Array.new(n)
    (n-1).times do
      x, y = file.gets.split(/ /).map{|e| e.to_i - 1}
      nodes[x] ||= []
      nodes[y] ||= []
      nodes[x].push y
      nodes[y].push x
    end

    #pp nodes
    ans = n + 1

    #n.times do |i|
    n.times do |i|
      #p ['n',i, fun(nodes,i)]
      ans = [ans, fun(nodes,i)].min
    end
    print "Case ##{problem_num+1}: #{ans}\n"
  end
end
