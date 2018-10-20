#!/usr/bin/ruby -w

require 'set'

def search_centre(n, graph)
  open = Set::new
  open_next = Set::new
  closed = Set::new

  (1..n).each do |i|
    open << i if graph[i].size == 1
  end

  until open.empty?
    last = open.dup
    until open.empty?
      c = open.first
      open.delete(c)
      closed << c

      graph[c].each do |ni|
        unless closed.include? ni or open.include? ni
          open_next << ni
        end
      end
    end
    open, open_next = open_next, open
  end

  last
end

def node_count_from_centre(parent, current, n, graph, ncount = Hash::new)
  count = 0

  graph[current].select{|e| e != parent}.each do |ni|
    node_count_from_centre(current, ni, n, graph, ncount)
    count += 1 + ncount[ni]
  end

  ncount[current] = count
  ncount
end

def shear_nodes_from_centre(parent, current, n, graph, node_count)
  shear = 0

  nodes = graph[current].select{|e| e != parent}.map{|e| [e, node_count[e]]}.sort{|i, j| i[1] <=> j[1]}.reverse
  #puts "Current node: #{current}"
  #puts nodes.inspect

  if nodes.size == 1
    shear += nodes[0][1] + 1
  elsif nodes.size >= 2
    shear += nodes.drop(2).map{|e| e[1]}.reduce(0, :+)
    shear += shear_nodes_from_centre(current, nodes[0][0], n, graph, node_count)
    shear += shear_nodes_from_centre(current, nodes[1][0], n, graph, node_count)
  end

  shear
end

(1..(gets.to_i)).each do |t|
  n = gets.to_i

  graph = Array::new(n+1) { Array::new }

  (n-1).times do
    i, j = gets.split.map(&:to_i)
    graph[i] << j
    graph[j] << i
  end

  #centre = search_centre(n, graph)
  #node_count = node_count_from_centre(centre, n, graph)
  #shear = shear_nodes_from_centre(0, centre, n, graph, node_count)
  
  shear = (1..n).map do |centre|
    #puts "Going with centre: #{centre}"
    node_count = node_count_from_centre(0, centre, n, graph)
    #puts "Node counts: #{node_count.inspect}"
    shear = shear_nodes_from_centre(0, centre, n, graph, node_count)
    #puts "Shear: #{shear}"
    shear
  end.min

  puts "Case ##{t}: #{shear}"
end
