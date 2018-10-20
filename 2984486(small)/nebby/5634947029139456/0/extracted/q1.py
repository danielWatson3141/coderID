import math
import itertools

def compare(list1, list2):
    list1.sort()
    list2.sort()
    return list1 == list2

def change(list1, num):
    for x in range(len(list1)):
        new = ''
        if(list1[x][num] == '0'):
            new = '1'
        else:
            new = '0'
        list1[x] = list1[x][0:num] + new + list1[x][num+1:len(list1[x])]

f = open('a2.in', 'r')
num = int(f.readline())
for x in range(num):
    nums = f.readline().split()
    N = int(nums[0])
    L = int(nums[1])
    initial = f.readline().split()
    required = f.readline().split()
    min_switches = L+1
    text = "NOT POSSIBLE"

    combinations = list(itertools.product([0, 1], repeat=L))

    
    for combination in combinations:
        switches = 0
        mylist = list(initial)
        for y in range(len(combination)):
            if(combination[y] == 1):
                switches+=1
                change(mylist, y)
        if (compare(list(mylist), list(required)) and switches<min_switches):
            text = str(switches)
            min_switches = switches
    print "Case #" + str(x+1) + ": " + text
