testcase = {}
import copy
test_count = 0


def remove(node, i):
    if i in node:
        for j in node:
            try:
                node[j].remove(i)
            except:
                pass
        del node[i]


def isFull(node):
    er = 0
    for i in node:
        if len(node[i]) == 2:
            er += 1
        elif len(node[i]) not in [1, 3]:
            return False
    if er != 1:
        return False
    return True


def test(testcase):
    global test_count
    print test_count
    depth = 0
    for i in testcase.keys():
        if len(testcase[i]) == 1 and len(testcase[testcase[i][0]]) > 3 or (len(testcase[testcase[i][0]])== 2 and i not in testcase[testcase[i][0]]):
            remove(testcase, i)
            depth += 1

    test_count += 1
    queue = [(testcase, depth)]
    visited = []
    while queue:
        tmp, depth = queue.pop(0)
        if isFull(tmp):
            return 'Case #%d: %d' % (test_count, depth),
        if tmp not in visited:
            for i in tmp:
                node = copy.deepcopy(tmp)
                remove(node, i)
                queue.append((node, depth + 1))
            visited.append(node)
    return 'Case #%d: %d' % (test_count, depth)

with open('b.out', 'wb') as aout:
    with open('b.in') as a:
        for i, l in enumerate(a):
            if i != 0:
                if len(l.strip().split(' ')) == 1:
                    if testcase:
                        aout.write('%s\n' % test(testcase))
                    testcase = {}
                else:
                    a, b = l.strip().split(' ')

                    if a not in testcase:
                        testcase[a] = []

                    if b not in testcase:
                        testcase[b] = []

                    testcase[a].append(b)
                    testcase[b].append(a)

    if testcase:
        # print test(testcase)
        aout.write('%s\n' % test(testcase))
