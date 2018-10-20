#!/usr/bin/ruby

n = STDIN.gets.to_i

ag = Hash.new
ag['GOOD'] = 0
ag['BAD'] = 0

for i in 1..n
  answer = 'GOOD'
  c = STDIN.gets.to_i
  arr = STDIN.gets.split( ' ' )
  for k in 0..c-1
    arr[k] = arr[k].to_i
  end

  #p arr[0,10].inject(:+)
  chk = arr[0,10].inject( :+ )
  if chk <= 4900
    answer = 'BAD'
  else
    answer = 'GOOD'
  end
  ag[answer] += 1

  puts 'Case #' + i.to_s + ': ' + answer

end

