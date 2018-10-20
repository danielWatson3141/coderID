
def xor(s,t)
  ret = ''
  s.length.times do |i|
    if (s[i] == '0' && t[i] == '0') || (s[i] == '1' && t[i] == '1')
      ret += '0'
    else
      ret += '1'
    end
  end
  ret
end
def sub(s,t)
  ret = 0
  s.length.times do |i|
    ret += 1 unless s[i] == t[i]
  end 
  return ret
end
gets.to_i.times do |testCase|
  print "Case ##{testCase + 1}: "
  n, l = gets.split.map(&:to_i)
  a = gets.split
  b = gets.split
  ret = 999999
  a.each do |x|
    b.each do |y|
      if a.map{|a| xor(a,x)}.sort == b.map{|b| xor(b,y)}.sort
        ret = [ret, sub(x,y)].min
      end
    end
  end
  if ret == 999999
    puts "NOT POSSIBLE"
  else
    puts ret
  end
end
