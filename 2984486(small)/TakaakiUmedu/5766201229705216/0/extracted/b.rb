T = gets.to_i

def get_v(tree)
	tree.each_with_index{|line, i|
		if line.any?{|v2| v2}
			return i
		end
	}
	return nil
end

$nums_table = {}
def get_v_nums(n)
	if table = $nums_table[n]
		return table
	end
	i = 1
	while i <= n + 1
		if i == n + 1
			return $nums_table[n] = [(n + 1) / 2, n - (n + 1) / 2 - 1]
		else
			i *= 2
		end
	end
	nil
end

def is_binary_tree(tree, n)
#	return false unless ret = get_v_nums(n)
#	leafs, edges = ret
	
#	es = 0
#	ls = 0
	rs = 0
	tree.each{|line|
		case count = line.count{|v2| v2}
		when 3
#			es += 1
#			if es > edges
#				return false
#			end
		when 1
#			ls += 1
#			if ls > leafs
#				return false
#			end
		when 2
			rs += 1
			if rs > 1
				return false
			end
		when 0
		else
			return false
		end
	}
	if rs != 1
		return false
	end
	
	cur = get_v(tree)
	queue = [cur]
	visited = {cur => true}
	while queue.length > 0
		cur = queue.pop
		tree[cur].each_with_index{|v2, i|
			if v2 && !visited[i]
				visited[i] = true
				queue << i
			end
		}
	end
	return visited.keys.length == n
end


(1..T).each{|t|
	n = gets.to_i
	
	
	tree = (0...n).collect{[]}
	
	(0...n-1).each{
		v1, v2 = gets.strip.split(/ /).collect{|num| num.to_i}
		v1 -= 1
		v2 -= 1
		tree[v1][v2] = true
		tree[v2][v1] = true
	}
	
	patterns = (0...2**n).collect{|pattern|
		str = sprintf("%0#{n}b", pattern)
		count = 0
		bits = str.split(//).collect{|c|
			if c == '1'
				count += 1
				true
			else
				false
			end
		}
		[count, bits]
	}.sort_by{|count, bits| count}
	
	found = n - 1
	patterns.each{|count, bits|
		if count >= n - 1
			break
		end
		tree_tmp = tree.collect{|line| line.clone}
		bits.each_with_index{|flag, i|
			if flag
				tree_tmp.each{|line|
					line[i] = false
				}
				tree_tmp[i] = []
			end
		}
#p [bits, tree_tmp]
		if is_binary_tree(tree_tmp, n - count)
			found = count
			break
		end
	}
	
	puts "Case \##{t}: #{found}"
	
}



