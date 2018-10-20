def flip a
  return '1' if a == '0'
  return '0'
end

def solve
  n,l = gets.chomp.split.map(&:to_i)

  outlets = gets.chomp.split
  devices = gets.chomp.split

  outlets.sort!.map!{|o| o.split('')}
  devices.sort!.map!{|d| d.split('')}

  min_moves = 1000000

  devices.each do |device|
    #create bitmap
    bitmap = []
    outlets[0].each_with_index{|o,i| bitmap << (o == device[i] ? '0' : '1')}
    moves = bitmap.map(&:to_i).inject(:+)

    #flip all outlets
    outlets.map!{|o| bitmap.each_with_index{|b,i| o[i] = flip(o[i]) if b == '1'};o}

    min_moves = [min_moves,moves].min if outlets.sort == devices
    outlets.map!{|o| bitmap.each_with_index{|b,i| o[i] = flip(o[i]) if b == '1'};o}
  end
  min_moves = 'NOT POSSIBLE' if min_moves == 1000000
  min_moves
end

t = gets.chomp.to_i
(1..t).each do |tc|
  result = solve
  puts "Case ##{tc}: #{result}"
end
