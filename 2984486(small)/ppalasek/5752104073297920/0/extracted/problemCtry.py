input_file = open("C-small-attempt1.in")

num_t = int(input_file.readline())

current = []

for t in xrange(num_t):
    n = int(input_file.readline())

    line = [int(s) for s in input_file.readline().split(' ')]
    
    c = 0

    for l in xrange(len(line)):
        c += (line[l] - l) ** 2

    current.append(c)

avg = sum(current) / float(len(current))

for s in xrange(len(current)):
    print 'Case #' + str(s + 1) + ":",

    if current[s] > avg:
        print 'GOOD'
    else:
        print 'BAD'
        
