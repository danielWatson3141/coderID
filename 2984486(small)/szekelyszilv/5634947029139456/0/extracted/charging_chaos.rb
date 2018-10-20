#!/usr/bin/ruby -w

def brute(d, first, flip, l, flow, devices)
  #puts "d: #{d}, first: #{first}, flip: #{flip}"
  if d == 0
    if (flow.map{|e| e ^ flip}.sort) == devices
      flip
    else
      nil
    end
  else
    (first...l).each do |i|
      sol = brute(d-1, i+1, flip | (1 << i), l, flow, devices)
      return sol if sol
    end
    return nil
  end
end

def solve_brute(l, flow, devices)
  (0..l).each do |i|
    sol = brute(i, 0, 0, l, flow, devices)
    return sol if sol
  end
  return nil
end

def solve_brute2(l, flow, devices)
  min = nil
  (0..(2**l)).each do |flip|
    if flow.map{|e| e ^ flip}.sort == devices and (min == nil || (0...l).map{|e| flip[e]}.reduce(:+) < min)
      min = flip
    end
  end
  min
end

(1..(gets.to_i)).each do |t|
  n, l = gets.split.map(&:to_i)
  flow = gets.split.map{|e| e.to_i(2)}.sort
  devices = gets.split.map{|e| e.to_i(2)}.sort

  flip = solve_brute(l, flow, devices)
  if flip
    sol = (0...l).map{|e| flip[e]}.reduce(:+)
  else
    sol = "NOT POSSIBLE"
  end

  puts "Case ##{t}: #{sol}"
end
