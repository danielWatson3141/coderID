import itertools
num_cases = int(raw_input())

for case in range(num_cases):
    num_outlets, outlet_length = [int(i) for i in raw_input().split(" ")]
    initial_flow = raw_input().split(" ")
    needed_flow = raw_input().split(" ")
    
    flipped = [False] * outlet_length
    weirdos = []
    impossible = False
    count = 0
    
    for i in range(outlet_length):
        ones_needed = 0
        ones_have = 0
        
        for needed in needed_flow:
            if needed[i] == '1':
                ones_needed += 1
        
        for have in initial_flow:
            if have[i] == '1':
                ones_have += 1
        
        zeros_have = num_outlets - ones_have
        
        if ones_needed == ones_have:
            if ones_needed == zeros_have:
                weirdos.append(i)
        else:
            if ones_needed == zeros_have:
                flipped[i] = True
                count += 1
            else:
                impossible = True
                break
    
    if impossible:
        print("Case #{}: NOT POSSIBLE".format(case+1))
        continue
    
    have = []
    for flow in initial_flow:
        actual = ""
        for i in range(len(flipped)):
            if flipped[i]:
                actual += "1" if flow[i] == "0" else "0"
            else:
                actual += flow[i]
        have.append(actual)
                
    have_copy = list(have)
                
    for flow in needed_flow:
        if flow not in have:
            break
        else:
            have.remove(flow)
    
    weirdos_p = []
    for i in range(1, len(weirdos)+1):
        weirdos_p.extend(itertools.combinations(weirdos, i))
    
    if len(have) > 0:
        for w in weirdos_p:
            have = []
            new_count = count
            f = list(flipped)
            for i in w:
                f[i] = not f[i]
                new_count += 1
                
            for flow in initial_flow:
                actual = ""
                for i in range(len(f)):
                    if f[i]:
                        actual += "1" if flow[i] == "0" else "0"
                    else:
                        actual += flow[i]
                have.append(actual)
            
            for flow in needed_flow:
                if flow not in have:
                    break
                else:
                    have.remove(flow)
            if len(have) == 0:
                count = new_count
                break
                
    
    if len(have) == 0:
        print("Case #{}: {}".format(case+1, count))
    else:
        print("Case #{}: NOT POSSIBLE".format(case+1))
            