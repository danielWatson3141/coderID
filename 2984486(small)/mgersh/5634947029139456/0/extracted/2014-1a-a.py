import string
import itertools

testcase = open('testcase', 'r')
num_cases = int(string.strip(testcase.readline()))

def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return itertools.chain.from_iterable(itertools.combinations(s, r) for r in range(len(s)+1))

def flip (flow, switch, n):
    for y in xrange(n):
        if flow[y][switch] == "0":
            flow[y] = flow[y][:switch] + "1" + flow[y][switch+1:]
        else:
            flow[y] = flow[y][:switch] + "0" + flow[y][switch+1:]

def check(flow, devices, n, l):
    all_flows = set(flow)
    for d in devices:
        if d in all_flows:
            all_flows.remove(d)
        else:
            return False
    return True

def do_calc(i):
    switches = 0
    to_flip_later = []
    params = string.split(string.strip(testcase.readline()), ' ')
    n = int(params[0])
    l = int(params[1])
    flow = string.split(string.strip(testcase.readline()), ' ')
    devices = string.split(string.strip(testcase.readline()), ' ')
#    print flow
#    print devices
    flow_counts = []
    dev_counts = []
    for switch in xrange(l):
        flow_zeros = 0
        flow_ones = 0
        dev_zeros = 0
        dev_ones = 0
        for y in xrange(n):
            if flow[y][switch] == "0":
                flow_zeros += 1
            else:
                flow_ones += 1
            if devices[y][switch] == "0":
                dev_zeros += 1
            else:
                dev_ones += 1
        if flow_zeros == dev_zeros and flow_ones == dev_ones:
            pass
        elif flow_zeros == dev_ones and flow_ones == dev_zeros:
            switches += 1
            flip(flow, switch, n)
        else:
#            print switch
            print "Case #"+str(i)+": NOT POSSIBLE"
            return
        if flow_zeros == flow_ones and dev_zeros == dev_ones:
            to_flip_later.append(switch)
#    print flow
#    print devices
    if check(flow, devices, n, l):
        print "Case #"+str(i)+": "+str(switches)
        return
    else:
        working_switches = l+1
        for s in powerset(to_flip_later):
            tent_switches = switches
        #    print s
            for e in s:
                flip(flow, e, n)
                tent_switches += 1
            if tent_switches < working_switches and check(flow, devices, n, l):
                #print flow
                #print devices
         #       print switches
          #      print tent_switches
                working_switches = tent_switches
            for e in s:
                flip(flow, e, n)
        if working_switches<l+1:
            print "Case #"+str(i)+": "+str(working_switches)
            return
        else:
            print "Case #"+str(i)+": NOT POSSIBLE"

for i in xrange(1, num_cases+1):
    do_calc(i)
