# -*- coding: utf-8 -*-
# 2014.04.12(Sat) 08:00 JST
# Google Code Jam 2014 Qualification Round
# AOKI Taichi

#  raise "!!! SOME THING IS WRONG !!!!"

#require 'rubygems'
#require 'memoize'
#include Memoize


def does_match(outlet, device)
  ((outlet.sort) == (device.sort))
end

def ones(i)
  i.to_s(2).split("").count("1")
end

def solver(outlet, device, n, l)
  return 0   if does_match(outlet, device) 
  answer=2**(l+1) - 1
  (0...(2**l-1)).each{|i|
    if does_match(outlet.map{|e| e^i}, device) then
      answer=i if ones(i) < ones(answer)
    end
  }
  return "NOT POSSIBLE" if   answer==(2**(l+1) - 1)
  return ones(answer)
end

test_n=gets.to_i
test_n.times{|test_i|
  print "Case ##{test_i+1}: "
  n, l = gets.chomp.split(" ").map{|s|s.to_i}
  outlet = gets.chomp.split(" ").map{|s|s.to_i(2)}
  device = gets.chomp.split(" ").map{|s|s.to_i(2)}
#  p outlet.map{|i| "%0#{l}b" % i}
#  p device.map{|i| "%0#{l}b" % i}
  puts solver(outlet, device, n, l)
}
