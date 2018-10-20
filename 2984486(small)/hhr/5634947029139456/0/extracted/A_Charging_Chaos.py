#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import argparse
import difflib


class Case(object):

    def __init__(self, f_out, i, N, L, initial_flow, target_flow):
        self.f_out = f_out
        self.i = i
        self.N = N
        self.L = L
        self.initial_flow = initial_flow
        self.target_flow = target_flow
        self.sorted_initial_flow = '|'.join(sorted(initial_flow))
        self.sorted_target_flow = '|'.join(sorted(target_flow))
        self.possible = {}


    def replace_str(self, s, k, t):
        return s[:k] + t + s[k+1:]

    def change_bit(self, initiate, k):
        got = []
        for e in initiate:
            kb = e[k]
            if kb == '1':
                kt = '0'
            else:
                kt = '1'
            got.append(self.replace_str(e, k, kt))
        return got

    def change_bit_list(self, initiate):
        r = set()
        for e in initiate:
            e = e.split('|')
            for i in range(self.L):
                got = self.change_bit(e, i)
                got.sort()
                s_got = '|'.join(got)
                r.add(s_got)
        return r

    def change_all(self, initiate):
        possible = {}
        s_target_flow = self.sorted_target_flow
        for i in range(1, self.L + 1):
            if i == 1:
                possible[i] = self.change_bit_list([initiate])
            else:
                possible[i] = self.change_bit_list(possible[i-1])
            if s_target_flow in possible[i]:
                return i
        self.possible = possible
        return 'NOT POSSIBLE'


    ###################### modify here #####################
    def get_result(self):
        if self.sorted_initial_flow == self.sorted_target_flow:
            return '0'
        else:
            return self.change_all(self.sorted_initial_flow)

    ########################################################

    def run(self):
        result = self.get_result()
        ###################### modify here #####################
        self.f_out.write('Case #%d: ' % self.i)
        self.f_out.write('%s\n' % result)
        ########################################################
        return None


def parse_cmd_args():
    parser = argparse.ArgumentParser(description='initiate a Google code jam contest problem')
    parser.add_argument('input', help='input file path')
    args = parser.parse_args()
    input_path = os.path.abspath(args.input)
    return input_path


def read_line(f_in, typ=None):
    if isinstance(f_in, file):
        line = f_in.readline()
    elif isinstance(f_in, (str, unicode)):
        line = f_in
    else:
        raise TypeError('unknown parameter type: %s' % type(f_in))

    tokens = line.strip().split()
    if typ:
        r = [typ(e) for e in tokens]
    else:
        r = tokens
    return r


def read_a_case(f_in, m, func_list):
    r = []
    for i in range(m):
        line = f_in.readline().strip()
        func = func_list[i]
        r.append(func(line))
    return r


def sample_diff(path_a, path_b):
    with open(path_a) as f_a, open(path_b) as f_b:
        a = f_a.readlines()
        b = f_b.readlines()

    d = difflib.Differ()
    diff = d.compare(a, b)
    print ''.join(list(diff))
    return None


def check_result(in_path, an_path, out_path):
    if os.path.basename(in_path) == 'sample.in':
        # comparing sample answers and output
        print '######### comparing sample answers and output #######'
        sample_diff(an_path, out_path)
    else:
        # print the first k lines in output file
        k = 5
        print '######## the fist %d lines of %s #######' % (k, out_path)
        with open(out_path) as out:
            for i in range(k):
                print out.readline(),
    return None


def main():
    in_path = parse_cmd_args()
    out_path = in_path.rstrip('.in') + '.out'
    an_path = in_path.rstrip('.in') + '.an'

    f_in = open(in_path)
    f_out = open(out_path, 'wb')

    T = read_line(f_in, int)[0]
    print T
    def read_int(f_in):
        read_line(f_in, typ=int)

    for i in range(T):
        ############### modify here #######################
        N, L = read_line(f_in, int)
        initial_flow = read_line(f_in)
        target_flow = read_line(f_in)
        # a, initial_flow, target_flow = read_a_case(f_in, 3, [read_int, read_line, read_line])
        # N, L = a

        c = Case(f_out, i + 1, N, L, initial_flow, target_flow)
        ##################################################
        c.run()
        del c
        # break
    f_in.close()
    f_out.close()

    check_result(in_path, an_path, out_path)

    return None


if __name__ == '__main__':
    main()

