#!/usr/bin/python

import sys

def get_file(argv):
    if len(argv) == 1:
        return "a.in"
    else:
        return "a_%s.in" % (argv[1])

def get_file_out(argv):
    if len(argv) == 1:
        return "a.out"
    else:
        return "a_%s.out" % (argv[1])

def print_answer(t, answer, f):
    answer = "Case #%d: %s" % (t, answer)
    print answer
    f.write(answer)
    f.write("\n")

swap = {
    '0': '1',
    '1': '0'
}

def get_min(outlets, devices, i, flips, min_flips, L):
    # print ''.join([' ']*i), i, flips, min_flips
    # print ''.join([' ']*i), outlets
    # print ''.join([' ']*i), set(outlets)
    # print ''.join([' ']*i), devices
    if set(outlets) == devices:
        # print 'oh yes!'
        return min(flips, min_flips)
    if i >= L:
        return min_flips
    elif flips >= min_flips:
        return min_flips
    else:
        flipped = []
        for outlet in outlets:
            # f = outlet[:]
            # f[i] = swap[f[i]]
            # print outlet[i]
            flipped.append(''.join([outlet[0:i], 
                swap[outlet[i]], 
                outlet[i+1:]]))
        min_flips = get_min([outlet[:] for outlet in outlets], devices, i+1, flips, min_flips, L)
        return min(
            min_flips,
            get_min(flipped, devices, i+1, flips+1, min_flips, L)
        )



def main(argv):
    f = open(get_file(argv), 'r')
    f_out = open(get_file_out(argv), 'w')
    T = int(f.readline())
    for case in xrange(1, T+1):
        N, L = [int(d) for d in (f.readline().split(' '))]
        outlets = f.readline().replace('\n', '').split(' ')
        devices = f.readline().replace('\n', '').split(' ')
        # print outlets
        # print devices
        min_flips = get_min(outlets, set(devices), 0, 0, L+1, L)
        # print min_flips
        if min_flips <= L:
            print_answer(case, min_flips, f_out)
        else:
            print_answer(case, 'NOT POSSIBLE', f_out)

if __name__ == "__main__":
    main(sys.argv)