import sys

def flip_bit(outlets, curr_flip):
    new_outlets = []
    for outlet in outlets:
        flipper = outlet[curr_flip]
        flipper = '1' if flipper == '0' else '0'
        new_outlet = outlet[:curr_flip] + flipper + outlet[curr_flip+1:]
        new_outlets.append(new_outlet)
    return new_outlets

def run(n, l, outlets, devices, curr_flip, num_flips, curr_best):
    # when every bit has been flipped, return.
    if curr_flip >= l: return curr_best
    # are they valid in the current state?
    valid = set(outlets) == set(devices)
    if valid and num_flips < curr_best:
        curr_best = num_flips
    # flip current bit, is it valid in the new state?
    new_outlets = flip_bit(outlets, curr_flip)
    new_valid = set(new_outlets) == set(devices)
    if new_valid and num_flips < curr_best:
        curr_best = num_flips + 1
    # now continue checking, getting back the currently know best.
    curr_best = run(n, l, outlets, devices, curr_flip+1, num_flips, curr_best)
    curr_best = run(n, l, new_outlets, devices, curr_flip+1, num_flips+1, curr_best)
    return curr_best

def solve_test(n, l, outlets, devices):
    num = run(n,l,outlets,devices,0,0,l+1)
    if num > l:
        return "NOT POSSIBLE"
    else:
        return str(num)

if __name__ == "__main__":
    lines = [line.rstrip('\n') for line in open(sys.argv[1])]
    f = open('out.txt', 'w')
    number_of_tests = int(lines[0])
    line_count = 1
    # for each test
    for test_number in range(1, number_of_tests + 1):
        n_and_l = [int(i) for i in lines[line_count].split(' ')]
        n = n_and_l[0]
        l = n_and_l[1]
        line_count += 1
        outlets = [i for i in lines[line_count].split(' ')]
        line_count += 1
        devices = [i for i in lines[line_count].split(' ')]
        line_count += 1

        f.write('Case #%s: %s\n' % (test_number, solve_test(n, l, outlets, devices)))
    f.close()
