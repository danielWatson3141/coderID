from random import *
from fractions import *
def f(x,y):
	return x*1001 + y

def gen(n):
	a = range(0,n)
	for i in range(0,n):
		r=randint(0,n-1)
		tmp=a[r]
		a[r]=a[i]
		a[i]=tmp
	return a

def gen2(n):
	a = range(0,n)
	for i in range(0,n):
		r=randint(i,n-1)
		tmp=a[r]
		a[r]=a[i]
		a[i]=tmp
	return a

	
D={}
E={}
n=1000
t=1000
for i in range(0,n):
	for j in range(0,n):
		D[f(i,j)]=0
		E[f(i,j)]=0

for x in range(0,t):
	a=gen(n)
	b=gen2(n)
	for i in range(0,n):
		D[f(a[i],i)]+=1
		E[f(b[i],i)]+=1

tst=input()
for q in range(1,tst+1):
	n=input()
	X=map(int,raw_input().split())
	x=1; y=1
	for i in range(0,n):
		x*=D[f(X[i],i)]
		y*=E[f(X[i],i)]
	if (x>y):
		print "Case #"+str(q)+": BAD"
	else:
		print "Case #"+str(q)+": GOOD"


		
