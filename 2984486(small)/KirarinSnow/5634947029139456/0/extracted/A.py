#!/usr/bin/env python
#
# Problem: Charging Chaos
# Language: Python
# Author: KirarinSnow
# Usage: python thisfile.py <input.in >output.out


for case in range(int(raw_input())):
    n, l = map(int, raw_input().split())
    o = map(lambda x: eval("0b"+x), raw_input().split())
    d = map(lambda x: eval("0b"+x), raw_input().split())
    
    ans = 0
    for i in range(l)[::-1]:
        x = []
        y = []
        z = []
        for j in range(n):
            x.append(o[j] >> i)
            y.append((o[j] >> i)^1)
            z.append(d[j] >> i)
        x.sort()
        y.sort()
        z.sort()
        
        if x == z or y == z:
            if y == z and x != z:
                ans += 1
        else:
            ans = "NOT POSSIBLE"
            break
        
    print "Case #%d: %s" % (case+1, ans)
