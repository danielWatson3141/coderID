from sys import argv, exit
import numpy as np

def get_input(inputfile):

    def read_int():
        return int(inputfile.readline().strip())
    def read_ints():
        return np.array(inputfile.readline().split(), dtype=int)
    def read_bigints(): #For ints that won't fit directly in an int32 array
        line = inputfile.readline().split()
        return np.array(map(lambda x: int(x), line))
    def read_float():
        return float(inputfile.readline().strip())
    def read_floats():
        return np.array(inputfile.readline().split(), dtype=float)
    def read_string():
        return inputfile.readline().strip()
    def read_strings():
        return np.array(inputfile.readline().split(), dtype=object)
    
    abc = read_strings()
    return abc

def solve_problem(outlets, devices, size_stream):

    total_dists = []
    
    for i in range(len(outlets)):
        dist_to_outlet = []
        for device in range(len(devices)):
            curr_dist = [0 for i in range(size_stream)] 
            if outlets[i] != devices[device]:
                for j in range(size_stream):
                    if devices[device][j] != outlets[i][j]:
                        curr_dist[j] = 1
                        
            dist_to_outlet.append(curr_dist)

        total_dists.append(dist_to_outlet)        
    
    sim_dists = {}
    for i in range(len(total_dists)):
        for j in range(len(total_dists[i])):
            if sim_dists.get(str(total_dists[i][j])):
                sim_dists[str(total_dists[i][j])] += 1
            else:
                sim_dists[str(total_dists[i][j])] = 1

    matching_outlets = []

    for key, value in sim_dists.items():
        if value is len(outlets):
            matching_outlets.append(key)

    fewest_switches = None
    # get the smallest amount of switches
    for matching in matching_outlets:
        switches = 0
        for c in matching:
            try:
                switches += int(c)
            except ValueError:
                pass
        if fewest_switches == None or switches < fewest_switches:
            fewest_switches = switches
    
    if len(matching_outlets) > 0:
        return fewest_switches
    else:
        return "NOT POSSIBLE"


if __name__ == "__main__":

    cmd_args = argv[1:]
    inputfile = ""

    if not len(cmd_args) or len(cmd_args) > 2:
        print("Invalid number of args! Exiting")
        exit(1)

    if not cmd_args[0].endswith(".in"):
        print("Invalid inputfile! Exiting")
        exit(1)

    input_filename = cmd_args[0]
    output_filename = input_filename[:-3] + "_out.out"

    inputfile = open(input_filename, "r")
    outputfile = open(output_filename, "w+")
    print("Created file: {}\n".format(output_filename))

    num_cases = int(inputfile.readline().strip())
    
    # solve the cases one-by-one
    for case in range(num_cases):
        input_para = inputfile.readline().split()
        amount_outlets = input_para[0]
        streams = int(input_para[1])
        outlets = inputfile.readline().split()
        devices = inputfile.readline().split()

        solution_str = solve_problem(outlets, devices, streams)

        outputfile.write("Case #{0:}: {1:}\n".format(case+1, solution_str))
        print(("Case #{0:}: {1:}".format(case+1, solution_str)))

    inputfile.close()
    outputfile.close()
