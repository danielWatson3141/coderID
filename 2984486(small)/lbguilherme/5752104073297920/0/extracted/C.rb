gets.to_i.times do |t|
    print "Case ##{t+1}: "
    sz = gets.to_i
    a = gets.strip.split(" ").map(&:to_i)
    v = 0
    for i in 0...sz
        v += 1 if a[i] >= i
    end
    g = (v <= 515*sz/1000)
    puts (g ? "GOOD" : "BAD")
end

