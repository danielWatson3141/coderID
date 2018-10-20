input = File.open('a.in', 'r')
output = File.new('a.out', 'w')

t = input.gets.to_i
puts t
for x in 1..t
  puts x
  line1 = input.gets.split
  n = line1[0].to_i
  l = line1[1].to_i
  flow = input.gets.split
  device = input.gets.split.sort
  
  ans = nil
  device.each do |d|
    delta = []
    switch = 0
    for i in 0...l
      if flow[0][i] == d[i]
        delta << 0
      else
        delta << 1
        switch += 1
      end
    end
    temp = flow.clone
    for k in 0...n
      r = ""
      for i in 0...l
        if delta[i] == 1
          if temp[k][i] == '0'
            r += '1'
          else
            r += '0'
          end
        else
          r += temp[k][i]
        end
      end
      temp[k] = r
    end
    if temp.sort == device
      ans = switch if ans == nil or switch < ans
    end
  end
  
  if ans != nil
    output.puts "Case ##{x}: #{ans}"
  else
    output.puts "Case ##{x}: NOT POSSIBLE"
  end
end

input.close
output.close