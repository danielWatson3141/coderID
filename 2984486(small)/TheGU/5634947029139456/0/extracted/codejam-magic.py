debug = True
import itertools

def change(pattern, value):
    for i,v in enumerate(pattern):
        if v == 1:
            if value[i-1] == 1:
                value[i-1] = 0
            else:
                value[i-1] = 1
    return(value)

    
with open("A-small-attempt1.in","r") as f:
    with open("out.txt","w") as o:
        count = 0
        case = int(f.readline())
        while case-count>0:
            count += 1
            result = 'NOT POSSIBLE'
            
            n,l = map(int,f.readline().split())
            print(n,l)
            current = list(map(tuple,map(list, f.readline().split())))
            need = list(map(tuple,map(list, f.readline().split())))
            print(current)
            print(need)

            switch_count = 99999

            for switch_pattern in itertools.product([0,1], repeat=l):
                new_current = []
                for value in current:
                    data = ()
                    for i,v in enumerate(switch_pattern):
                        if v == 1:
                            if value[i] == '1':
                                data += ('0',)
                            else:
                                data += ('1',)
                        else:
                            data += (value[i],)
                    new_current.append(data)

                if len(set(new_current) & set(need)) == n:
                    move = switch_pattern.count(1)
                    if move < switch_count:
                        switch_count = move
                
            if switch_count < 99999:
                result = switch_count
            
            ########################################
            # Output
            case_result = "Case #%s: %s" % (count,result)
            if debug:
                print(case_result)
            o.write(case_result+'\n')
            
        
