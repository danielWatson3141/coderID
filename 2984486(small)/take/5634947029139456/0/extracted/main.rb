casecount = 0
cases = []


open( "./A-small-attempt1.in" ) {|f|
  casecount = f.gets.to_i
  casecount.times {
    c = []

    c.push(f.gets.split(' ').map{|s| s.to_i })
    c.push(f.gets.split(' ').map{|s| s })
    c.push(f.gets.split(' ').map{|s| s })

    cases.push(c)
  }
}

def check(a, b)
  a.sort == b.sort
end

def flip(a, s)
  return a if s == 0
  a.each {|c|
    b = 1
    uc = s
    while 0 != uc do
      if 0 != (uc & 0x01)
        if c[c.length - b] == '0'
          c[c.length - b] = '1'
        else
          c[c.length - b] = '0'
        end
      end
      uc = (uc >> 1)
      b += 1
    end
  }
  a
end

def bcount(uc)
  bit = 0
	while 0 != uc do
		bit += 1 if 0 != (uc & 0x01)
    uc = (uc >> 1)
	end
	bit
end

i = 0
cases.each {|c|
  i += 1
  scount = c[0][1]
  a = c[1]
  b = c[2]
  l = (2 ** scount).to_i

  t = 0
  ans = []
  l.times {
    aa = flip(Marshal.load(Marshal.dump(a)), t)
    if check(aa, b)
      ans.push(t)
    end
    t += 1
  }

  if ans.length == 0
    puts "Case ##{i}: NOT POSSIBLE"
  else
    p = 9999999999999999999
    ans.each{|f|
      p = [p,bcount(f)].min
    }
    puts "Case ##{i}: " + p.to_s
  end
}
