__author__ = 'nguyensontung1404'

def eliminate(_list):
    if "\n" in _list[-1]:
        _list[-1] = _list[-1][:-1]
    return _list

def no_flip(outlet, device):
    for flow in device:
        if flow not in outlet:
            return False
    return True

def need_flip(flow_o, flow_d):
    re = []
    for i in range(len(flow_d)):
        if flow_d[i] != flow_o[i]:
            re.append(i)
    return re

def flip(outlet, index):
    o = outlet[:]
    for i in range(len(o)):
        for f in index:
            _str = o[i]
            if _str[f] == "0":
                _str = "%s1%s" % (_str[:f], _str[f+1:])
                o[i] = _str
            else:
                _str = "%s0%s" % (_str[:f], _str[f+1:])
                o[i] = _str
    return o

if __name__ == "__main__":
    import sys
    sys.stdin = open("A-large.in")
    sys.stdout = open("out.txt", "w")
    for case in range(1, int(sys.stdin.readline())+1):
        _str = sys.stdin.readline()
        N, L = map(int, _str.split(" "))
        outlet = eliminate(sys.stdin.readline().split(" "))
        device = eliminate(sys.stdin.readline().split(" "))
        if no_flip(outlet, device):
            print "Case #%d: 0" % case
        else:
            origin = device[0]
            count = []
            for flow in outlet:
                switches = need_flip(flow, origin)
                if no_flip(flip(outlet,switches), device):
                    count.append(len(switches))
            if count == []:
                print "Case #%d: NOT POSSIBLE" % case
            else:
                print "Case #%d: %d" % (case, min(count))


