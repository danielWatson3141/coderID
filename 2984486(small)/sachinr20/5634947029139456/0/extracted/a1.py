#f =  open('input.txt', 'r')
#a = f.read()
#print (a)
#f.close()

def hamming_distance(s1, s2):
    '''From Wikipedia'''
    #Return the Hamming distance between equal-length sequences
    if len(s1) != len(s2):
        raise ValueError("Undefined for sequences of unequal length")
    return sum(ch1 != ch2 for ch1, ch2 in zip(s1, s2))

def flip_list(list3, i):
    j = 0
    for str1 in list3:
        
        if str1[i]=='0':
            #str1[i]==1
            list3[j] = str1[:i]+'1'+str1[i+1:]
            #print("HEREE")
        if str1[i]=='1':
            #str1[i]==0
            list3[j] = str1[:i]+'0'+str1[i+1:]
        j = j+1
    #print("<<",list3,">>")
    return list3

def handle_output(caseno, N,L, list1, list2):
    if set(list1) == set(list2):
        print("COUNT:0")
        C = 0
        
    else:
        count = L+1
        for str1 in list1:
            for str2 in list2:
                list3 = list(list1)
                dist = hamming_distance(str1, str2)
                #print(dist)
                for i in range(0, L):
                    if str1[i]!=str2[i]:
                        #print("Flipping",i, list3,list1)
                        list3 = flip_list(list3, i)
                #print(str1,str2,list2, list3)
                if set(list3)==set(list2):
                    if count>dist:
                        count = dist
                        #print("DISTCHNAGE:",dist)
        if count==L+1:
            print("IMPOSSIBLE")
            C = -1
        else:
            print("COUNT:",count)
            C = count

    '''
    matches = 0
    num = list1[0]
    for elem1 in list1:
        if elem1 in list2:
            matches += 1
            num = elem1
    '''

    if C == -1:
        outstr = 'Case #' + str(caseno) + ': NOT POSSIBLE\n'
    else:
        outstr = 'Case #' + str(caseno) + ': ' + str(C) + '\n'
    with open('output.txt', 'a') as fo:
        fo.write(outstr)

with open('output.txt', 'w') as fo:
    pass

with open('input.txt') as fi:
    T = int(fi.readline())
    for t in range(1, T+1):
        line1 = fi.readline()
        [N, L]=[int(k) for k in line1.split(' ')]
        #print("N:",N,"L:", L)
        line2 = fi.readline()
        line3 = fi.readline()
        list1 = [str(k) for k in line2.split()]
        list2 = [str(k) for k in line3.split()]
        #print(list1, list2)
        handle_output(t,N,L, list1, list2)
        '''
        for i in range(1,5):
            if ans1==i:
                line1 = fi.readline()
            else:
                fi.readline()
        ans2 = int(fi.readline())
        for i in range(1,5):
            if ans2==i:
                line2 = fi.readline()
            else:
                fi.readline()
        #print(line1, "---" ,line2)
        list1 = [int(k) for k in line1.split(' ')]
        list2 = [int(k) for k in line2.split(' ')]
        #print(list1, list2)
        handle_output(t, list1, list2)
        '''
