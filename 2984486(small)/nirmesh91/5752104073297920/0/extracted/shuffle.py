T = int(input())
for x in range(0,T):
    N = int(input())
    inp = [int(y) for y in input().split(' ')]
    flag = 0
    for i in range(0,len(inp)):
        if inp[i] < i:
            flag = 1
            break

    if flag == 0:
        print('Case #' + str(x+1) + ': ' + 'BAD')
    else:
        print('Case #' + str(x+1) + ': ' + 'GOOD' )