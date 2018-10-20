T = gets.to_i


(1..T).each{|t|
	n, l = gets.strip.split(/ /).collect{|num| num.to_i}
	
#	flow = gets.strip.split(/ /).collect{|str| str.split(//).collect{|c| c == '1'}}
#	dev = gets.strip.split(/ /).collect{|str| str.split(//).collect{|c| c == '1'}}

	flow = gets.strip.split(/ /).collect{|str| [str, str.to_i(2)]}
	dev = gets.strip.split(/ /).collect{|str| [str, str.to_i(2)]}
	
	flow_total = 0
	flow.each{|str, flow_pattern|
		flow_total ^= flow_pattern
	}

	dev_total = 0
	dev_table = {}
	dev.each{|str, dev_pattern|
		dev_table[dev_pattern] = true
		dev_total ^= dev_pattern
	}
	
	if (n % 2 == 0) && flow_total != dev_total
		puts "Case \##{t}: NOT POSSIBLE"
	else
		
		cands = []
		
		dev_pattern0 = dev[0][1]
		
		cands = flow.collect{|str, flow_pattern|
			dev_pattern0 ^ flow_pattern
		}
		
		cands = cands.collect{|flip_pattern|
			pattern = sprintf("%02b", flip_pattern).split(//).collect{|c| c == '1'}
			[pattern.count(true), flip_pattern, pattern]
		}.sort_by{|count, pattern| count}

		ans = nil
		cands.each{|count, flip_pattern|
			unless flow.all?{|str, flow_pattern| dev_table[flow_pattern ^ flip_pattern]}
				next
			end
			ans = count
			break
		}

		if ans
			puts "Case \##{t}: #{ans}"
		else
			puts "Case \##{t}: NOT POSSIBLE"
		end
	end
}



