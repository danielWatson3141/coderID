from functools import partial
import time
import datetime

__author__ = 'eegee'

filename = "A-small-attempt0"

input_data = open("../data/" + filename + ".in")
output_data = open("../data/" + filename + ".out", "w")
time.perf_counter()


def bit_count(int_type):
    count = 0
    while int_type:
        int_type &= int_type - 1
        count += 1
    return count

for case in range(int(input_data.readline())):
    answer = ""
    # read inputs #
    switch_count, switch_length = list(map(int, input_data.readline().split()))
    base_two = partial(int, base=2)
    switches = sorted(list(map(base_two, input_data.readline().split())))
    required_switches = sorted(list(map(base_two, input_data.readline().split())))
    # read inputs #

    # solution #
    max_mask = 2 ** switch_length - 1
    def get_answer():
        for bits_flipped in range(switch_length + 1):
            for mask in range(max_mask):
                if bit_count(mask) != bits_flipped:
                    continue

                new_switches = []
                for switch in switches:
                    new_switches.append(switch ^ mask)

                if required_switches == sorted(new_switches):
                    return str(bits_flipped)

        return "NOT POSSIBLE"

    answer = get_answer()
    # solution #

    # display and write output #
    output_line = "Case #" + str(case + 1) + ": "
    print(output_line + answer)
    output_data.write(output_line + answer + "\n")
    # display and write output #

print()
print("total_time:", datetime.timedelta(seconds=time.perf_counter()))
input_data.close()
output_data.close()