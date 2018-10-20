-- This is in Lua; http://www.lua.org

local ghost
ghost = {__index=function(t,k) t[k] = setmetatable({n=0}, ghost) return t[k] end}

local function read()
	local o = setmetatable({n=0}, ghost)
	for s in io.read():gmatch("[01]+") do
		local p = o
		for v in s:gmatch(".") do
			p, p.n = p[v], p.n + 1
		end
		p.n = p.n + 1
	end
	return o
end

local function ch(a, b, s)
	local _a, _b, _0, _1, n = {}, {}, s and "1" or "0", s and "0" or "1", 1
	for i=1,#a do
		if a[i]["1"].n > 0 then
			_a[n], _b[n], n = a[i]["1"], b[i][_1], n + 1
		end
		if a[i]["0"].n > 0 then
			_a[n], _b[n], n = a[i]["0"], b[i][_0], n + 1
		end
	end
	return _a, _b
end

local function score(a, b)
	if #a == 0 then return 0 end
	local s0, s1 = true, true
	for i=1,#a do
		local a0, a1, b0, b1 = a[i]["0"].n, a[i]["1"].n, b[i]["0"].n, b[i]["1"].n
		s0 = s0 and a1 == b1 and a0 == b0
		s1 = s1 and a1 == b0 and a0 == b1
	end
	return math.min(s0 and score(ch(a, b)) or math.huge, s1 and (1+score(ch(a,b,1))) or math.huge)
end

local function solve(NL, o, p)
	local x = score({o}, {p})
	return x == math.huge and "NOT POSSIBLE" or x
end

for i=1, io.read() do
	print("Case #" .. i .. ": " .. solve(io.read(), read(), read()))
end