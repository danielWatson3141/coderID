from random import randint
def bad_shf(N):
    a = list(range(N))
    for k in range(N):
            p=randint(0,N-1)
            a[p],a[k]=a[k],a[p]
    return tuple(a)
def good_shf(N):
    a = list(range(N))
    for k in range(N):
            p=randint(k,N-1)
            a[p],a[k]=a[k],a[p]
    return tuple(a)
def score(l):
    result = 0
    for i in range(len(l)):
        result+=abs(l[i]-i)
    return result
def score_2(l):
    result = 0
    for i in range(len(l)):
        result+=int(abs(l[i]-i)<2)
    return result
def score_3(l):
    result = 0
    for i in range(len(l)):
        result+=int(l[i]==i)
    return result

def score_5(s):
    if s is None or len(s) <= 1:
        return 0

    longest = test = [s[0]]

    for i in range(1, len(s)):
        if s[i] >= s[i - 1]:
            test += [s[i]]
        else:
            if len(longest) < len(test):
                longest = test
            test = [s[i]]
    if len(longest) < len(test):
        longest = test
    return len(longest)

def score_4(seq):
    if not seq:
        return 0

    M = [None] * len(seq)    # offset by 1 (j -> j-1)
    P = [None] * len(seq)

    # Since we have at least one element in our list, we can start by 
    # knowing that the there's at least an increasing subsequence of length one:
    # the first element.
    L = 1
    M[0] = 0

    # Looping over the sequence starting from the second element
    for i in range(1, len(seq)):
        # Binary search: we want the largest j <= L
        #  such that seq[M[j]] < seq[i] (default j = 0),
        #  hence we want the lower bound at the end of the search process.
        lower = 0
        upper = L

        # Since the binary search will not look at the upper bound value,
        # we'll have to check that manually
        if seq[M[upper-1]] < seq[i]:
            j = upper

        else:
            # actual binary search loop
            while upper - lower > 1:
                mid = (upper + lower) // 2
                if seq[M[mid-1]] < seq[i]:
                    lower = mid
                else:
                    upper = mid

            j = lower    # this will also set the default value to 0

        P[i] = M[j-1]

        if j == L or seq[i] < seq[M[j]]:
            M[j] = i
            L = max(L, j+1)

    # Building the result: [seq[M[L-1]], seq[P[M[L-1]]], seq[P[P[M[L-1]]]], ...]
    result = []
    pos = M[L-1]
    for _ in range(L):
        result.append(seq[pos])
        pos = P[pos]

    return len(result)    # reversing
input_file = open(input("input from: "), "r")
output_file = open(input("output to: "), "w")
T = int(input_file.readline().strip())
smt3 = []
smt2 = []
smt4 = []
smt5 = []
for i in range(T):
        N = int(input_file.readline().strip())
        l = [int(i) for i in input_file.readline().strip().split(' ')]
        print(score(l), score_2(l), score_3(l), score_4(l), score_5(l))
        smt3.append(score_3(l))
        smt2.append(score_2(l))
        smt4.append(score_4(l))
        smt5.append(score_5(l))
        output_file.write("Case #{}: {}\n".format(i+1, "BAD" if score_4(l)>60 else "GOOD"))
        output_file.flush()

