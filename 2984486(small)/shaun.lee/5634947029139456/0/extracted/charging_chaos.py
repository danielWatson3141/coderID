from __future__ import print_function
import sys


def read_input(f):
    T = int(f.readline().strip())

    for i in xrange(T):
        output = {}
        counts = [int(val) for val in f.readline().strip().split(" ")]
        output['N'] = counts[0]
        output['L'] = counts[1]
        output['outlets'] = f.readline().strip().split(" ")
        output['outlets'] = [[int(val) for val in list(outlet)]
                             for outlet in output['outlets']]
        output['devices'] = f.readline().strip().split(" ")
        output['devices'] = [[int(val) for val in list(dev)]
                             for dev in output['devices']]

        yield output


def test_sat(outlets, devices):
    return all([dev in outlets for dev in devices])


def toggle(outlet, switch_no):
    new_outlet = list(outlet)
    new_outlet[switch_no] = abs(outlet[switch_no] - 1)
    return new_outlet


def toggle_switches(outlets, switch_no):
    return [toggle(outlet, switch_no) for outlet in outlets]


def check_case(N, L, outlets, devices, depth, pos=0):
    # if it works, we're done
    if test_sat(outlets, devices):
        return depth
    # if not, recursively explore the space by flipping each of the
    # remaining switches
    else:
        if pos < L:
            result = [check_case(N, L,
                                 toggle_switches(outlets, i),
                                 devices,
                                 depth + 1,
                                 i + 1)
                      for i in xrange(pos, L)]
            if any(result):
                result = [val for val in result if val is not None]
                return min(result)
        return None

if __name__ == "__main__":
    input_filename = sys.argv[1]
    with open(input_filename) as input_file:
        case_no = 0
        for case in read_input(input_file):
            case_no += 1
            # check_case(case)
            N = case['N']
            L = case['L']
            outlets = case['outlets']
            devices = case['devices']
            result = check_case(N, L, outlets, devices, 0)
            if result is None:
                result = "NOT POSSIBLE"
            else:
                result = str(result)
            print("Case #" + str(case_no) + ": " + result)
