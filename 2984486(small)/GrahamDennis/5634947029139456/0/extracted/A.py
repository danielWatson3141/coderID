#!/usr/bin/env python

import sys
from heapq import heappush, heappop, heappushpop
from collections import Counter


def main(argv):
    f = open(argv[1])
    
    T = int(f.readline())
    
    for t in xrange(T):
        print "Case #%i: %s" % (t+1, solve(f))


def solve(f):
    
    N, L = map(int, f.readline().split())
    
    initial_flows = map(lambda x: int(x, base=2), f.readline().split())
    target_flows = map(lambda x: int(x, base=2), f.readline().split())
    
    def is_valid(bits_considered, flips):
        mask = (1 << (bits_considered)) - 1
        
        target_counter = Counter(flow & mask for flow in target_flows)
        initial_counter = Counter((flow ^ flips) & mask for flow in initial_flows)
        
        # if target_counter == initial_counter:
        # print "attempting: %i, %i; mask = %i" % (bits_considered, flips, mask)
        # print target_counter, initial_counter
        
        return target_counter == initial_counter
    
    heap = []
    
    heappush(heap, (0, 0, 0))
    
    while heap:
        # print heap
        flip_count, bits_considered, flips = heappop(heap)
        
        if is_valid(bits_considered+1, flips):
            if bits_considered+1 == L: return flip_count
            heappush(heap, (flip_count, bits_considered+1, flips))
        
        new_flips = flips | (1 << bits_considered)
        if is_valid(bits_considered+1, new_flips):
            if bits_considered+1 == L: return flip_count + 1
            heappush(heap, (flip_count+1, bits_considered+1, new_flips))
    
    return "NOT POSSIBLE"


if __name__ == "__main__":
    sys.exit(main(sys.argv))
