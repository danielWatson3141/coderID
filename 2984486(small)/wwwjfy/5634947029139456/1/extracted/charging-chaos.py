import copy

def compare_flip(outlets, devices):
    flags = 0
    if sorted(outlets) == sorted(devices):
        flags |= 1
    for i in range(len(outlets)):
        if outlets[i][-1] == '0':
            outlets[i] = outlets[i][:-1] + '1'
        else:
            outlets[i] = outlets[i][:-1] + '0'
    if sorted(outlets) == sorted(devices):
        flags |= 2
    return flags

def try_flip(outlets, devices, pos):
    if len(outlets[0]) < pos + 1:
        return 0
    this_outlets = [o[:pos + 1] for o in outlets]
    this_devices = [d[:pos + 1] for d in devices]
    result = compare_flip(this_outlets, this_devices)
    if result == 0:
        return None
    if result & 1:
        try1 = try_flip(outlets, devices, pos + 1)
        if result != 3:
            final_try = try1
    if result & 2:
        outlets2 = copy.copy(outlets)
        for i in range(len(outlets2)):
            if outlets2[i][pos] == '0':
                outlets2[i] = outlets2[i][:pos] + '1' + outlets2[i][pos+1:]
            else:
                outlets2[i] = outlets2[i][:pos] + '0' + outlets2[i][pos+1:]
        rest = try_flip(outlets2, devices, pos + 1)
        if rest is not None:
            try2 = rest + 1
            if result != 3:
                final_try = try2
        else:
            try2 = None
            if result != 3:
                final_try = None
    if result == 3:
        if try1 is not None and try2 is not None:
            final_try = min(try1, try2)
        if try1 is not None:
            final_try = try1
        elif try2 is not None:
            final_try = try2
        else:
            final_try = None
    return final_try

for i in range(int(raw_input())):
    raw_input()
    outlets = raw_input().split()
    devices = raw_input().split()
    times = try_flip(outlets, devices, 0)
    if times is not None:
        print('Case #%s: %s' % (i + 1, times))
    else:
        print('Case #%s: NOT POSSIBLE' % (i + 1))
