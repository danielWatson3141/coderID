import random

def get_ints():
    return map(int, raw_input().split())


def count_bad_shuffles(length=40):
    digit_pos_counts = [[0] * length for _ in xrange(length)]
    for _ in xrange(100000):
        a = range(length)
        for k in xrange(length):
            p = random.randint(0, length - 1)
            a[k], a[p] = a[p], a[k]
        for i, d in enumerate(a):
            digit_pos_counts[d][i] += 1

    probabilities = []
    for digit_counts in digit_pos_counts:
        total = float(sum(digit_counts))
        digit_probs = [count / total for count in digit_counts]
        assert 0.0 not in digit_probs
        probabilities.append(digit_probs)
        #print 'hi'
        #print ' '.join('%f' % (prob) for prob in digit_probs)
    return probabilities

probabilities = count_bad_shuffles(1000)


def shuffle_bad(length):
    a = range(length)
    for k in xrange(length):
        p = random.randint(0, length - 1)
        a[k], a[p] = a[p], a[k]
    return a


def shuffle_good(length):
    a = range(length)
    for k in xrange(length):
        p = random.randint(k, length - 1)
        a[k], a[p] = a[p], a[k]
    return a


def probability(pos, value, length):
    return

#print probabilities

def is_good(sequence):
    length = len(sequence)
    assert length==1000
    prior_probability = 1.0
    for pos, value in enumerate(sequence):
        prob = probabilities[value][pos]
        prior_probability *= prob / (1. / length) # / (prob * .5 + (1. / length) * .5)
    return prior_probability < .52


l=1000
#corr_good = sum(is_good(shuffle_good(l)) for _ in xrange(1000))
#corr_bad = sum(is_good(shuffle_bad(l)) == False for _ in xrange(1000))
#print corr_good, corr_bad


n_cases = input()
for case in xrange(1, n_cases + 1):
    length, = get_ints()
    permutation = get_ints()

    result = is_good(permutation)

    print "Case #%d: %s" % (case, "GOOD" if result else "BAD")
