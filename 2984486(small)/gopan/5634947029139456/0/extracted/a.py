import sys
import itertools
import copy

# def rotate(lst, n):
#     return lst[n:] + lst[0:n]
# 
# assert rotate([1,2,3], 1) == [2,3,1]
# 
# def f(outlet_flows, required_flows, flip_count):
#     for i, of in enumerate(outlet_flows):
# 
# 
#     flat_outlet_flows = list(chain.from_iterable(outlet_flows))
#     flat_required_flows = list(chain.from_iterable(required_flows))
#     a = len([1 for s in flat_outlet_flows if s[0] == '1'])
#     b = len([1 for s in flat_required_flows if s[0] == '1'])
#     results = [sys.maxint]
#     if a == b:
#         results.append(g(outlet_flows[1:], required_flows[1:], flip_count))
#     if a == len(required_flows) - b:
#         results.append(g(outlet_flows[1:], required_flows[1:], flip_count + 1))
#     return sys.maxint

# def g(outlet_flows, required_flows, flip_count):
#     if not outlet_flows:
#         return flip_count
#     return min([f(rotate(outlet_flows, shift), rotate(required_flows, shift), flip_count) for shift in xrange(0, len(outlet_flows))])

sample_count = int(raw_input())
for i in xrange(1, sample_count + 1):
    N, L = [int(s) for s in raw_input().split(' ')]
    outlet_flows = [list(s) for s in raw_input().split(' ')]
    required_flows = sorted([list(s) for s in raw_input().split(' ')])
    least_flips = sys.maxint
    for flip_plan in itertools.product([True, False], repeat=L):
        flips = flip_plan.count(True)
        if least_flips <= flips:
            continue
        # print "flips:", flips
        tmp_flows = copy.deepcopy(outlet_flows)
        # print "before:", tmp_flows
        for j, flip in enumerate(flip_plan):
            if flip:
                for tmp_flow in tmp_flows:
                    tmp_flow[j] = '1' if tmp_flow[j] == '0' else '0'
        # print "after:", sorted(tmp_flows)
        if sorted(tmp_flows) == required_flows:
            # print required_flows
            least_flips = flips
    print 'Case #%d:' % i,
    if least_flips == sys.maxint:
        print 'NOT POSSIBLE'
    else:
        print least_flips

