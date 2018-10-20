#!/usr/bin/env ruby

require 'pp'

gets.to_i.times do |i|
  n, l = gets.chomp.split.map(&:to_i)
  o = gets.chomp.split
  d = gets.chomp.split.sort

  m = l
  (0...(1<<l)).each do |s|
    c = 0
    q = o.map(&:dup)
    (0...l).each do |t|
      if (s&1 == 1)
        q.map! do |a|
          a[t] = a[t] == "0" ? "1" : "0"
          a
        end
        c += 1
      end
      s >>= 1
    end
    m = c if q.sort == d && c < m
  end

  puts "Case ##{i+1}: #{m == l ? "NOT POSSIBLE" : m}"
end
