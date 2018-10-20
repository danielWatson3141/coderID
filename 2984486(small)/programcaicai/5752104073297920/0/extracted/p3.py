from collections import deque,defaultdict
from random import randint,random
from math import exp


def SortAndCountInversions(array):
    length = len(array)  
    midpoint = length / 2
    inversions = 0

    if length == 1:
        return inversions, array

    else:
        leftInv, left = SortAndCountInversions(array[:midpoint])
        rightInv, right = SortAndCountInversions(array[midpoint:])
        inversions += (leftInv + rightInv)

        lenLeft = len(left)
        lenRight = len(right)

        j = k = 0
        mergedArray = []

        for i in range(0, length):

            if j != lenLeft and k != lenRight:
                if left[j] <= right[k]:
                    mergedArray.append(left[j])
                    j += 1

                else:
                    mergedArray.append(right[k])
                    k += 1

                    # Increment inversion count
                    if j != lenLeft:
                        inversions += lenLeft - j

            elif j == lenLeft:
                mergedArray.append(right[k])
                k += 1

            elif k == lenRight:
                mergedArray.append(left[j])
                j += 1

        return inversions, mergedArray

def inversions(seq):
	return SortAndCountInversions(seq)[0]



def GA(n):
	a = range(n)
	for k in range(n):
		p = randint(k,n-1)
		t = a[k]
		a[k] = a[p]
		a[p] = t
	return a


def BA(n):
	a = range(n)
	for k in range(n):
		p = randint(0,n-1)
		t = a[k]
		a[k] = a[p]
		a[p] = t
	return a

fin = open('C-small-attempt3.in')
fout = open('out.txt','w')

T = int(fin.readline())
casno=1

gc = 0
bc = 0
while T!=0:
	T-=1
	n = int(fin.readline())
	s = map(int,fin.readline().split())

	def out(casno,ans):
		outstr ='Case #%d: %s' % (casno,ans)
		print outstr
		fout.write(outstr+'\n')
	invs = inversions(s)
	invn = len(s) *(len(s)-1) / 4.0
	d = abs(invs - invn)

	if random()<exp(- 1.0*d /(len(s)**1.32)):
		out(casno,'GOOD')
		gc+=1
	else:
		out(casno,'BAD')
		bc+=1
	casno+=1

print gc,bc