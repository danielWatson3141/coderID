#!/usr/bin/env ruby

fin = File.open "./B-small-attempt0.in", "r"
fout = File.open "./B-small-attempt0.out", "w"

def ppush edge, a, b
	edge[a] << b
end
case_amount = fin.readline.to_i
(1..case_amount).each {|i|
	n = fin.readline.to_i
	edge = []
	(1..n).each { |i|edge[i]=[] }
	(n-1).times {
		a, b = fin.readline.split(' ').map(&:to_i)
		ppush edge, a, b
		ppush edge, b, a
	}

	p edge
	result = Hash.new do |hash, key|
		# key: node, prevnode
		node, prev = key
		childs = edge[node].select(&prev.method(:!=))
		if childs.length == 0
			hash[key] = [1, 0]
		elsif childs.length == 1
			childamount = hash[[childs[0], node]][0]
			hash[key] = [childamount+1, childamount]
		else
			tmp = []
			for child in childs
				tmp << hash[[child, node]]
			end
			tmp.sort_by!{|x| x[1]-x[0]}
			sumamount = tmp.map(&:first).reduce(&:+)
			hash[key] = sumamount+1, sumamount-tmp[0][0]-tmp[1][0]+tmp[0][1]+tmp[1][1]
			#p tmp#, hash[key]
			#hash[key]
		end
		puts "========#{node}, #{prev}============"
		p hash[key]
		hash[key]
	end

	min = 100000
	(1..n).each {|i|
		a = result[[i, 0]][1]
		#p i, a
		if a<min
			min = a
		end
	}

	fout.printf "Case ##{i}: %s\n", min
}

fin.close
fout.close
