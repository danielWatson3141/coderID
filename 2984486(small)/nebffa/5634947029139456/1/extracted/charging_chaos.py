input_file = "A-large.in"
output_file = "charging_chaos.out"

inputs = []
with open(input_file, 'r') as input:
    n_cases = int(input.readline())

    for i in range(n_cases):
        N, L = [int(i) for i in input.readline().split(' ')]
        outlet_throughputs = [i.strip('\n') for i in input.readline().split(' ')]
        device_requirements = [i.strip('\n') for i in input.readline().split(' ')]

        inputs.append([N, L, outlet_throughputs, device_requirements])


def output_to_device_map(output_throughput, device_requirement):
    mapping = []
    for i in range(len(output_throughput)):
        mapping.append(output_throughput[i] != device_requirement[i])

    return mapping


def apply_mapping(mapping, code):
    new_code = []
    for i in range(len(code)):
        if mapping[i]:
            new_code.append(str(1 - int(code[i])))
        else:
            new_code.append(code[i])

    return ''.join(new_code)



with open(output_file, 'w') as output:
    case_number = 0
    for case in inputs:
        case_number += 1
        
        N = case[0]
        L = case[1]
        outlet_throughputs = case[2]
        device_requirements = case[3]


        best_answer = L + 1
        for i in range(N):
            mapping = output_to_device_map(outlet_throughputs[0], device_requirements[0])

            remaining_outlets = outlet_throughputs[1:]
            mapped_remaining_outlets = [apply_mapping(mapping, outlet) for outlet in remaining_outlets]
            mapped_remaining_outlets = sorted(mapped_remaining_outlets)

            remaining_devices = device_requirements[1:]

            solution_found = True
            for j in range(len(remaining_devices)):
                if remaining_devices[0] in mapped_remaining_outlets:
                    mapped_remaining_outlets.remove(remaining_devices.pop(0))
                else:
                    solution_found = False
            
            if solution_found:
                cur_answer = len([i for i in mapping if i == True])
                if best_answer > cur_answer:
                    best_answer = cur_answer

            # rotate the list of outlets
            outlet_throughputs = outlet_throughputs[1:] + [outlet_throughputs[0]]

        if best_answer == L + 1:
            answer = "NOT POSSIBLE"
        else:
            answer = best_answer

        output.write('Case #{case_number}: {answer}\n'.format(case_number=case_number, answer=answer))
