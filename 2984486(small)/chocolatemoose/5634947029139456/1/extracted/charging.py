import sys

def swap(outlets,bit):
    for outlet in outlets:
        outlet[bit] = not outlet[bit]

with open(sys.argv[1]) as ff:
    t = int(ff.readline())
    for c in range(1,t+1):
        n,l = map(int,ff.readline().split())
        devices = [[int(a) for a in d] for d in ff.readline().split()]
        outlets = [tuple(int(a) for a in d) for d in ff.readline().split()]
#         print devices
#         print outlets
        min_switch = 100
        for device in devices:
            swap_outlets = [list(a) for a in outlets]
            foutlet = swap_outlets[0]
            swaps = 0
#             print device
            for i,bit in enumerate(device):
#                 print i,bit
                if bit != foutlet[i]:
                    swap(swap_outlets,i)
                    swaps += 1
            if set(map(tuple,devices)) == set(map(tuple,swap_outlets)):
                min_switch = min(swaps,min_switch)
        if min_switch == 100:
            print "Case #%d: NOT POSSIBLE" % c
        else:
            print "Case #%d: %d" % (c,min_switch)