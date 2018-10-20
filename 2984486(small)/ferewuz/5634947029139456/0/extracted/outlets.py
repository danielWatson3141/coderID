import sys
import itertools

def min_switches(num_of_flows, flow_len, outlets, devices):

    if check_correct(outlets, devices):
        return 0
    for i in range(1, flow_len+1):
        for subset in itertools.combinations(range(0, flow_len), i):
            temp_outlets = [outlet[:] for outlet in outlets[:]]
            for j in subset:
                for k,_ in enumerate(temp_outlets):
                    temp_outlets[k][j] = '1' if temp_outlets[k][j]=='0' else '0'
            if check_correct(temp_outlets, devices):
                return i
    return "NOT POSSIBLE"



def check_correct(outlets, devices):
    for device in devices:
        if device not in outlets:
            return False
    return True
def main(argv=sys.argv):

    count = int(sys.stdin.readline())
    for i in range(count):
        num_of_flows, flow_len = map(int, sys.stdin.readline().split(' '))
        outlets = map(list, (sys.stdin.readline().split(' ')))
        devices = map(list, (sys.stdin.readline().split(' ')))
        outlets[-1].pop()
        devices[-1].pop()
        # Read inputs

        sys.stdout.write(
            'Case #{0}: {1} \n'.format(
                i+1,
                min_switches(num_of_flows, flow_len, outlets, devices)
            )
        )
if __name__ == '__main__':
    main()
