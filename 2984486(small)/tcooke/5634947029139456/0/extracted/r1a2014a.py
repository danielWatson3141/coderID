# Written in Python 3.3

import math
import sys

def findsol(F,D,N,L):

    # Define each of the switches

    S = []
    for i in range(L):
        S.append(0)

    # Set the first device in each of the ports in turn, and
    # determine the required switching

    minswitch = L+1
    for i in range(N):
        numswitch = 0
        for j in range(L):
            if not(F[i][j] == D[0][j]):
                S[j] = 1
                numswitch += 1
            else:
                S[j] = 0

        # Only consider if we have a potentially better solution

        if (numswitch >= minswitch):
            continue

        # Apply this switch setting to the other ports, and check
        # if a device can fit it

        allmatch = 1
        for k in range(N):
            if k==i:
                continue

            # Calculate the new flow from this port
            
            tmp = list(F[k])
            for j in range(L):
                if S[j]==1:
                    if tmp[j]=='0':
                        tmp[j]='1'
                    else:
                        tmp[j]='0'
            tmp = "".join(tmp)

            # Check if there is a matching device

            match = 0
            for k in range(N):
                if (D[k] == tmp):
                    match = 1
                    break

            if (match==0):
                allmatch = 0
                break

        # If they all matched, pick the best solution

        if (allmatch==1):
            minswitch = numswitch

    if (minswitch <= L):
        return str(minswitch)

    return 'NOT POSSIBLE'

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

def getpatterns(P,N,L):
    patterns = []
    idx = 0
    for i in range(N):
        tmp = ''
        for j in range(L):
            tmp += P[idx]
            idx += 1
        idx += 1
        patterns.append(tmp)
    return patterns
              
      
# The main code section

fidi = open('A-small-attempt0.in','r')
fido = open('a.out','w')

T = fidi.readline()
T = int(T)

for ii in range(1,T+1):
    tmp = fidi.readline()
    tmp = convertnums(tmp)
    N = tmp[0]
    L = tmp[1]

    F = fidi.readline()
    flow = getpatterns(F,N,L)

    D = fidi.readline()
    devices = getpatterns(D,N,L)

    # Find the solution

    a = findsol(flow,devices,N,L)

    # Show the output

    fido.write('Case #' + str(ii)+': '+ a +'\n')
    print('Case #',str(ii),': ',a)

fidi.close()
fido.close()



