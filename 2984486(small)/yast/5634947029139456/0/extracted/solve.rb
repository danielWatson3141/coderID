filename = "./A-small-attempt4.in"
#filename = "./input.txt"

outputfile = "output.txt"
#outputfile = "output2.txt"


def numofbits1(bits)
  num = 0
  mask = 1
  while(mask != 0) do
    break if 1 << 31  == mask
    num += 1 if (bits & mask) != 0
    mask <<= 1
  end
  num
end

def isSolve(ini, dev)

  dev.each{|d|
    if !ini.include?(d)
      return false
    end
  }

  return true

end

def solve(num, length, initial, devices)

  ini = []
  devs = []

  initial.each{|i|
    ini.push(("0b" + i).oct)
  }
  devices.each{|d|
    devs.push(("0b" + d).oct)
  }

  ini = ini.sort
  devs = devs.sort
  patterns = 0..(2**length)-1

  answer = 100000000

  patterns.each{|x|

    if isSolve(ini.map {|item| item ^ x }, devs)
      count = numofbits1(x)
      if count < answer
        answer = count
      end
    end
  }

  if answer == 100000000
    return "NOT POSSIBLE"
  else
    return answer
  end
end

ll = []

open(filename){|f|
  while l = f.gets
    ll.push(l)
  end
}

numOfTest = ll[0].to_i

inputs = []

open(outputfile, "w"){|f|

  for i in 0..(numOfTest-1)
    offset = i * 3
    num = ll[offset+1].split(' ')[0].to_i
    length = ll[offset+1].split(' ')[1].to_i

    initial =ll[offset+2].split(' ')
    devices =ll[offset+3].split(' ')


    result = "Case ##{i+1}: #{solve(num, length, initial, devices)}"
    puts result
    f.write(result + "\n")
  end

}
