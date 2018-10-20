varT = gets.chomp.to_i
for repeat in 1..varT
	varN, varL = gets.chomp.split.map(&:to_i)
	ls1 = gets.chomp.split
	ls2 = gets.chomp.split
	print "Case ##{repeat}: "

	suspc = varL
	minic = varL+1
	for j in 0...(2**suspc)
		lsf = Marshal.load(Marshal.dump(ls1))
		testl = []
		for k in 0...suspc
			if (2**k) & j > 0
				testl << k
			end
		end
		for p in testl
			for k in 0...lsf.size
				lsf[k][p] = (1-lsf[k][p].to_i).to_s
			end
		end
		if lsf.sort == ls2.sort
			minic = [minic, testl.size].min
		end
	end
	if minic > varL
		puts "NOT POSSIBLE"
	else puts minic end
end
