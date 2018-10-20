
def change(arr, ind):
    new_arr = []
    for x in arr:
        new_arr.append(x[:ind] + str(1 - int(x[ind])) + x[ind+1:])
    return new_arr

def find(a, b):
    s = a[0]

    min_count = 50;
    for x in b:
        count = 0
        temp = list(a)
        for ind in range(len(s)):
            if s[ind] != x[ind]:
                temp = change(temp, ind)
                count += 1
        if (set(temp) == set(b) and count < min_count):
            min_count = count
        if min_count == 0: break;

    return min_count
   

def main():
    file_in = open('A-large.in','r')
    file_out = open('out.txt', 'w')

    cases = int(file_in.readline())
    for case in range(cases):
        print case
        file_in.readline();
        a = file_in.readline().split()
        b = file_in.readline().split()
        ans = find(a, b)
        if ans == 50:
            file_out.write('Case #' + str(case+1) + ': NOT POSSIBLE' + '\n')
        else:
            file_out.write('Case #' + str(case+1) + ': ' + str(ans)+ '\n')

    
    file_in.close()
    file_out.close()



main()



























