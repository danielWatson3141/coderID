T = gets.chomp.to_i
T.times do |cc|
  N = gets.chomp.split(' ').map{|c| c.to_i}
  L = N[1]
  N = N[0]
  A = gets.chomp.split(' ').map{|c| c.to_i(2)}
  B = gets.chomp.split(' ').map{|c| c.to_i(2)}
  A.sort!
  B.sort!
  # puts "#{N} #{L}"
  # puts A
  # puts B
  sol = 5555
  A.each do |c|
    B.each do |d|
      ch = c^d
      C = Array.new(B)
      # puts C
      C = C.map{|i| i^ch}.sort
      # puts "#{c} #{d} #{ch}"
      # puts C
      if A == C 
        # puts "#{c} #{d} #{ch}"
        cnt = ch.to_s(2).count('1')
        # puts cnt
        sol = [sol,cnt].min
      end
    end
  end
  if sol == 5555
    puts "Case ##{cc+1}: NOT POSSIBLE"
  else
    puts "Case ##{cc+1}: #{sol}"
  end
end
