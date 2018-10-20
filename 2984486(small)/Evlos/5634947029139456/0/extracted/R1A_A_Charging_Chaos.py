#!/usr/bin/python
# -*- coding: utf-8 -*-

import math
import itertools


class GoogleCodeJam():
    def __init__(self):
        self.file_out = None
        self.data = None

        self.input_data()

    def input_data(self):
        file_in = open(raw_input('Input Filename: '))
        self.file_out = open('result.out', 'w+')

        self.data = file_in.readlines()
        self.data.reverse()
        file_in.close()

    def pop_data(self, do_split=False):
        if do_split:
            return self.data.pop().replace('\n', '').split(' ')
        else:
            return self.data.pop().replace('\n', '')


class Main(GoogleCodeJam):
    @staticmethod
    def compare(a, b):
        result = list(set(a).difference(set(b)))
        # print result
        if result:
            return False
        else:
            return True

    def run(self):
        t = int(self.pop_data())

        for i in xrange(0, t):
            val_n, val_l = self.pop_data(True)
            outlets = self.pop_data(True)
            devices = self.pop_data(True)

            is_find = False
            result = 0
            if self.compare(outlets, devices):
                is_find = True
            else:
                outlets_no = []
                for j in xrange(0, int(val_l)):
                    outlets_no.append(j)
                # print 'outlets_no:', outlets_no

                for j in xrange(1, int(val_l) + 1):
                    result = j
                    # print 'count: %i' % result

                    current = list(itertools.combinations(outlets_no, j))
                    # print 'current:', current

                    for x in current:
                        outlets_tmp = outlets[:]
                        # print 'outlets_tmp:', outlets_tmp
                        for y in x:
                            # print 'y:', y
                            for k in xrange(0, len(outlets_tmp)):
                                # if int(outlets_tmp[k][y]) == 1:
                                #     outlets_tmp[k][y] = 0
                                # else:
                                #     outlets_tmp[k][y] = 1
                                if outlets_tmp[k][y] == '0':
                                    outlets_tmp[k] = outlets_tmp[k][:y] + '1' + outlets_tmp[k][y+1:]
                                else:
                                    outlets_tmp[k] = outlets_tmp[k][:y] + '0' + outlets_tmp[k][y+1:]
                                # print 'outlets_tmp[k]:', outlets_tmp[k]

                        if self.compare(outlets_tmp, devices):
                            is_find = True
                            break

                    if is_find:
                        break

            if not is_find:
                result = 'NOT POSSIBLE'

            output = 'Case #%i: %s' % (i + 1, result)
            self.file_out.write('%s\r\n' % output)
            print output

        self.file_out.close()

if __name__ == '__main__':
    Main().run()
