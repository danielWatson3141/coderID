T = int(input())
for x in range(0,T):
    N,L = [int(y) for y in input().split(' ')]
    inp = [int(y,2) for y in input().split(' ')]
    oup = [int(y,2) for y in input().split(' ')]
    
    arr = []
    for i in inp:
        temp = []
        for j in oup:
            a = i ^ j
            temp.append(bin(a))
        arr.append(set(temp))
    #print(arr)
    b = set.intersection( *arr )
    if len(b) == 0:
        print('Case #' + str(x+1) + ': ' + 'NOT POSSIBLE')
    else:
        print('Case #' + str(x+1) + ': ' + str(min( [str(y).count('1') for y in b])) )