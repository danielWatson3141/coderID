require 'bundler'

Bundler.require(:default)

file = File.new('q1data.txt', 'r')


def permute(p, x)
  x = x.clone
  p.each_with_index do |b, i|
    if b == 1
      if x[i]== 1
        x[i] = 0
      else
        x[i] = 1
      end
    end
  end
  x
end

n = file.gets.to_i
n.times.each do |i|
  n, l = file.gets.split(' ').map(&:to_i)
  outlets =file.gets.split(' ').map { |x| x.split(//).map(&:to_i) }
  devises = file.gets.split(' ').map { |x| x.split(//).map(&:to_i) }

  notfound = true
  [0, 1].repeated_permutation(l).to_a.each do |p|
    found = true
    poutlets = outlets.map { |x| permute(p, x) }
    devises.each do |d|
      unless poutlets.include?(d)
        found =false
        break
      end
    end
    if found
      count = 0
      p.each do |x|
        count += 1 if x ==1
      end
      puts "Case ##{i+1}: #{count}"
      notfound = false
      break
    end
  end

  if notfound
    puts "Case ##{i+1}: NOT POSSIBLE"
  end
end


file.close