import copy

def main():
    T = int(input())

    for T in range(T):
        N,L = (int(x) for x in input().split())
        print("Case #{}: {}".format(T+1, solve(N, L)))
        
def solve(N, L):
    original = [list(map(lambda ins: True if ins is '1' else False, x)) for x in input().split()]
    desire = set(tuple(map(lambda ins: True if ins is '1' else False, x)) for x in input().split())

    ans = lolwut(0, original, L, desire, 0)
    if ans  >= 9999999:
        return "NOT POSSIBLE"
    else:
        return ans

def lolwut(i, curr, L, desire, flips):
    if i is L:
        result = set(tuple(x) for x in curr)
        if result == desire:
            return flips
        else:
            return 9999999
    else:
        noflip = copy.deepcopy(curr)
        flip = copy.deepcopy(curr)

        for switches in flip:
            switches[i] = not switches[i]
        return min(lolwut(i + 1, flip, L, desire, flips + 1), lolwut(i + 1, noflip, L, desire, flips))
                   
    
def printOut(out):
    for line in out:
        print(line)
    
if __name__ == '__main__':
    main()
