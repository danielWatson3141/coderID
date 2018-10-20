# switches

require 'set'

T = gets.to_i

for pripad in 1..T do
	n, l = gets.chomp.split(' ').map { |e| e.to_i }
	*have = gets.chomp.split(' ').map { |e| e.to_i(2) }
	*want = gets.chomp.split(' ').map { |e| e.to_i(2) }
	# puts "in #{[n, l]} #{have} #{want}"

	want_s = Set.new want
	mx = l + 1
	for i in 0...(1 << l) do
		flipped = have.map { |e| e ^ i }
		# puts "fliped #{i} #{flipped}"
		flipped_s = Set.new flipped
		if (flipped_s == want_s) then
			ct = 0
			for k in 0...l do
				ct += 1 if i & 1 == 1
				i >>= 1
			end
			mx = ct if ct < mx
		end
	end

	if mx <= l then
		puts "Case ##{pripad}: #{mx}"
	else
		puts "Case ##{pripad}: NOT POSSIBLE"
	end
end