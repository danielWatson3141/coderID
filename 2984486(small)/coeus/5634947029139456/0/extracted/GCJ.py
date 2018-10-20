import itertools

lns = open('D:/A-small-attempt0.in').readlines()
cases = int(lns[0])
lns_out = []

def getCombinations(data, n_bits, r):
    #data is the outlets
    #r is the number of combinations
    #output is the list of possbile combaination
    combs = itertools.combinations(range(n_bits), r)
    combs_list = list(combs)
    retval = [] # list of set
    for comb in combs_list:
        temp = list(data)
        ret_temp = set([])
        for datum in temp:
            datum_temp = list(datum)
            for idx in comb:
                if datum_temp[idx] == '0':
                    datum_temp[idx] = '1'
                else:
                    datum_temp[idx] = '0'
            ret_temp.add(''.join(datum_temp))
        retval.append(ret_temp)
    return retval

for c in range(cases):
    N = int(lns[c*3 + 1].strip().split(' ')[0])
    L = int(lns[c*3 + 1].strip().split(' ')[1])
    outlets = set(lns[c * 3 + 2].strip().split(' '))
    devices = set(lns[c * 3 + 3].strip().split(' '))
    
    found = False
    for i in range(L):
        if i == 0:
            if len(outlets.intersection(devices)) == N:
                lns_out.append('Case #' + str(c+1) + ': 0\n')
                found = True
                break
        else:
            xs = getCombinations(outlets, L, i)
            for x in xs:
                if len(x.intersection(devices)) == N:
                    lns_out.append('Case #' + str(c+1) + ': ' + str(i) + '\n')
                    found = True
                    break
        if found:
            break
    if not found:
        lns_out.append('Case #' + str(c+1) + ': NOT POSSIBLE\n')
f = open('D:/output.txt', 'w')
f.writelines(lns_out)
f.close()
