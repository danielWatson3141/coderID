
def xor(s,t)
  ret = s + ''
  s.length.times do |i|
    if (s[i] == '0' && t[i] == '0') || (s[i] == '1' && t[i] == '1')
      ret[i] = '0'
    else
      ret[i] = '1'
    end
  end
  ret
end
def sub(s,t)
  ret = 0
  for i in 0..63
    ret += 1 unless ((s >> i) & 1) == ((t >> i) & 1)
  end
  return ret
end
gets.to_i.times do |testCase|
  print "Case ##{testCase + 1}: "
  n, l = gets.split.map(&:to_i)
  a = gets.split.map{|a|a.to_i(2)}
  b = gets.split.map{|a|a.to_i(2)}
  ret = 999999
  cnt = 0
  a.each do |x|
    b.each do |y|
      if a.map{|a| a^x}.sort == b.map{|b| b^y}.sort
        ret = [ret, sub(x,y)].min
      end
    end
  end
  if ret == 999999
    puts "NOT POSSIBLE"
  else
    puts ret
  end
  STDOUT.flush
end
