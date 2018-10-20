
def calc(a)
	sum = 0
	a.each_with_index{|v, i|
		sum += (v - i) * (v - i)
	}
	Math.sqrt(sum / a.length)
end

T = gets.to_i
(1..T).each{|t|
	n = gets.to_i
	a = gets.strip.split(/ /).collect{|num| num.to_i}
	ave = calc(a)
	if ave < 350
		puts "Case \##{t}: BAD"
	else
		puts "Case \##{t}: GOOD"
	end
}

