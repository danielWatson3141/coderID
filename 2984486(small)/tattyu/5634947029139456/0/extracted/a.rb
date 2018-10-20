
infile = ARGV[0]
#outfile = "#{ARGV[0]}.out"

File::open(infile){|f|
	num = f.gets.chomp.to_i
	num.times{|i|
		arg =  f.gets.chomp.split(' ')
		cnt = arg[0].to_i
		fig = arg[1].to_i
		
		input = f.gets.chomp.split(' ')
		target = f.gets.chomp.split(' ')

		input.map!{|v| "0b#{v}".oct }
		target.map!{|v| "0b#{v}".oct }

		input.sort!
		target.sort!

		bcnt = Array.new(fig)
		tbcnt = Array.new(fig)

		fnd = true
		result = 0
		n = 0
		s = 0
=begin		
		fig.times {|i|
			bit = 1<<i
			bcnt[i] = 0
			tbcnt[i] = 0
			input.each{|v| bcnt[i] += 1 if (v&bit)!=0 }
			target.each{|v| tbcnt[i] += 1 if (v&bit)==0 }
			#p "#{bcnt[i]} #{tbcnt[i]}"
			if bcnt[i] == (cnt-tbcnt[i])
					s += 1
			end
			if (bcnt[i] == tbcnt[i]) then
				result += 1
			end
			
			if (bcnt[i] != tbcnt[i]) && bcnt[i] != (cnt-tbcnt[i]) then
				result = "NOT POSSIBLE"
				break
			end
		}
=end
		if result == "NOT POSSIBLE" then
			print "Case ##{i+1}: #{result}\n"
		else
			bits = Array.new(fig)
			temp = Array.new(cnt)
			fnd = false
			fnd = true
			input.each_with_index{|v,i| 
				if v != target[i] then
					fnd = false
					break
				end
			}
			if fnd
				result = 0
			else
				succ = false
				fig.times { |i| bits[i] = i }
				(fig+1).times { |idx|
					bits.combination(idx+1).each{ |ba|
						#p ba
						bit = 0
						ba.each{|v| bit |= (1<<v) }
						#p bit
						input.each_with_index{ |v,i| temp[i] = v ^ bit }
						temp.sort!
						fnd = true
						temp.each_with_index{ |v,i| 
							if target[i] != v then
								fnd = false
								break
							end
						}
						if fnd then
							result = idx+1
							succ = true
							break
						end
					}
					if fnd then
						break
					end
				}
				result = "NOT POSSIBLE" unless succ
			end
		
			print "Case ##{i+1}: #{result}\n"
		end
	}
#=end


}




