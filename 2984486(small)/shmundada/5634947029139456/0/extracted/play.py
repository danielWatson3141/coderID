def solve(final, init, mem , N, L, done, steps):
    t_init = sorted(init)
    if t_init == final:
        return steps
    elif done == L:
        return False
    else:
        init_tup = (e for e in init)
        if init_tup in mem:
            return mem[init_tup]
        else:
            ans = []
            switched = []
            for config in init:
                change = "0"
                if config[done] == "0":
                    change = "1"
                if done == L-1:
                    switched.append(config[:done] + change)
                else:
                    switched.append(config[:done] + change + config[done+1:])
                            
            ans_switched = solve(final, switched , mem, N, L, done+1, steps+1)
            ans_not_switched = solve(final, init , mem, N, L, done+1, steps)
            if ans_switched:
                ans.append(ans_switched)
            if ans_not_switched:
                ans.append(ans_not_switched)
            switched = sorted(switched)
            switched_tup = (e for e in switched)
            mem[switched_tup] = ans_switched
            mem[init_tup] = ans_not_switched
            if len(ans) == 0:
                return False
            else:
                return min(ans)



    
f = open('A-small-attempt0 (3).in', 'r')
line1 = f.readline()
cases = int(line1)
for case in range(1,cases+1):
    line = f.readline()
    inp = line.split()
    N = int(inp[0])
    L = int(inp[1])
    line = f.readline()
    init = line.split()
    line = f.readline()
    final = line.split()
    final.sort()
    ans = solve(final , init , {}, N, L, 0, 0)
    if ans == False and ans is not 0:
        print "Case #"+str(case)+ ": " + "NOT POSSIBLE"
    else:
        print "Case #"+str(case)+ ": " + str(ans)
