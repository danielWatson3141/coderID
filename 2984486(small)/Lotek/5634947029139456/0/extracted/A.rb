#!/usr/bin/env ruby
T = gets.to_i
T.times do |t|
  print "Case ##{t+1}: "
  n, l = gets.split.map(&:to_i)
  outlets = gets.split
  devices = gets.split
  xor_table = Array.new(n){Array.new(n)}
  n.times do |i|
    n.times do |j|
      xor_table[i][j] = outlets[i].unpack("C*").zip(devices[j].unpack("C*")).map{|a,b|a^b}.join
    end
  end
  possible = xor_table[0]
  n.times do |i|
    possible = possible & xor_table[i]
  end
  if possible.empty?
    puts "NOT POSSIBLE"
    next
  end
  min = l
  possible.each do |p|
    index = []
    xor_table.each do |x|
      index << x.index(p)
    end
    if index.length == index.uniq.length
      min = [min, p.split('').count("1")].min
    end
  end
  puts "#{min}"
end
