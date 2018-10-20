#!/usr/bin/env python
#coding: utf-8

def check(outlets, devices):
    new_outlets = sorted(outlets)
    new_devices = sorted(devices)
    same = True
    for i in xrange(len(new_devices)):
        if new_outlets[i] != new_devices[i]:
            same = False
            break
    return same

if __name__ == '__main__':
    fname = 'A-small-attempt3'
    with open('%s.in' % fname) as f, open('%s.out' % fname, 'w') as f2:
        casenum = int(f.readline())
        for casei in xrange(casenum):
            n, l = f.readline().strip().split()
            n, l = int(n), int(l)
            outlets = f.readline().strip().split()
            devices = f.readline().strip().split()
            one_count_outlet = []
            one_count_device = []
            for i in xrange(l):
                count = 0
                for item in outlets:
                    if item[i] == '1':
                        count += 1
                one_count_outlet.append(count)
                count = 0
                for item in devices:
                    if item[i] == '1':
                        count += 1
                one_count_device.append(count)
            flip_index = []
            flip_count = 0
            possible = True
            # print one_count_outlet, one_count_device
            for i in xrange(l):
                if one_count_outlet[i]*2 == n:
                    flip_index.append(i)
                    continue
                if one_count_outlet[i] == n - one_count_device[i]:
                    flip_count += 1
                    for j in xrange(n):
                        if outlets[j][i] == '1':
                            outlets[j] = outlets[j][:i]+'0'+outlets[j][i+1:]
                        else:
                            outlets[j] = outlets[j][:i]+'1'+outlets[j][i+1:]
                    continue
                if one_count_outlet[i] == one_count_device[i]:
                    continue
                possible = False
                break
            if not possible:
                print 'NOT POSSIBLE'
                f2.write('Case #%s: NOT POSSIBLE\n' % (casei+1))
                continue
            if not flip_index:
                result = check(outlets, devices)
                # print outlets, devices
                if result:
                    print flip_count
                    f2.write('Case #%s: %s\n' % (casei+1, flip_count))
                else:
                    print 'NOT POSSIBLE'
                    f2.write('Case #%s: NOT POSSIBLE\n' % (casei+1))
                continue
            result_list = []
            for flipi in xrange(2**len(flip_index)):
                flip_count2 = 0
                tmp = flipi
                for i in xrange(len(flip_index)):
                    if tmp % 2 == 1:
                        for j in xrange(n):
                            if outlets[j][flip_index[i]] == '1':
                                outlets[j] = outlets[j][:flip_index[i]]+'0'+outlets[j][flip_index[i]+1:]
                            else:
                                outlets[j] = outlets[j][:flip_index[i]]+'1'+outlets[j][flip_index[i]+1:]
                        flip_count2 += 1
                    tmp = tmp/2
                result = check(outlets, devices)
                if result:
                    result_list.append(flip_count+flip_count2)
                tmp = flipi
                for i in xrange(len(flip_index)):
                    if tmp % 2 == 1:
                        for j in xrange(n):
                            if outlets[j][flip_index[i]] == '1':
                                outlets[j] = outlets[j][:flip_index[i]]+'0'+outlets[j][flip_index[i]+1:]
                            else:
                                outlets[j] = outlets[j][:flip_index[i]]+'1'+outlets[j][flip_index[i]+1:]
                    tmp = tmp/2
            if result_list:
                count = min(result_list)
                print count
                f2.write('Case #%s: %s\n' % (casei+1, count))
            else:
                print 'NOT POSSIBLE'
                f2.write('Case #%s: NOT POSSIBLE\n' % (casei+1))




