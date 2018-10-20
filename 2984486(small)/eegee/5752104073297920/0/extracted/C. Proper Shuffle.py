import time
import datetime
__author__ = 'eegee'

filename = "C-small-attempt3"

input_data = open("../data/" + filename + ".in")
output_data = open("../data/" + filename + ".out", "w")
time.perf_counter()

for case in range(int(input_data.readline())):
    answer = ""
    # read inputs #
    number_count = int(input_data.readline())
    numbers = list(map(int, input_data.readline().split()))
    # read inputs #

    # solution #
    increase_count = 0
    for i in range(number_count):
        if numbers[i] > numbers[i - 1]:
            increase_count += 1
    percent = (increase_count / number_count)
    # print(percent)
    answer = "GOOD" if (0.49 < percent < 0.51) else "BAD"
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