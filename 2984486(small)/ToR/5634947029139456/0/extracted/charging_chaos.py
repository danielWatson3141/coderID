def solve(nlist, llist):
    N = len(nlist)
    table = [[None for n in range(N)] for l in range(N)]

    for (i,n) in enumerate(nlist):
        for (j,l) in enumerate(llist):
            dif = n^l
            table[i][j] = dif

    #print(table)

    possible = set(table.pop(0))
    for row in table:
        possible = possible.intersection(row)

    #print(possible)
    if not possible:
        return "NOT POSSIBLE"
    
    #least_move = "{0:b}".format(min(possible))
    #a = sorted([x ^ min(possible) for x in nlist])
    #b = sorted(llist)
    #count = sum([1 for x in least_move if x == "1"])
    #print(count, least_move)
    possible_move = ["{0:b}".format(p) for p in possible]
    count = min([sum([1 for x in p if x == "1"]) for p in possible_move])
    
    return str(count)

def solve_bf(nlist, llist, L):
    #L = len("{0:b}".format(nlist[0]))
    change = list(range(2**L+1))

    min_move = L+1
    b = sorted(llist)
    for c in change:
        count = sum([1 for x in "{0:b}".format(c) if x == "1"])
        if count > min_move:
            continue
        a = sorted([x ^ c for x in nlist])
        if a == b:
            min_move = count

    if min_move > L:
        return "NOT POSSIBLE"
    else:
        return str(min_move)
        

def main(file):
    f = open(file)
    fout = open(file[:-2]+"out", "w")

    t = int(f.readline().strip())
    for i in range(t):
        (n, l) = tuple([int(x) for x in f.readline().split()])
        nlist = [int(x,2) for x in f.readline().split()]
        llist = [int(x,2) for x in f.readline().split()]
        result = solve_bf(nlist,llist,l)
        fout.write("Case #%d: %s\n" % (i+1, result))

    f.close()
    fout.close()

if __name__ == "__main__":
    main("A-small-attempt2.in")
    #nlist = [int(x,2) for x in "00000100 10011111 11111011 10001111 01100000 00010100 01110000 11101011".split()]
    #llist = [int(x,2) for x in "00110000 10101011 11011111 01000100 01010100 10111011 00100000 11001111".split()]
    #print(solve(nlist,llist))
    #print(solve_bf(nlist,llist,8))
