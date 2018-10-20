require 'set'

def readt
  readline.to_i
end

def read_xy
  readline.strip.split.map(&:to_i).map {|z| z-1}
end

def report(tcase, text)
  puts "Case \##{tcase+1}: #{text}"
end

def is_tree?(deleted, degs, vert)
  return true if deleted.size+1 == degs.size

  found = false
  degs.each do |d|
    return false if d>3
    if d==2
      return false if found
      found = true
    end
  end

  return false unless found

  mark = []
  degs.size.times do
    mark << false
  end
  to_visit = [((0..(degs.size-1)).to_a-deleted).first]
  while to_visit.size>0
    v = to_visit.pop
    mark[v] = true
    vert[v].each do |x|
      to_visit << x if !mark[x] && !deleted.include?(x)
    end
  end

  mark.each_with_index do |m,i|
    return false if !m && !deleted.include?(i)
  end

  return true
end

T = readt

LMAX = 20

T.times do |tcase|
  n = readt

  vertices = []
  deg = []
  n.times do
    vertices << []
    deg << 0
  end
  (n-1).times do
    (x,y) = read_xy
    vertices[x] << y
    deg[x] += 1
    vertices[y] << x
    deg[y] += 1
  end

  # puts vertices.inspect
  # puts deg.inspect

  lowest = LMAX
  max = (1 << n)-1
  (0..max).each do |i|
    to_switch = []
    j = 0
    while i>0
      to_switch << j if i&1 == 1
      i = i >> 1
      j += 1
    end

    # puts '-'
    # puts to_switch.inspect if to_switch.size == 1

    deg2 = deg.dup
    to_switch.each do |del|
      vertices[del].each do |v|
        deg2[v] -= 1 if deg2[v] > 0
      end
      deg2[del] = 0
    end

    # puts deg2.inspect if to_switch.size == 1
    if is_tree?(to_switch, deg2, vertices)
      lowest = to_switch.size if to_switch.size < lowest
    end
  end

  report tcase, lowest
end
