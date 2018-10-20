
def count_a(a, num, root):
    visited = [root]
    queue = [num]
    count = 0

    while(len(queue) > 0):
        head = queue[0]
        count += 1
        visited.append(head)
        for x in a[head]:
            if not (x in visited):
                queue.append(x)

        del queue[0]

    return count

def del_a(a, num, root):
    visited = [root]
    queue = [num]
    count = 0

    while(len(queue) > 0):
        head = queue[0]
        visited.append(head)
        for x in a[head]:
            if not (x in visited):
                queue.append(x)

        del queue[0]
        if (len(a[head]) > 0):
            a[head] = []
            count +=1
    return count


def find(a):
    res = 0;
    temp = []
    for ind in range(len(a)):
        if (len(a[ind]) >= 4):
            temp = []
            for x in a[ind]:
                count = count_a(a,x,ind)
                temp.append((x, count))
            
        temp.sort(key=lambda tup: tup[1]) 
        del_num = len(a[ind]) - 3
        for x in range(del_num):
            res += del_a(a, temp[x][0], ind)
       
    temp = []
    for ind in range(len(a)):
        if (len(a[ind]) == 2):
            count_1 = count_a(a, a[ind][0], ind)
            count_2 = count_a(a, a[ind][1], ind)
            if count_1 < count_2:
                temp.append((ind, a[ind][0], count_1))
            else:
                temp.append((ind, a[ind][1], count_2))
    
    temp.sort(key=lambda tup: tup[2])
    for x in range(len(temp) - 1):
        res += del_a(a, temp[x][1], temp[x][0])

    return res



def main():
    file_in = open('B-small-attempt1.in', 'r')
    file_out = open('out.txt', 'w')

    cases = int(file_in.readline())

    for case in range(cases):
        print case
        a = []
        N = int(file_in.readline())
        for i in range(N+1):
            a.append([])

        for i in range(N-1):
            line = file_in.readline().split()
            a[int(line[0])].append(int(line[1]))
            a[int(line[1])].append(int(line[0]))

        ans = find(a)
        
        file_out.write('Case #' +str(case+1) +': ' + str(ans)+ '\n')
        

    file_in.close()
    file_out.close()

main()































    
    
        
    



















