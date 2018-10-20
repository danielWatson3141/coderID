def match(device, flow):
    for f in flow:
        if f not in device:
            return False
    return True

def switch(flow, ptr):
    alt = []
    for f in flow:
        if (f[ptr] == '0'):
            alt.append(f[:ptr] + '1' + f[(ptr+1):])
        else:
            alt.append(f[:ptr] + '0' + f[(ptr+1):])
    return alt

def recursion(device, flow, N, L, count, ptr):
    if match(device, flow):
        return count
    elif count == L or ptr == L:
        return L + 1
    else:
        m1 = recursion(device, flow, N, L, count, ptr+1)
        m2 = recursion(device, switch(flow, ptr), N, L, count+1, ptr+1)
        
        if m1 < m2:
            return m1
        else:
            return m2

def main():
    ifile = open('a.txt', 'r')
    ofile = open('a.out', 'w')

    T = int(ifile.readline().split()[0])

    for case in range(1, T+1):
        N, L = [int(x) for x in ifile.readline().split()]
        flow = [x for x in ifile.readline().split()]
        device = [x for x in ifile.readline().split()]

        m = recursion(device, flow, N, L, 0, 0)
                                
        ofile.write('Case #%d: ' %(case))
        if (m > L):
            ofile.write('NOT POSSIBLE\n')
        else:
            ofile.write('%d\n'  %(m))
                
        

if __name__ == "__main__":
    main()
