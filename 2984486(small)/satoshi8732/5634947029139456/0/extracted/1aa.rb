#!/usr/bin/ruby

Num = gets.chomp!.to_i
tc = 0
Num.times do
  tc += 1

  print "Case ##{tc}: "

  nl = gets.chomp!.split
  nn = nl.shift.to_i
  ll = nl.shift.to_i

  inis = gets.chomp!.split
  ini = []
  nn.times do
    ini << inis.shift.to_i(2)
  end

  reqs = gets.chomp!.split
  req = []
  nn.times do
    req << reqs.shift.to_i(2)
  end

  onoffnum = Array.new(ll, 0)
  ini.each do |out|
    ll.times do |bit|
      if (out & 1) != 0 then
        onoffnum[bit] += 1
      end
      out >>= 1
    end
  end

  ronoffnum = Array.new(ll, 0)
  req.each do |out|
    ll.times do |bit|
      if (out & 1) != 0 then
        ronoffnum[bit] += 1
      end
      out >>= 1
    end
  end

#  p onoffnum
#  p ronoffnum

  flscan = [""]
  ronoffnum.each_with_index do |rnum, idx|
    inum = onoffnum[idx]

    if inum == rnum then
      nf0 = flscan.collect{|fls| "0" + fls}
    else
      nf0 = []
    end

    if (nn - inum) == rnum then
      nf1 = flscan.collect{|fls| "1" + fls}
    else
      nf1 = []
    end

    flscan = nf0 + nf1
    if flscan.size == 0 then
      break
    end

#    p flscan

  end

  flscan = flscan.sort_by{|fls| fls.count("1")}

  ans = "NOT POSSIBLE"

  flscan.each do |fls|
    fliped = []
    fl = fls.to_i(2)
    ini.each do |io|
      fliped << (io ^ fl)
    end

    if fliped.all?{|outlet| req.include?(outlet)} then
#p fls
      ans = fls.count("1")
      break
    end
  end

  puts ans
end
