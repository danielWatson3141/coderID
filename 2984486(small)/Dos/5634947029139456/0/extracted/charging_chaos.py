"""
Created on 26/apr/2014

@author: dosdos

Problem A. Charging Chaos
https://code.google.com/codejam/contest/2984486/dashboard#s=p0



***Sample***

Input
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01

Output
Case #1: 1
Case #2: NOT POSSIBLE
Case #3: 0

"""
import unittest
import itertools


class ChargingChaos(object):

    def __init__(self, input_file_name=None, output_file_name=None, log_file_name=None):
        self.input_file_name = input_file_name
        self.output_file_name = output_file_name
        self.log_file_name = log_file_name

    # file I/O
    def read_word(self, file):
        return next(file).strip()

    def read_int(self, file, b=10):
        return int(self.read_word(file), b)

    def read_words(self, file, d=' '):
        return self.read_word(file).split(d)

    def read_ints(self, file, b=10, d=' '):
        return [int(x, b) for x in self.read_words(file, d)]


    def switch(self, l, i):
        l2 = []
        for elem in l:
            sl = list(elem)
            sl[i] = '0' if sl[i] == '1' else '1'
            l2.append(''.join(sl))
        return l2

    def solve_small(self):

        # create I/O files
        input_file = open(self.input_file_name, 'r')
        output_file = open(self.output_file_name, "w")
        log_file = open(self.log_file_name, "w")

        # read file size
        T = self.read_int(input_file)

        log_file.write("There are %d cases to solve! :)\n" % T)

        # iterate on each case
        for case in range(T):

            log_file.write("\nCase #%d: \n" % (case+1) )

            # get problem data
            line = self.read_ints(input_file)
            N = line[0]
            L = line[1]
            initial = self.read_words(input_file)
            required = self.read_words(input_file)

            # initial.sort()
            required.sort()

            log_file.write("%s %s %s %s" % (N, L, initial, required))

            # calculate index to switch
            to_switch = range(L)
            switch_subsets = []
            for L in range(0, len(to_switch)+1):
                for subset in itertools.combinations(to_switch, L):
                    switch_subsets.append(subset)

            for to_s in switch_subsets:
                new_initial = initial
                for s in to_s:
                    print(new_initial,s)
                    new_initial = self.switch(new_initial,s)
                new_initial.sort()
                if new_initial == required:
                    print(len(to_s))
                    output_file.write("Case #%d: %d\n" % (case+1,len(to_s)))
                    break
            else:
                print("NOT POSSIBLE")
                output_file.write("Case #%d: %s\n" % (case+1,"NOT POSSIBLE"))


        # close I/O files
        input_file.close()
        output_file.close()
        log_file.close()


class Test(unittest.TestCase):
    def setUp(self):
        self.problem_A = ChargingChaos()

    def test_switch(self):
        self.assertEqual(self.problem_A.switch(['101'],1),['111'])
        self.assertEqual(self.problem_A.switch(['01', '10', '11'],0),['11', '00', '01'])
        self.assertEqual(self.problem_A.switch(['101', '111'],0),['001', '011'])

    def test_solve_small(self):
        # problem_A = ChargingChaos("A-sample.in", "A-sample.out", "A-log.out")
        problem_A = ChargingChaos("A-small-attempt0.in", "A-small-attempt0.out", "A-log.out")
        # problem_A = ChargingChaos("A-large-attempt0.in", "A-large-attempt0.out", "A-log.out")
        problem_A.solve_small()


if __name__ == '__main__':
    unittest.main()
