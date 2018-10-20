#!/usr/bin/env python3

def process(outlets, devices, l, flip):
    if l == len(devices[0]):
        outlets_s = [x.decode('utf-8') for x in outlets]
        devices_s = [x.decode('utf-8') for x in devices]
        outlets_s.sort()
        if outlets_s == devices_s:
            return flip
        else:
            return None
    if l != 0:
        outlets_s = [x[:l].decode('utf-8') for x in outlets]
        devices_s = [x[:l].decode('utf-8') for x in devices]
        outlets_s.sort()
        if outlets_s != devices_s:
            return None
    required_zeros = [x[l] for x in devices].count(48)
    has_zeros = [x[l] for x in outlets].count(48)
    retval1 = retval2 = 999
    if required_zeros == has_zeros:
        retval1 = process(outlets, devices, l+1, flip)
        if retval1 is None:
            retval1 = 999
    if required_zeros + has_zeros == len(devices):
        for o in outlets:
            if o[l] == 49:
                o[l] = 48
            else:
                o[l] = 49
        retval2 = process(outlets, devices, l+1, flip+1)
        if retval2 is None:
            retval2 = 999
        for o in outlets:
            if o[l] == 49:
                o[l] = 48
            else:
                o[l] = 49
    if retval1 == retval2 and retval2 == 999:
        return None
    else:
        return min(retval1, retval2)

T = int(input())
for case in range(1, T+1):
    input()
    outlets = [bytearray(s, 'utf-8') for s in input().split()]
    devices = [bytearray(s, 'utf-8') for s in input().split()]
    devices.sort()
    retval = process(outlets, devices, 0, 0)
    print('Case #{0}: {1}'.format(case, retval if retval is not None else 'NOT POSSIBLE'))
