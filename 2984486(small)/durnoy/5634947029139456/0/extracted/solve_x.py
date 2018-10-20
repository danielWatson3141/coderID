from __future__ import print_function
import sys

f = sys.stdin

if len(sys.argv) > 1:
    f = open(sys.argv[1], "rt")


T = int(f.readline().strip())

for case_id in range(1, T+1):
    N, L = map(int, f.readline().strip().split())
    flows = list(map(lambda x: long(x, base=2), f.readline().strip().split()))
    devices = list(map(lambda x: long(x, base=2), f.readline().strip().split()))

    #~ print(N, L)
    #~ for i in flows:
        #~ print(str.format('{0:0' + str(L) + 'b}', i))
    #~ print('--')
    #~ for i in devices:
        #~ print(str.format('{0:0' + str(L) + 'b}', i))
    #~ print('--')
    r = 'NOT POSSIBLE'
    min_num = L + 1
    devices_set = set(devices)
    for x in range(0, 2 << L):
        new_flows_set = set(map(lambda y: y ^ x, flows))
        if len(new_flows_set - devices_set) == 0 and len(devices_set - new_flows_set) == 0:
            min_num = min(min_num, str.format('{0:b}', x).count('1'))

    if min_num <= L:
        r = min_num

    print(str.format('Case #{0}: {1}', case_id, r))
