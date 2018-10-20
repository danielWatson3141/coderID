input = File.open('c.in', 'r')
output = File.new('c.out', 'w')

t = input.gets.to_i
s = []
sum = 0
for x in 1..t
  n = input.gets.to_i
  perm = input.gets.split.map {|i| i.to_i}
  op = 0
  for i in 0...n
    for j in (i+1)...n
      op += 1 if perm[i] < perm[j]
    end
  end
  s << op
end

mid = s.sort[t/2-1]

for x in 1..t
  if s[x-1] > mid
    output.puts "Case ##{x}: BAD"
  else
    output.puts "Case ##{x}: GOOD"
  end
end

input.close
output.close