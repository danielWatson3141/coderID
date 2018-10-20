# Written in Python 3.3

import math
import random
import sys
import pickle

def findsol(C):
    # Get the number in the histogram

    Nh = 0.0
    for i in range(1000):
        Nh += hist[0][i]
    
    # Compare the histogram with the sequence

    lr = 1.0
    for i in range(1000):
        tmp = 1000 * hist[i][C[i]]/Nh
        lr *= tmp

    if (lr > 0):
        return 'GOOD'
    else:
        return 'BAD'


# Code for converting a string with lots of numbers
# separated by spaces into a list

def convertnums(s):

    a = []
    ii = 0
    for jj in range(len(s)):
        if s[jj]==' ':
            if (ii < jj):
                a.append(int(s[ii:jj]))
                ii = jj + 1
                
    a.append(int(s[ii:jj]))  # No space at end

    return a

def generateprobs():
    # Initialise

    for i in range(N):
        hist[i][i] = 1.0

    newhist=[]
    for i in range(N):
        newhist.append([])
        for j in range(N):
            newhist[i].append(0.0)

    # Get the probabilities after each of the swaps

    for i in range(N):  # Swap this value
        print(i)

        # Re-initialise

        for j in range(N):
            for k in range(N):
                newhist[j][k] = 0.0

        for j in range(N):  # Swap it with this
            for l in range(N):
                newhist[i][l] += hist[j][l] / N
                if (j==i):
                    continue
                newhist[j][l] = ((N-1)*hist[j][l] + hist[i][l]) / N

        for j in range(N):
            for k in range(N):
                hist[j][k] = newhist[j][k]

def generatehist():  # Empirical method: Don't use...

    print('Started')
    cnt = 0
    
    while (1==1):
        seq = []
        for i in range(1000):
            seq.append(i)

        # Permute using bad algorithm

        for j in range(1000):
            p = random.randrange(0,1000)
            tmp = seq[j]
            seq[j] = seq[p]
            seq[p] = tmp

        # Add to the histogram at the end

        for i in range(1000):
            hist[i][seq[i]] += 1

        cnt = cnt+1
        if (cnt % 10000)==0:
            print(cnt)

def savehist(fname):
    fid = open(fname,'wb')
    pickle.dump(hist,fid)
    fid.close()

def loadhist(fname):
    fid = open(fname,'rb')
    h = pickle.load(fid)
    fid.close()
    return h

# The main code section

N = 1000
if (1==0):
    hist = []
    for i in range(N):
        hist.append([])
        for j in range(N):
            hist[i].append(0)

    generatehist()
    savehist('hist.gen')

if (1==0):
    hist = []
    for i in range(N):
        hist.append([])
        for j in range(N):
            hist[i].append(0)
            
    generateprobs()
    savehist('hist_new.gen')
    halt()


hist = loadhist('hist.gen')

fidi = open('C-small-attempt0.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    N = fidi.readline()
    N = int(N)

    C = fidi.readline()
    C = convertnums(C)
    
    # Find the solution

    a = findsol(C)

    # Show the output

    fido.write('Case #' + str(ii)+': '+str(a)+'\n')
    print('Case #',str(ii),': ',str(a))

fidi.close()
fido.close()



