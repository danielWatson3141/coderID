#!/usr/bin/env ruby

n_case = STDIN.readline.to_i

def is_match?(flow, device_flow)
  flow = flow.sort

  if device_flow == flow
    true
  else
    false
  end
end

def switch(n, initial_flow)
  initial_flow.map do |v|
    v ^ n
  end
end

i = 1
until (STDIN.eof?)
  n_devices, n_flow = STDIN.readline.split(" ").map { |v| v.to_i }
  initial_flow = STDIN.readline.split(" ").map { |v| v.to_i(2) }
  device_flow = STDIN.readline.split(" ").map { |v| v.to_i(2) }.sort!

#  print "#{n_devices} #{n_flow}\n"
#  print "#{initial_flow.inspect}\n"
#  print "#{device_flow.inspect}\n"

  max_flow = 2 ** (n_flow)
#  print "max_flow: #{max_flow}\n"
  res = max_flow + 1
#  print "Initial Flow: #{initial_flow}\n"
#  print "Device Flow: #{device_flow}\n"
  0.upto(max_flow) do |j|
#    print "Switch #{j}: #{switch(j, initial_flow).map{ |v| v.to_s(2) }}\n"
    if is_match?(switch(j, initial_flow), device_flow)
      sum = 0
      j.to_s(2).each_char { |char| sum += 1 if char == "1" }
      res = sum if sum < res
    end
  end
  res = "NOT POSSIBLE" if res > max_flow

  print "Case ##{i}: #{res}\n"
  i += 1
end
