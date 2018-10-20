# Copyright 2014 Mitchell Kember. Subject to the MIT License.
# Google Code Jam Round 1A 2014
# Problem A: Charging Chaos

function nflips(l, aes, res)
	least = 9999999
	for i = 0:2^l-1
		xa = map(a -> a $ i, aes)
		if match(xa, res)
			no = nones(i)
			if no < least
				least = no
			end
		end
	end
	if least != 9999999
		return least
	end
end

function nones(n)
	c = 0
	while n != 0
		c += 1
		n &= (n - 1)
	end
	c
end

function match(l1, l2)
	for a in l1
		if !in(a, l2)
			return false
		end
	end
	true
end

function message(n)
	if n === nothing
		"NOT POSSIBLE"
	else
		n
	end
end

function parselist(l)
	xs = Array(Int, length(l))
	for i = 1:length(l)
		xs[i] = parseint(l[i], 2)
	end
	xs
end

function main()
	n = int(readline())
	for i = 1:n
		_, l = int(split(readline()))
		aes = parselist(split(readline()))
		res = parselist(split(readline()))
		a = nflips(l, aes, res)
		println("Case #$i: ", message(a))
	end
end

main()
