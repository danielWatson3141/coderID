import sys

# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")



def solution(A):
    # write your code in Python 3.6
    maximum = 2
    start = 0
    current = 2
    
    fruitA = A[0]
    fruitB = A[1]
    
    
    while current < len(A):
        nowTree = A[current]
        print(nowTree)
        if nowTree == fruitA or nowTree ==fruitB:
            current+=1
            maximum = max(maximum, current-start)
            continue
        
        backCounter = current-1
        
        mRT = A[backCounter]
        
        while backCounter > start and A[backCounter]==mRT:
            backCounter -= 1
        print("back to "+str(backCounter))    
        start = backCounter+1
            
        fruitA = mRT
        fruitB = A[current]
    
    return maximum


if __name__ == '__main__':
    print(solution([1,2,1,3,4,3,5,1,2]))
