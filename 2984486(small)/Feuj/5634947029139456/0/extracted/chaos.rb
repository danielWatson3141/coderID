def solve

    file = File.open('A-small-attempt2.in', 'r')
    output = File.open('output.txt', 'w')
    tT = file.gets.to_i
    for test_case in (1..tT) do
        
        output.print "Case ##{test_case}: "
        
        n, l = file.gets.split(" ").map { |x| x.to_i}
        outlets = file.gets.split(" ").map{ |x| x.split(//).map{ |s| s.to_i} }
        devices = file.gets.split(" ").map{ |x| x.split(//).map{ |s| s.to_i} }
        
        all_switches = Array.new
        
        devices.each do |dev|
            
            curr_switches = Array.new
            outlets.each do |out|
                curr_switches << find_switch(dev, out)
            end
            
            all_switches << curr_switches
        end
        
        working_switch = []
        
        for s in (0...n)
            sel_switch = all_switches[0][s]
            possible_ind = (0...n).to_a
            possible_ind.delete(s)
            answer = is_working_switch(1, possible_ind, sel_switch, all_switches, n)
            if answer
                working_switch << answer
            end
        end
        
        puts working_switch.length
        
        if working_switch.empty?
            output.puts "NOT POSSIBLE"
            next
        end
        
        val = working_switch.map{ |s| nb_switches(s)}
        
        output.puts val.min
        
        puts "Case ##{test_case}: "
        puts "--------------------"
        all_switches.each do |row|
            row.each do |s|
                print s.join
                print " "
            end
            puts
        end
        puts
        puts working_switch[val.index(val.min)].join
        
    end

    file.close
    output.close
end

def find_switch (device, outlet)
    switch = Array.new
    for i in (0...outlet.length)
        switch << (device[i] - outlet[i] ) % 2
    end
    
    return switch
end

def nb_switches (switch)
    return switch.reduce(:+)
end

def is_working_switch (row, possible_ind, switch,  switches, n)
    if row == n
        return switch
    end
    
    indices = []
    possible_ind.each do |i|
        if switches[row][i] == switch
            indices << i
        end
    end
    
    if indices.empty?
        return false
    end
    
    indices.each do |i|
        possible_cp = Array.new(possible_ind)
        possible_cp.delete(i)
        answer = is_working_switch(row+1, possible_cp, switch, switches, n)
        if answer
            return answer
        end
    end
    
    return false

end

solve
