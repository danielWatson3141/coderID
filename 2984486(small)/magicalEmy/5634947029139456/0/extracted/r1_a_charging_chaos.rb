# -*- coding: utf-8 -*-
# GCJ 2014 QR A. Magic Trick

test_case = gets.chomp.to_i

for t_i in 1..test_case
  n,l = gets.chomp.split(" ").map {|it| it.to_i}
  outlets = gets.chomp.split(" ").map {|it| it.to_i(2)}
  devices = gets.chomp.split(" ").map {|it| it.to_i(2)}

  ans = "NOT POSSIBLE"
  max = 2 ** l - 1
  if ((outlets - devices).empty?) then
    ans = 0
  else
    for i in 0b1..max
      temp = outlets.map {|ol|
        ol ^ i
      }
      if ((temp - devices).empty?) then
        # puts "switch #{i.to_s(2)}"
        switch = i.to_s(2).split(//)
        count = 0
        switch.each do |fl|
          if (fl == "1") then
              count = count + 1
          end
        end
        ans = count
        break
      end
    end
  end
  
  print "Case ##{t_i}: "
  puts "#{ans}"
end


