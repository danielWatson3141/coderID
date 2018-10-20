#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import argparse
import difflib
from collections import defaultdict


class Case(object):

    def __init__(self, f_out, i, N, edges):
        self.f_out = f_out
        self.i = i
        self.N = N
        self.edges = edges
        self.node_dict = None
        self.node_degree = None

    def count_node_degree(self):
        node_dict = defaultdict(list)
        for e in self.edges:
            x = e[0]
            y = e[1]
            node_dict[x].append(y)
            node_dict[y].append(x)
        self.node_dict = node_dict
        node_degree = defaultdict(int)
        for e in self.node_dict:
            node_degree[e] = len(self.node_dict[e])
        self.node_degree = node_degree
        return None

    ###################### modify here #####################
    def get_result(self):
        self.count_node_degree()
        degree_2 = 0
        for k, v in self.node_degree.items():
            if v == 2:
                degree_2 += 1

        need_remove = degree_2 - 1
        return need_remove
    ########################################################

    def run(self):
        result = self.get_result()
        ###################### modify here #####################
        self.f_out.write('Case #%d: ' % self.i)
        self.f_out.write('%d\n' % result)
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

    for i in range(T):
        ############### modify here #######################
        N = read_line(f_in, int)[0]
        edges = []
        for j in range(N - 1):
            x, y = read_line(f_in, int)
            edges.append((x, y))
        c = Case(f_out, i + 1, N, edges)
        ##################################################
        c.run()
        del c
    f_in.close()
    f_out.close()

    check_result(in_path, an_path, out_path)

    return None


if __name__ == '__main__':
    main()

