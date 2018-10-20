fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
changes = []


def try_both(flows, devices):
    a = sorted(flows)
    b = sorted(devices)
    for i in range(len(a)):
        if a[i] != b[i]:
            return 0
    return 1


def make_changes(l, len_, tot):
    if len_ == tot:
        changes.append(l)
        return
    make_changes(l + '0', len_+1, tot)
    make_changes(l + '1', len_+1, tot)


def can_be(ch, flows, devices, L):
    flows_ = []
    for i in range(len(flows)):
        elem = flows[i]
        res = ''
        for j in range(L):
            if ch[j] == '1':
                res += str(1 - int(elem[j]))
            else:
                res += str(int(elem[j]))
        flows_.append(res)
    return try_both(flows_, devices)


tests = int(fin.readline())
for t in range(tests):
    N, L = map(int, fin.readline().split())
    flows = sorted(list(fin.readline().split()))
    changes = []
    make_changes('', 0, L)
    k = 0
    can = 0
    for elem in changes:
        if can_be(elem, flows, devices, L):
            k = elem.count('1')
            can = 1
            break
    if can == 1:
        fout.write("Case #" + str(t + 1) + ": " + str(k) + '\n')
    else:
        fout.write("Case #" + str(t + 1) + ": NOT POSSIBLE\n")
fout.close()
