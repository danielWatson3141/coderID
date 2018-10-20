from __future__ import division
import sys
import copy

def isPerm(x1,x2):
    for x in x1:
        if not x in x2:
            return False
    return True


def flip(list2,index):
    list1 = copy.deepcopy(list2)
    for i in xrange(0,len(list1)):
        if list1[i][index] == 0:
            list1[i][index] = 1
        elif list1[i][index] == 1:
            list1[i][index] = 0
    return list1

def subsets(my_set):
    result = [[]]
    for x in my_set:
        result = result + [y + [x] for y in result]
    return sorted(result,key=lambda x: len(x))


def main():
    file = open(sys.argv[1], 'r')
    T = int(file.readline().strip())
    
    for trial in xrange(1,T+1):
        sys.stdout.write("Case #%d: " % trial)
        
        data = file.readline().strip().split()
        N = int(data[0])
        L = int(data[1])
        
        init_data = file.readline().strip().split()
        req_data = file.readline().strip().split()
        
        init_flow = []
        req_flow = []
        for i in xrange(0,N):
            init_flow.append([])
            req_flow.append([])
            for j in xrange(0,L):
                init_flow[i].append(int(init_data[i][j]))
                req_flow[i].append(int(req_data[i][j]))
        
        setL = [i for i in xrange(0,L)]
        subsetsL = subsets(setL)
        #print subsetsL
        
        possible = False
        for subset in subsetsL:
            init_flipped = copy.deepcopy(init_flow)
            for i in subset:
                init_flipped = flip(init_flipped,i)
            if isPerm(init_flipped, req_flow):
                possible = True
                sys.stdout.write("%d\n" % len(subset))
                break
        
        if possible == False:
            sys.stdout.write("NOT POSSIBLE\n")
            
        """
        
                
        init_sum = []
        req_sum = []
        
        for i in xrange(0,L):
            init_sum.append(0)
            req_sum.append(0)
            for j in xrange(0,N):
                init_sum[i] += int(init_flow[j][i])
                req_sum[i] += int(req_flow[j][i])
        
        flip_count = 0
        possible = True
        for i in xrange(0,L):
            if init_sum[i] != req_sum[i]:
                if init_sum[i] + req_sum[i] == N:
                    flip_count += 1
                else:
                    possible = False
                    break
                    
                    
        if possible:
            sys.stdout.write("%d\n" % flip_count)
        else:
            sys.stdout.write("NOT POSSIBLE\n")
        """

if __name__ == '__main__':
    main()