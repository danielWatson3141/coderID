#!/Library/Frameworks/Python.framework/Versions/3.3/bin/python3.3
# Codejam ID 2984486
# Run with parameter
# -p for preprocessing
# -s for small input
# -l for large input
# -m=<int> for multithreading


from GCJ import GCJ


def parse(infile):
    N, L = GCJ.readints(infile)
    a = GCJ.readstrs(infile)
    b = GCJ.readstrs(infile)
    return N, L, a, b
 

        
def solve(data):
    N, L, a, b = data
    IMP = L + 10
    
    A = [[ [int(ch) for ch in string] for string in a]]
    B = [[ [int(ch) for ch in string] for string in b]]
    
    a_cnt = [0] * L
    b_cnt = [0] * L
    
    for n in range(N):
        for pos in range(L):
            a_cnt[pos] += A[0][n][pos]
            b_cnt[pos] += B[0][n][pos]

    def calc(pos, old_As, old_Bs, change_cnt, mini):
        new_mini = IMP
        if pos == L:
            for group in range(len(old_As)):
                if len(old_As[group]) !=  len(old_Bs[group]):
                    return IMP
            return change_cnt
        else:
            new_As = []
            new_Bs = []               
            for group in range(len(old_As)):
                new_A = [[],[]]
                new_B = [[],[]]
                if len(old_As[group]) !=  len(old_Bs[group]):
                    return IMP
                for i in range(len(old_As[group])):
                    new_A[old_As[group][i][pos]].append(old_As[group][i])
                    new_B[old_Bs[group][i][pos]].append(old_Bs[group][i])
                new_As.append(new_A[0])
                new_Bs.append(new_B[0])
                new_As.append(new_A[1])
                new_Bs.append(new_B[1])
            new_mini = min(mini, calc(pos+1,new_As, new_Bs, change_cnt, mini))                    
            new_As = []
            new_Bs = []               
            for group in range(len(old_As)):
                new_A = [[],[]]
                new_B = [[],[]]
                if len(old_As[group]) !=  len(old_Bs[group]):
                    return IMP
                for i in range(len(old_As[group])):
                    new_A[old_As[group][i][pos]].append(old_As[group][i])
                    new_B[old_Bs[group][i][pos]].append(old_Bs[group][i])
                new_As.append(new_A[0])
                new_Bs.append(new_B[1])
                new_As.append(new_A[1])
                new_Bs.append(new_B[0])
        
            new_mini = min(new_mini, calc(pos+1, new_As, new_Bs, change_cnt+1, new_mini))
            return new_mini
            
                    
    res = calc(0, A, B, 0, IMP)
    if res > L:
        return "NOT POSSIBLE"
    else:
        return res
    
    
   

    
            
        
        
    


if __name__ == "__main__":
    GCJ('A', solve, parse, None).run()
