import sys
import copy

sys.stdin = open('switch.in', 'r')
sys.stdout = open('switch.out', 'w')

def main():
    total_cases = int(input())
    for case_number in range(1, total_cases + 1):
        best = float('inf')
        has_solved = False
        n, l = [int(i) for i in input().split()]
        outlets = set([int(i, 2) for i in input().split()])
        devices = set([int(i, 2) for i in input().split()])
        for switch_combo in range(2**l):
            if try_switch(switch_combo, outlets, copy.copy(devices)):
                has_solved = True
                ones = count_ones(switch_combo) 
                if ones < best:
                    best = ones
        if has_solved:
            print('Case #%d: %d' % (case_number, best))
        else:
            print('Case #%d: NOT POSSIBLE' % (case_number))
        # print('----')

# returns if it works, how many switces
def try_switch(switch, outlets, devices):
    for o in outlets:
        devices.discard(o ^ switch)
    if len(devices) == 0:
        return True
    else:
        return False

def count_ones(number):
    ans = 0
    s = str('{0:b}'.format(number))
    for c in s:
        if c == '1':
            ans += 1
    return ans

if __name__ == '__main__':
    main()