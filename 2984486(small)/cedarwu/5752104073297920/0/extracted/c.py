#!/usr/bin/env python
# coding:utf-8

def process_file(file):
    f = open(file)
    text = f.read()
    f.close()
    lines = text.split('\n')
    return lines

def process_lines(lines):
    cases = []
    n = int(lines[0].split(' ')[0])
    per = 2
    for i in range(1, n+1):
        i = per*(i-1) + 1

        line = int(lines[i])
        c = [int(x) for x in lines[i+1].split(' ')]
        cases.append(c)
    return cases

def process_case(case):
    #print case
    total = sum(case)
    if sum(case[len(case)/2:]) > total*0.5061:
        return "BAD"
    else:
        return "GOOD"

def main():
    import sys
    if len(sys.argv) == 1:
        filename = 'x.in'
    else:
        filename = sys.argv[1]
    lines = process_file(filename)
    cases = process_lines(lines)
    for k, v in enumerate(cases):
        case = process_case(v)
        if type(case) == set or type(case) == list:
            case = ' '.join([str(x) for x in case])
        print "Case #%d: %s" % (k + 1, case)

if __name__ == "__main__":
    main()