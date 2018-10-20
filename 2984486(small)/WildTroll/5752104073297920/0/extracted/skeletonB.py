import os

def solve(f):
    a1 = 0
    a2 = 0
    a3 = 0
    k = [i for i in range(0,1000)]
    n = f.readline()
    d = f.readline()
    val = [int(i) for i in d.split(' ')]
    v = [abs(k[i]-val[i]) for i in range(0,1000)]
    y = [k[i]-val[i] for i in range(0,1000)]
    x = 10540.9255
    s = 31.6228
    avg = 499.5
    s1 = 0
    s2 = 0
    s3 = 0
    s4 = 0
    for i in range(0, 250):
        s1 += val[i]
    for i in range(250, 500):
        s2 += val[i]
    for i in range(500,750):
        s3 += val[i]
    for i in range(750,1000):
        s4 += val[i]
    if (abs(s1-s2) > 1.15*x) or (abs(s1-s3) > 1.15*x) or (abs(s1-s4) > 1.15*x) or (abs(s2-s3) > 1.15*x) or (abs(s2-s4) > 1.15*x) or (abs(s4-s3) > 1.15*x):
        a3 += 1
        return "BAD"
    return "GOOD", a3

    
if __name__ == "__main__":
    input_filename = 'C-small-attempt5.in'
    output_filename = 'out0.txt'
 
    f_in = open(input_filename)
    counter = int(output_filename.split('.')[0][-1])
    while os.path.isfile(output_filename):
        counter += 1
        output_filename = output_filename.split(str(counter - 1) + '.')[0] + str(counter) + '.txt'
    f_out = open(output_filename, 'a')
 
    test_cases = int(f_in.readline())
    g = 0
    for i in range(test_cases):
        ans = solve(f_in)
        f_out.write('Case #' + str(i + 1) +': ' + str(ans) + '\n')
    print g
    f_in.close()
    f_out.close()
    print "done"
