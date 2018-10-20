#!/usr/bin/python

import sys


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        nb_outlets, flow_length = map(int, data.readline().split())
        initial_flows = [int(i, 2) for i in data.readline().split()]
        required_flows = [int(i, 2) for i in data.readline().split()]
        # fix the solution switch per switch
        switch_changes = 0
#        for i in xrange(flow_length):
#            xores = []
#            for initial, required in zip(initial_flows, required_flows):
#                x = int(initial, 2) ^ int(required, 2)
#                xores.append(bin(x)[2:])
#            initial_ones = 0
#            required_ones = 0
#            for initial, required in zip(initial_flows, required_flows):
#                if initial[i] == '1':
#                    initial_ones += 1
#                if required[i] == '1':
#                    required_ones += 1
#            if initial_ones == required_ones:
#                pass
#            elif initial_ones == nb_outlets - required_ones:
#                switch_changes += 1
#            else:
#                switch_changes = -1
#                break
            # new mehod brute force
            # there are 2**10 combos
        lowest_change = 0
        cur_best = None
        required_flows = sorted(required_flows)
        for ibrute in xrange(2 ** flow_length):
            changed_bits = bin(ibrute).count('1')
            if changed_bits < cur_best or cur_best is None:
                # test it
                modified = sorted([i ^ ibrute for i in initial_flows])
                if modified == required_flows:
                    cur_best = changed_bits
        print "Case #%d: %s" % (icase + 1, str(cur_best) if cur_best is not None else "NOT POSSIBLE")


if __name__ == "__main__":
    main()
