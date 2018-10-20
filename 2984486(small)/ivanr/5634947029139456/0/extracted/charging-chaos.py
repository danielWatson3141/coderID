T = int(raw_input())

for t in xrange(T):
    N, L = map(int, raw_input().split())
    init = raw_input().split()
    required = raw_input().split()

    init.sort()
    required.sort()
    required = ' '.join(required)

    todo = [(' '.join(init), 0)]
    done = set()

    result = 'NOT POSSIBLE'

    while len(todo) > 0:
        init, num = todo[0]
        todo = todo[1:]

        if init in done:
            continue

        done.add(init)

        if init == required:
            result = num
            break

        init = init.split()

        # Try to flip each bit
        for i in xrange(L):
            new = map(list, init)

            for j in xrange(N):
                if new[j][i] == '0': new[j][i] = '1'
                else: new[j][i] = '0'

            new = map(lambda x: ''.join(x), new)
            new.sort()
            new = ' '.join(new)
            todo.append((new, num+1))

    print 'Case #%d: %s' % (t+1, result)
