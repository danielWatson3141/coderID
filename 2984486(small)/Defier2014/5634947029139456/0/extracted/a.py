num = 0
testcase = {}
import copy

def bflip(v, i):
    v = list(v)
    if v[i] == '1':
        v[i] = '0'
    else:
        v[i] = '1'
    return ''.join(v)

def flip(tmp, i):
    node = copy.deepcopy(tmp)
    for k, v in enumerate(node):
        node[k] = bflip(v, i)
    return node

def isFit(now, target):
    # node == test['target']
    for i in now:
        if i not in target:
            return False
    return True


def test(test):
    num = int(test['swiches'])
    queue = [(test['initial'], 0), ]
    visited = []
    while queue:
        node, depth = queue.pop(0)
        # print node
        if depth  > num :
            return 'NOT POSSIBLE'
        if isFit(node, test['target']):
            return str(depth)

        if node not in visited:
            for i in range(num):
                queue.append((flip(node, i), depth+1))
        visited.append(node)

with open('a.out', 'wb') as aout:
    with open('a.in') as a:
        for i, l in enumerate(a):
            if i != 0:
                if (i -1) % 3 == 0:
                    if testcase:
                        print i/3
                        aout.write('Case #%d: %s\n' % (i/3 , test(testcase)))
                    testcase = {}
                    testcase['devices'], testcase['swiches'] = l.strip().split(' ')
                elif (i-1)%3 == 1:
                    testcase['initial'] = l.strip().split(' ')
                elif (i-1)%3 == 2:
                    testcase['target'] = l.strip().split(' ')

    if testcase:
        aout.write('Case #%d: %s\n' % (i/3 , test(testcase)))
