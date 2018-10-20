require 'bundler'

Bundler.require(:default)

file = File.new('q2data.txt', 'r')

def test_root(r, nodes)
  sum = 0
  return 0 if nodes[r].nil?
  v = nodes[r].select { |x| nodes.keys.include?(x) }


  # puts "#{v.to_s}"

  if v.size > 2
    sum += v.size - 2
  elsif v.size == 1
    return delete_tree(v[0], nodes.clone)
  end
  nodes.delete(r)
  v.each do |c|
    sum += test_root(c, nodes)
  end
  sum
end


def delete_tree(r, nodes)
  v = nodes[r].select { |x| nodes.keys.include?(x) }
  return 0 if v.nil?
  # puts "v #{v} -- #{nodes[r]} -- #{nodes.keys}"
  nodes.delete(r)
  if v == 0
    0
  else
    sum = v.size
    v.each do |c|
      sum += delete_tree(c, nodes)
    end
    sum
  end
end

n = file.gets.to_i
n.times.each do |i|
  m = file.gets.to_i
  edges = []
  (m-1).times.each do
    edges << file.gets.split(' ').map(&:to_i)
  end
  nodes = {}
  m.times.each do |j|
    nodes[j+1] = []
  end
  edges.each do |e|
    nodes[e[0]] << e[1]
    nodes[e[1]] << e[0]
  end

  # puts nodes.to_s

  results = []
  (1...m+1).each do |r|
    tmp =nodes.clone
    results << test_root(r, tmp)
    # puts '-+-: ' + tmp.size.to_s
  end
  # puts results.to_s
  puts "Case ##{i+1}: #{results.min}"
end

file.close