#!/usr/bin/env ruby

require 'pp'

def del(a, i)
  a[i].each do |j|
    a[j].delete(i)
  end
  a[i] = []
end

def bcheck(a, c, i, j)
  c[i] = true
  b = a[i]
  case b.size
  when 0 # root
    return i == j
  when 1
    return false if i == j
    return b[0] == j
  when 2 # root
    return false unless i == j
    return bcheck(a, c, b[0], i) && bcheck(a, c, b[1], i)
  when 3
    return false if i == j
    return (b[0] == j || bcheck(a, c, b[0], i)) &&
           (b[1] == j || bcheck(a, c, b[1], i)) &&
           (b[2] == j || bcheck(a, c, b[2], i))
  else
    return false
  end
end

def check(a, c)
  # puts "check: #{a.inspect}"
  a.size.times do |i|
    next if c[i]
    d = c.dup
    return d.reduce(&:&) if bcheck(a, d, i, i)
  end
  return false
end

gets.to_i.times do |i|
  n, = gets.chomp.split.map(&:to_i)

  a = Array.new(n).map{[].dup}
  (n-1).times do
    x, y = gets.chomp.split.map{|z|z.to_i-1}
    a[x] << y
    a[y] << x
  end

  # pp a
  m = n
  (0...(1<<n)).each do |s|
    w = s
    b = a.map(&:dup)
    c = Array.new(n, false)
    d = 0
    (0...n).each do |t|
      if (s&1 == 1)
        del(b, t)
        c[t] = true
        d += 1
      end
      s >>= 1
    end
    # puts "#{w}: #{c.inspect} #{b.inspect}"
    m = d if d < m && check(b, c)
  end

  puts "Case ##{i+1}: #{m}"
end
