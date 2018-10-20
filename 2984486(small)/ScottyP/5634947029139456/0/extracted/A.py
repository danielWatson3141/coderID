import numpy as np
import math
import time


input_file_name = './A-small-attempt0.in'
output_file_name = './A-small.out'
    

if __name__ == '__main__':

    input_file = open(input_file_name, 'r')
    output_file = open(output_file_name, 'w')

    # get info from input file
    file_line = input_file.readline()
    file_line = file_line.replace('\n', '')
    num_cases = int(file_line)

    case_num = 1
    while True:
        file_line = input_file.readline()
        if file_line == '' or file_line == '\n':
            input_file.close()
            break
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        N = int(file_line_list[0])
        L = int(file_line_list[1])

        outlet_array = np.zeros((N, L), dtype = np.bool)
        device_array = np.zeros((N, L), dtype = np.bool)
        device_bool_array = np.zeros((N), dtype = np.int)

        # fill in outlet_array
        file_line = input_file.readline()
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        for i in range(N):
            for j in range(L):
                outlet_array[i, j] = bool(int(file_line_list[i][j]))

        # fill in device_array
        file_line = input_file.readline()
        file_line = file_line.replace('\n', '')
        file_line_list = file_line.split()
        for i in range(N):
            for j in range(L):
                device_array[i, j] = bool(int(file_line_list[i][j]))

##        print(outlet_array) ##
##        print(device_array) ##
##        print('') ##

        best_num_flips = L + 1
        for device_i in range(N):
            possible = True
            device_bool_array = np.zeros((N), dtype = np.int)
            flip_array = np.logical_xor(outlet_array[0, :], device_array[device_i, :])
            num_flips = flip_array.sum()
            if num_flips > best_num_flips:
                continue
            device_bool_array[device_i] = 1
            for outlet_i in range(N - 1):
                if possible == False:
                    break
                flipped_outlet_array = np.logical_xor(flip_array, outlet_array[outlet_i + 1, :])
                for device_j in range(N):
                    check_array = np.logical_xor(flipped_outlet_array, device_array[device_j, :])
                    if check_array.sum() == 0 and device_bool_array[device_j] == 0:
                        device_bool_array[device_j] = 1
                        break
                    elif device_j == N - 1:
                        possible = False
                        break
            if possible == True:
                best_num_flips = num_flips*1

        if best_num_flips == L + 1:
            output_file.write('Case #' + str(case_num) + ': NOT POSSIBLE' + '\n')
        else:
            output_file.write('Case #' + str(case_num) + ': ' + str(best_num_flips) + '\n')
        print(case_num)
        case_num += 1
        
    output_file.close()











