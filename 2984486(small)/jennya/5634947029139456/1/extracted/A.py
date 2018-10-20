
def match(init, goal, flip_first):
    i_cnt = sum([int(str[0]) for str in init])
    g_cnt = sum([int(str[0]) for str in goal])

    if flip_first is False:
        if i_cnt != g_cnt: return None

        rv = []
        if i_cnt!=0:
            new_init_1 = [str[1:] for str in init if str[0]=='1']
            new_goal_1 = [str[1:] for str in goal if str[0]=='1']
            rv.append( (new_init_1, new_goal_1) )
        if (N-i_cnt)!=0:
            new_init_0 = [str[1:] for str in init if str[0]=='0']
            new_goal_0 = [str[1:] for str in goal if str[0]=='0']
            rv.append( (new_init_0, new_goal_0) )
        return rv

    else:
        if len(init)-i_cnt != g_cnt: return None

        rv = []
        if i_cnt!=0:
            new_init_1 = [str[1:] for str in init if str[0]=='1']
            new_goal_0 = [str[1:] for str in goal if str[0]=='0']
            rv.append( (new_init_1, new_goal_0) )
        if (len(init)-i_cnt)!=0:
            new_init_0 = [str[1:] for str in init if str[0]=='0']
            new_goal_1 = [str[1:] for str in goal if str[0]=='1']
            rv.append( (new_init_0, new_goal_1) )
        return rv


import sys
f = open(sys.argv[1])

line = f.readline()
T = int(line)

case_counter = 1
while 1:
    if case_counter > T: break

    # input stage
    line = f.readline().split()
    N = int(line[0])
    L = int(line[1])

    init = f.readline().split()
    goal = f.readline().split()
    state = (0, [(init, goal)], '')
    bfs_queue = [state]

    output = None
    while len(bfs_queue)!=0 :
        bfs_queue.sort()
        state = bfs_queue.pop(0)
        ans = state[0]
        groups = state[1]
        ans_seq = state[2]
        

        # flip_first = False
        new_groups = []
        failure = False
        #print("=== ", ans, ans_seq, "F")
        for group in groups:
            #print(" ", group[0], group[1])
            rv = match(group[0], group[1], flip_first = False)
            #print(" => ", rv)
            if rv is not None:
                new_groups+=rv
            else:
                failure = True
                break
        if failure is not True:
            if len(ans_seq)==L-1:
                output = ans
                break
            else:
                #print("  ## append")
                bfs_queue.append((ans, new_groups, ans_seq+'0'))

        # flip_first = False
        new_groups = []
        failure = False
        #print("=== ", ans, ans_seq, "T")
        for group in groups:
            #print(" ", group[0], group[1])
            rv = match(group[0], group[1], flip_first = True)
            if rv is not None:
                new_groups+=rv
            else:
                failure = True
                break
        if failure is not True:
            if len(ans_seq)==L-1:
                output = ans+1
                break
            else:
                #print("  ## append")
                bfs_queue.append((ans+1, new_groups, ans_seq+'1'))

    # output stage
    if output is None:
        print("Case #%d: NOT POSSIBLE" % (case_counter) )
    else:
        print("Case #%d: %d" % (case_counter, output) )

    case_counter += 1

