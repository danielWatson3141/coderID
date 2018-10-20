T = gets.to_i


(1..T).each{|t|
	n, l = gets.strip.split(/ /).collect{|num| num.to_i}
	
#	flow = gets.strip.split(/ /).collect{|str| str.split(//).collect{|c| c == '1'}}
#	dev = gets.strip.split(/ /).collect{|str| str.split(//).collect{|c| c == '1'}}

	flow = gets.strip.split(/ /).collect{|str| [str, str.to_i(2)]}
	dev = gets.strip.split(/ /).collect{|str| [str, str.to_i(2)]}
	
	min = l + 1
	(0...2**l).each{|flips|
		flow_table = {}
		flow.each{|str, pattern|
			flow_table[pattern ^ flips] = true
		}
		if dev.all?{|str, pattern| flow_table[pattern]}
			count = sprintf("%b", flips).gsub(/0/, '').length
			if count < min
				min = count
			end
		end
	}
	if min <= l
		puts "Case \##{t}: #{min}"
	else
		puts "Case \##{t}: NOT POSSIBLE"
	end
	
}



