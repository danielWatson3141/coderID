
def flip(str, flips)
    res = ""
    str.size.times do |i|
        if flips[i] == "0"
            res << str[i]
        else
            res << (str[i] == "1" ? "0" : "1")
        end
    end
    res
end

def computeflip(str1, str2)
    res = ""
    str1.size.times do |i|
        res << (str1[i] == str2[i] ? "0" : "1")
    end
    res
end

def tryflips(out, dev)
    sol = 99999
    trieds = []
    out.each do |s1|
        dev.each do |s2|
            f = computeflip(s1, s2)
            next if trieds.include? f
            trieds << f
            nout = []
            out.each do |o|
                n = flip(o, f)
                if dev.include? n
                    nout << n 
                else                
                    break
                end 
            end
            next if nout.size != dev.size
            nout.sort!
            if nout == dev
                n = f.count("1")
                if sol > n
                    sol = n
                end
            end
        end
    end
    sol == 99999 ? "NOT POSSIBLE" : sol
end

gets.to_i.times do |t|
    print "Case ##{t+1}: "
    
    n, l = gets.split(" ").map(&:to_i)
    
    out = gets.strip.split(" ").sort
    dev = gets.strip.split(" ").sort
    
    puts tryflips(out, dev)
end
