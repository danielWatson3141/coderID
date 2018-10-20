def readt
  readline.to_i
end

def read_nl
  readline.strip.split.map(&:to_i)
end

def read_flows
  readline.strip.split
end

def report(tcase, text)
  puts "Case \##{tcase+1}: #{text}"
end

T = readt

LMAX = 12

T.times do |tcase|
  (n, l) = read_nl
  outlets = read_flows
  devices = read_flows

  lowest = LMAX
  max = (1 << l)-1
  (0..max).each do |i|
    to_switch = []
    j = 0
    while i>0
      to_switch << j if i&1 == 1
      i = i >> 1
      j += 1
    end

    outlets2 = outlets.map do |outlet|
      ret = outlet.dup
      to_switch.each do |switch|
        if ret[switch] == '1'
          ret[switch] = '0'
        else
          ret[switch] = '1'
        end
      end
      ret
    end

    if outlets2.sort == devices.sort
      lowest = to_switch.size if to_switch.size < lowest
    end
  end

  if lowest < LMAX
    report tcase, lowest
  else
    report tcase, 'NOT POSSIBLE'
  end
end