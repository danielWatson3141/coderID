require 'pp'

def ppd(*arg)
  if $DEBUG
    pp(*arg)
  end
end

def putsd(*arg)
  if $DEBUG
    puts(*arg)
  end
end

def ri
  readline.to_i
end

def ris
  readline.split.map do |e| e.to_i end
end

def rs
  readline.chomp
end

def rss
  readline.chomp.split
end

def rf
  readline.to_f
end

def rfs
  readline.split.map do |e| e.to_f end
end

def rws(count)
  words = []
  for i in 1 .. count
    words << readline.chomp
  end
  words
end

class Node
  def initialize(id)
    @id = id
    @children = []
  end

  attr_accessor :id
  attr_accessor :children
end

def count(node, mark)
  if mark[node.id]
    return 0
  end

  mark[node.id] = 1
  sum = 1
  node.children.each do |e|
    sum += count(e, mark)
  end

  return sum
end

def childs(node, mark)
  ret = []
  node.children.each do |e|
    if !mark[e.id]
      ret << e
    end
  end
  ret
end

def solve(node, mark)
  if mark[node.id]
    return 0
  end
ppd node.id

  mark[node.id] = 1

  if childs(node, mark).size >= 2
    min = 99999999
    childs(node, mark).combination(2) do |e|
      mark3 = mark.dup
      result = solve(e[0], mark3) + solve(e[1], mark3)

      childs(node, mark3).each do |c|
        if c != e[0] && c != e[1]
          mark2 = mark3.dup
          result += count(c, mark2)
        end
      end

      if result < min
        min = result
      end
    end
    return min
  elsif childs(node, mark).size == 0
    return 0
  else
    mark2 = mark.dup
    c = count(childs(node, mark).first, mark2)
ppd "c = #{c}"
    return c
  end
end

# main
t_start = Time.now

# 問題に応じて
cases = readline().to_i

(1 .. cases).each do |case_index|
  # readline().chomp
  # readline().split

  nodes = []
  n = ri
  for i in 1..n
    nodes << Node.new(i)
  end
  for i in 1..n-1
    x, y = ris
    nodes[x - 1].children << nodes[y - 1]
    nodes[y - 1].children << nodes[x - 1]
  end

  min = 99999999
  for i in 1..n
    root = nodes[i - 1]
    mark = Hash.new
    ret = solve(root, mark)
ppd "ret = #{ret}"
    if ret < min
      min = ret
    end
ppd "----"
  end

  puts "Case ##{case_index}: #{min}"

  # progress
  trigger = 
    if cases >= 10
      case_index % (cases / 10) == 0
    else
      true
    end

  if trigger
    STDERR.puts("case #{case_index} / #{cases}, time: #{Time.now - t_start} s")
  end
end
