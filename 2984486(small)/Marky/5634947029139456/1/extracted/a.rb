for t in 1..gets.to_i
	n, l = gets.split.map &:to_i
	outlets = gets.split.map{|i| i.to_i 2}
	devices = gets.split.map{|i| i.to_i 2}
	mf = l+1 # minflips
	for dev in devices
		flips = outlets[0] ^ dev
		flipout = outlets.map{|out| out^flips}
		for d2 in devices
			if flipout.include? d2
				flipout.delete d2
			else break;
			end
		end
		next if not flipout.empty?
		mf = [mf, (flips.to_s 2).count('1')].min
	end
	print "Case ##{t}: "
	puts (mf>l ? "NOT POSSIBLE" : mf)
end