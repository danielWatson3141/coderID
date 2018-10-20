def gets
  STDIN.gets.strip
end

def changes(switches, target, i, j, n)
  # puts "s = #{switches.inspect}, i = #{i}, j =#{j}, n = #{n}"
  if switches.map { |e| e.to_i(2) }.sort == target.map { |e| e.to_i(2) }.sort
    return n
  end
  if i >= j
    return j
  end
  invert = switches.map { |e|
    p = (e[i] == "0" ? "1" : "0");
    if i == 0
      p + e[(i + 1)..-1]
    else
      e[0..(i - 1)] + p + e[(i + 1)..-1]
    end
  }
  # p switches
  # p invert
  # puts "--"
  [
    changes(invert, target, i + 1, j, n == j + 1 ? 1 : (n + 1)),
    changes(switches, target, i + 1, j, n)
  ].min
end

n = gets.to_i
n.times do |i|
  print "Case ##{i + 1}: "

  # puts
   outlets = gets.split(" ").map(&:to_i)
   switches = gets.split(" ") #.map { |e| e.to_i(2) }.sort
   target = gets.split(" ") #.map { |e| e.to_i(2) }.sort

  result = changes(switches, target, 0, outlets[1], 0)
  if (result == outlets[1])
    puts "NOT POSSIBLE"
  else
    puts result
  end
end