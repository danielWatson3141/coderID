
def xor(a,b):
    c = []
    for i in range(len(a)):
        if a[i] == b[i]:
            c.append(0)
        else:
            c.append(1)
    return c

def do_case(case, rfile, wfile):
    inp = map(int, rfile.readline().strip().split(' '))
    N = inp[0]
    L = inp[1]
    prod = rfile.readline().strip().split(' ')
    outlet = rfile.readline().strip().split(' ')
    for i in range(N):
        prod[i] = map(int, list(prod[i]))
        outlet[i] = map(int, list(outlet[i]))

    if N == 1:
        c = xor(prod[0], outlet[0])
        mini = sum(c)
    else:
        a = [0]*L
        b = [0]*L
        for i in range(N):
            a = xor(a,prod[i])
            b = xor(b,outlet[i])
        '''if not((sum(a) == 0) or (sum(a) == L)):
            mini = -1
        else:
            mini = sum(xor(a,b))'''
        c = sum(xor(a,b))
        if c%2 == N%2:
            mini = -1
        else:
            mini = c


    #print to file
    if not mini == -1:
        wfile.write('Case #'+str(case)+': '+str(mini)+'\n')
    else:
        wfile.write('Case #'+str(case)+': NOT POSSIBLE\n')

def main():
    #open files
    rfile = file('Q1small.in', 'r')
    wfile = file('Q1small.out', 'w')

    num_of_cases = int(rfile.readline().strip())

    for case in range(num_of_cases):
        print case+1
        do_case(case+1, rfile, wfile)

if __name__ == '__main__':
    main()