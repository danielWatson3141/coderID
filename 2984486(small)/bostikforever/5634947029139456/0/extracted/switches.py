import sys
import copy

def number_of_set_bits(integer):
    return bin(integer).count("1")

def check_bits(initial, target):
    if set(initial) == set(target):
        return 0
    min_diff = float('inf')
    checker = initial[0]
    rest = initial[1:]
    target_set = set(target)
    for i in target:
        diff = i^checker #get the different bits
        rest_copy = [k^diff for k in rest]
        set_diff = target_set - set(rest_copy)
        #print set_diff, i
        if len(set_diff) == 1 and list(set_diff)[0] == i:
            #print "Got here"
            min_diff = min(min_diff, number_of_set_bits(diff))
            #print min_diff
            #print bin(diff)
    if min_diff < float('inf'):
        return min_diff
    return "NOT POSSIBLE"


if __name__ == "__main__":
    output_file = open("%s.%s"%(sys.argv[1].split(".")[0],"out"),"w")
    file_name = sys.argv[1]
    input_file = open(file_name)
    case_count = int(input_file.readline())
    for i in xrange(case_count):
        specs = input_file.readline()
        initial = map(lambda x: int(x,2), input_file.readline().strip().split(" "))
        target = map(lambda x: int(x,2), input_file.readline().strip().split(" "))
        #print initial, target
        #result = time(C, F, X, 2)
        result = check_bits(initial, target)
        output_file.write("Case #%s: %s\n"%(i+1, result))
    output_file.close()
    input_file.close()
    print "Done!"