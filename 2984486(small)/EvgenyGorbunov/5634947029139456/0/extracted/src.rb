require "bigdecimal"
case_type = "small"

f = open("input_#{case_type}.txt")
out = []

f.gets.to_i.times do |n_of_case|
	n, l = f.gets.strip.split.map{|v| v.to_i}

	cells = f.gets.strip.split 
	power = f.gets.strip.split.sort.join

	uniq_cells = {}
	uniq_cells[cells.sort.join] = true
	if power == cells.sort.join
		out << "Case ##{n_of_case+1}: 0"
	else
		i = 1
		last_iteration = [cells.clone]
		next_iteration = []
		doit = true
		correct = false
		while doit
			last_iteration.each do |arr|

				break unless doit
				l.times do |j|
					new_cells = arr.clone

					break unless doit

					new_cells.each_with_index do |el, jj|
						s = el.clone
						s[j] = s[j] == '1' ? '0' : "1"
						new_cells[jj] = s
					end

					uniq_cell = new_cells.sort.join
					if uniq_cell == power
						correct = true
						doit = false
						break
					else
						if uniq_cells[uniq_cell].nil?
							next_iteration << new_cells
							uniq_cells[uniq_cell] = true
						end
					end
				end
			end
			break unless doit
			break if next_iteration.size == 0
			last_iteration = next_iteration
			next_iteration = []

			i += 1
		end

		if correct
			out << "Case ##{n_of_case+1}: #{i}"
		else
			out << "Case ##{n_of_case+1}: NOT POSSIBLE"			
		end

	end

end

open("output_#{case_type}.txt", "w"){|f| f.write(out.join("\n"))}