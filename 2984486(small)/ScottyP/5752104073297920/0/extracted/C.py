import numpy as np
import math
import time


input_file_name = './C-small-attempt0.in'
output_file_name = './C-small.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    expected_value = 375000

    case_num = 1
    while True:
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        N = int(file_line)

        file_line = input_file.readline()
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        perm = map(int, file_line_list)

        sum_total = 0
        for i in range(len(perm)):
            sum_total += abs(i - perm[i])

        print(sum_total) ##

        if sum_total < 325000:
            output_file.write('Case #' + str(case_num) + ': ' + 'BAD' + '\n') ##
        else:
            output_file.write('Case #' + str(case_num) + ': ' + 'GOOD' + '\n') ##
##        print(case_num)
        case_num += 1
        
    output_file.close()











