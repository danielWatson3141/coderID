flows = []
devs = []
outlet_num = 0

def test(tester):
    global flows,devs
    new_flows = [v ^ tester for v in flows]
    return set(new_flows) == set(devs)

def getBestTester(testers):
    global outlet_num
    candidate = testers[0]
    min_cnt = outlet_num
    for t in testers:
        flip_cnt = str(format(t, "b")).count('1')
        if flip_cnt < min_cnt:
            min_cnt = flip_cnt
            candidate = t
    return candidate

test_cnt = input()
output = []

def getTester(bit_cnt):
    res = []
    for i in range(0, 2 ** bit_cnt):
        res.append(i)
    return res

for num in range(0, test_cnt):
    in_arr = raw_input().split(" ")
    dev_num = int(in_arr[0])
    outlet_num = int(in_arr[1])
    flows = [int(x,2) for x in raw_input().split(" ")]
    devs = [int(y,2) for y in raw_input().split(" ")]
    
    pass_testers = []
    tester = getTester(outlet_num)
    for t in tester:
        if test(t):
            pass_testers.append(t)    
    if len(pass_testers) > 0:
        t = getBestTester(pass_testers)
        answer = str(str(format(t, "b")).count('1'))
    else:
        answer = "NOT POSSIBLE"
    output.append("Case #%d: %s" % ((num + 1), answer))
    
    
for v in output:
    print v

