require 'pp'

PATH = 'a_'
case 1
when 0 then filepath = PATH + 'input_sample.txt'
when 1 then filepath = PATH + 'input_small.txt'
when 2 then filepath = PATH + 'input_large.txt'
end

def switch(n)
  if n == "1"
    "0"
  else
    "1"
  end
end

open(filepath) do |file|
  test_case_size = file.gets.to_i
  test_case_size.times do |problem_num|
    n, l = file.gets.split(/\s/).map(&:to_i)
    switches_orig = file.gets.split(/\s/)
    devices       = file.gets.split(/\s/)
    devices.sort!

    ans = l+1

    (2**l).times do |i|
      flags = "%0#{l}d" % i.to_s(2)
      switches = Marshal.load(Marshal.dump(switches_orig))
      count = 0

      flags.split(//).each_with_index do |f,i|
        if f == "1"
          switches.each do |s|
            s[i] = switch(s[i])
          end
          count +=1
        end
      end

      if switches.sort == devices
        ans = [ans, count].min
      end
    end

    if ans==l+1
      print "Case ##{problem_num+1}: NOT POSSIBLE\n"
    else
      print "Case ##{problem_num+1}: #{ans}\n"
    end
  end
end


