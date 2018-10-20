def uber_check(possibles, result, target):
    if set(result) == set(target):
        return 0
    m = 20000
    for i in xrange(len(possibles)):
        for j in xrange(len(result)):
            result[j] ^= 1 << possibles[i]
        m = min(m, uber_check(possibles[i + 1:], result, target) + 1)
        for j in xrange(len(result)):
            result[j] ^= 1 << possibles[i]
    return m
    
def process_game():
    N, L = map(int,raw_input().split())
    start = map(lambda x : int(x,2), raw_input().split())
    target = map(lambda x : int(x,2), raw_input().split())
    assert(len(start) == N)
    assert(len(target) == N)
    bit_count_s = [sum((start[i] >> j) & 1 for i in xrange(N)) for j in xrange(L)]
    bit_count_t = [sum((target[i] >> j) & 1 for i in xrange(N)) for j in xrange(L)]
    result = start[:]
    changes = 0
    possibles = []
    for i in xrange(L):
        if bit_count_t[i] * 2 == N:
            possibles.append(i)
        if bit_count_s[i] == bit_count_t[i]:
            continue
        if bit_count_s[i] + bit_count_t[i] == N:
            changes += 1
            for j in xrange(N):
                result[j] ^= 1 << i
            continue
        print "NOT POSSIBLE"
        return

    res = uber_check(possibles, result, target)
    if res < 20000:
        print changes + res
    else:
        print "NOT POSSIBLE"

for i in xrange(1, int(raw_input()) + 1):
    print "Case #%d:" % (i),
    process_game()
