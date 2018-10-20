import copy

f = open('A-small-attempt1.in', 'r')
outf = open('output1.txt', 'w')

T = int(f.readline())

def compare_state(outlets, devices):
    if (set(map(lambda x: ''.join(map(str, x)), outlets)) == 
        set(map(lambda x: ''.join(map(str, x)), devices))):
        return True
    else:
        return False

def change_i_bit(outlets, i):
    new_state = copy.deepcopy(outlets)
    for switch in new_state:
        switch[i] = 1 - switch[i]
    return new_state

def charge(N, L, outlets, devices):
    # if (reduce(lambda x, y: x & y, map(lambda x: int(x, 2), outlets)) ^ 
    #     reduce(lambda x, y: x & y, map(lambda x: int(x, 2), devices))) != 0:
    #     return -1
    
    outlets = map(lambda x: map(int, list(x)), outlets)
    devices = map(lambda x: map(int, list(x)), devices)

    if compare_state(outlets, devices) is True:
        return 0

    pre_level = {'': outlets}
    for tot_switch in range(L):
        new_level = {}
        for parent in pre_level.keys():
            try:
                changed_bits = set(map(int, parent.split('-')))
            except ValueError:
                changed_bits = set()
            for s_bit in range(L):
                if s_bit not in changed_bits:
                    new_bits_list = list(changed_bits) + [s_bit]
                    new_bits_list.sort()
                    new_bits = '-'.join(map(str, new_bits_list))
                    if new_bits not in new_level:
                        new_state = change_i_bit(pre_level[parent], s_bit)
                        if compare_state(new_state, devices) is True:
                            return tot_switch + 1
                        new_level[new_bits] = new_state
        pre_level = new_level
    return -1

for test_ind in range(T):
    N, L = map(int, f.readline().split())
    outlets = f.readline().split()
    devices = f.readline().split()

    can_charge = charge(N, L, outlets, devices)

    if can_charge >= 0:
        out_str = 'Case #' + str(test_ind + 1) + ': ' + str(can_charge) + '\n'
    else:
        out_str = 'Case #' + str(test_ind + 1) + ': NOT POSSIBLE\n'
    outf.write(out_str)

f.close()
outf.close()
