#!/usr/bin/ruby

n = STDIN.gets.to_i

for i in 1..n
  answer = 'NOT POSSIBLE'
  min_answer = 2 ** 40 # dummy
  values = STDIN.gets.split( ' ' )
  n = values[0].to_i
  l = values[1].to_i

  outlets = STDIN.gets.split( ' ' )
  devices = STDIN.gets.split( ' ' )

  for k in 0..devices.size - 1
    # fits to devices[k]
    for p in 0..outlets.size - 1
      temp_answer = ''
      for m in 0..outlets[p].length - 1
        if outlets[p][m] == devices[k][m]
          temp_answer += '0'
        else
          temp_answer += '1'
        end
      end

      # fits devices[k] to outlets[p]
      # p 'd[' + k.to_s + '] to o[' + p.to_s + '] : ' + temp_answer

      # check is it possible for temp_answer
      wrong_flag = false
      temp_outlets = Array.new
      for ox in 0..outlets.size - 1
        temp_outlets.push( outlets[ox].to_i(2) ^ temp_answer.to_i(2) )
      end

      for dx in 0..devices.size - 1
        idx = temp_outlets.index( devices[dx].to_i(2) )
        if idx
          temp_outlets[idx] = 'USED' # dummy used flag
        else
          wrong_flag = true
          break
        end
      end

      if wrong_flag == false
        switch_count = 0
        temp_answer.split( '' ).each do |c|
          switch_count += 1 if c == '1'
        end
        if min_answer > switch_count
          min_answer = switch_count
          answer = switch_count.to_s
        end
      end

    end
  end

  puts 'Case #' + i.to_s + ': ' + answer

end


