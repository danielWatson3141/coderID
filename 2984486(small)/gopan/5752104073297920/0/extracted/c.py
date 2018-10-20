import random
from collections import Counter

def good_shuffle(N):
    a = [k for k in xrange(0, N)]
    for k in xrange(0, N):
        p = random.randint(k, N - 1)
        a[k], a[p] = a[p], a[k]
    return tuple(a)

def bad_shuffle(N):
    a = [k for k in xrange(0, N)]
    for k in xrange(0, N):
        p = random.randint(0, N - 1)
        a[k], a[p] = a[p], a[k]
    return tuple(a)

# good_results = [good_shuffle(3) for i in xrange(100000)]
# bad_results = [bad_shuffle(3) for i in xrange(100000)]
# print Counter(good_results)

# print Counter(bad_results)

def sign(n):
    if n > 0:
        return 1
    else:
        return -1

def calc_score_of_perm(perm):
    N = len(perm)
    score = 0.0
    for i in xrange(0, N):
        if perm[i] < i + 2:
            perm[i] += N
        # print score
        tmp = 1 - 2.04 * (perm[i] - (i + 2)) / (N - 1)
        score += sign(tmp) * pow(abs(tmp), 1.1)
    return score

sample_count = int(raw_input())
good_count = 0
for i in xrange(1, sample_count + 1):
    N = int(raw_input())
    perm = [int(s) for s in raw_input().split(' ')]
    assert len(perm) == N
    score = calc_score_of_perm(perm)
    print 'Case #%d:' % i,
    if score > 0:
        print 'BAD'
    else:
        print 'GOOD'
        good_count += 1
# print good_count


