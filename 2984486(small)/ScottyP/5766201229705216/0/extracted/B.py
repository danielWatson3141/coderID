import numpy as np
import math
import time
import copy


input_file_name = './B-small-attempt0.in'
output_file_name = './B-small.out'

def biggest_bin_tree(list_of_lists, i, j):
    children = copy.deepcopy(list_of_lists[i])
    if len(children) == 1:
        return 1
    if j in children:
        children.remove(j)
    if len(children) == 1:
        return 1
    else:
        score_list = []
        for child in children:
            score_list.append(biggest_bin_tree(list_of_lists, child, i))
        score_list.sort()
        return (1 + score_list[-1] + score_list[-2])
        

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
        N = int(file_line)

        list_of_lists = []
        for i in range(N):
            list_of_lists.append([])

        for i in range(N - 1):
            file_line = input_file.readline()
            file_line = file_line.replace('\n', '')
            file_line_list = file_line.split()
            X = int(file_line_list[0])
            Y = int(file_line_list[1])
            list_of_lists[X - 1].append(Y - 1) # change to index from 0
            list_of_lists[Y - 1].append(X - 1)

        best_num_nodes = 0

        for i in range(N):
            num_nodes = biggest_bin_tree(list_of_lists, i, N + 1)
            if num_nodes > best_num_nodes:
                best_num_nodes = num_nodes

        num_nodes_to_delete = N - best_num_nodes

        output_file.write('Case #' + str(case_num) + ': ' + str(num_nodes_to_delete) + '\n')
        print(case_num)
        case_num += 1
        
    output_file.close()











