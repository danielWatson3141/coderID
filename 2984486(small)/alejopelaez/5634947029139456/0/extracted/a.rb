require 'set'

t = gets.to_i
1.upto(t) do |i|
  ans = "NOT POSSIBLE"

  n, l = gets.split(" ").map(&:to_i)

  pow = gets.split(" ")
  dev = gets.split(" ")

  nums = (0..l-1).to_a
  arr = []
  for j in 0..(nums.length) do
    arr = arr + nums.combination(j).to_a
  end

  arr.each do |subset|
    tmp = []
    pow.each do |e|
      tmp << e.dup
    end


    subset.each do |j|
      tmp.each do |e|
        if e[j] == '0'
          e[j] = '1'
        else
          e[j] = '0'
        end
      end
    end

    if(tmp.to_set == dev.to_set)
      ans = subset.size
      break
    end
  end

  puts "Case ##{i}: #{ans}"
end
