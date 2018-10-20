import sys


def get_diff(outlet, device):
    diff = []
    cnt = 0
    for i in xrange(len(outlet)):
        if outlet[i] == device[i]:
            diff.append(0)
        else:
            diff.append(1)
            cnt += 1
    return cnt, diff

        
def change_outlets(outlets, diff):
    changed = []
    for outlet in outlets:
        o = ""
        for i in xrange(len(outlet)):
            if diff[i] == 1:
                o += "1" if outlet[i] == "0" else "0"
            else:
                o += outlet[i]
        changed.append(o)
    return changed


def compute(N, L, outlets, devices):
    best = L + 1
    d = devices[0]
    d_sorted = sorted(devices)
    for o in outlets:
        cnt, diff = get_diff(o, d)
        if cnt >= best:
            continue
        o_sorted = sorted(change_outlets(outlets, diff))
        if o_sorted == d_sorted:
            best = cnt
    return best if best <= L else "NOT POSSIBLE"


def parse():
    N, L = map(int, sys.stdin.readline().strip().split())
    outlets = map(str, sys.stdin.readline().strip().split())
    devices = map(str, sys.stdin.readline().strip().split())
    return N, L, outlets, devices


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
