oufile = open('out.txt', 'w')
import itertools

def check(x, y):
    return 

def search(L, start, required):
    for i in xrange(0, L + 1):
        for c in itertools.combinations(xrange(L), i):
            end = []
            for x in start:
                x_list = list(x)
                for index in c:
                    x_list[index] = '1' if  x_list[index] == '0' else '0'
                new_x = ''.join(x_list)
                end.append(new_x)
            ok = sorted(end) == sorted(required)
            if ok:
                oufile.write(str(i) + '\n')                
                return True
    return False
                
with open('A-small-attempt1.in') as infile:
    T = int(infile.readline())
    for i in range(0,T):
        oufile.write('Case #' + str(i + 1) + ': ')
        N, L = (int(x) for x in infile.readline().split(' '))
        start = infile.readline().strip().split(' ')
        required = infile.readline().strip().split(' ')
        if not search(L, start, required):
            oufile.write('NOT POSSIBLE\n')
        
        
        
                    
                        
                    
        
                