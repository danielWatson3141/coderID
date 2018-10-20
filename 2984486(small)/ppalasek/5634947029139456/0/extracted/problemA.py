import copy

input_file = open("A-small-attempt0.in")

num_t = int(input_file.readline())

def to_bool(s, l):
    return [bool(int(c)) for c in s[:l]]

for t in xrange(num_t):
    (n, l) = (int(s) for s in input_file.readline().split(' '))

    states = [to_bool(s, l) for s in input_file.readline().split(' ')]
    needed = [to_bool(s, l) for s in input_file.readline().split(' ')]

    needed_s = set(tuple(c) for c in needed)

    f = '{:0' + str(l) + 'b}'

    result = 'NOT POSSIBLE'

    found = False

    for i in xrange(2 ** l):
        bin = f.format(i)
        states_c = copy.deepcopy(states)

        for cur in xrange(l):
            if bool(int(bin[cur])):
                for s in xrange(n):
                    states_c[s][cur] = not(states_c[s][cur])

            curr = set(tuple(c) for c in states_c)

            if len(curr.intersection(needed_s)) == n:
                result = bin.count("1")
                found = True
                break

        if found:
            break

    print 'Case #' + str(t + 1) + ': ' + str(result)