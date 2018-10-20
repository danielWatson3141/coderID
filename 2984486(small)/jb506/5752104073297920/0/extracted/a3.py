import sys

ROWS_PER_TEST = 2
NAME = "a3"
import itertools
import sys
import datetime
import math

def start():
    magic = Magic()
    magic.parse_input()
    magic.run()
    magic.print_output()


class Base():
    def __init__(self):
        self.counter = 1
        self.input_rows = []
        self.num_tests = 0
        self.output_rows = []

    def parse_input(self):
        self.num_tests = int(input())
        for x in range(0, self.num_tests):
            line = input()
            self.input_rows.append(line)

    def run(self):
        pass

    def print_output(self):
        #outfile = open("C:\\Users\\jb\\PycharmProjects\\codejam\\codejam\\output\\" + NAME + str(datetime.datetime.now()), 'w')
        for row in self.output_rows:
            print("Case #%d: %s" %(self.counter, row))
            #outfile.write("Case #%d: %s" %(self.counter, row))
            self.counter += 1


class TestCase():
    def __init__(self):
        self.nums = []
        self.num_numbers = 0

    def parse_lines(self, lines):
        self.num_numbers = int(lines[0])
        self.nums = [int(num) for num in lines[1].split(" ")]

    def detect(self):
        count = 0
        for item in self.nums[0:math.floor(len(self.nums)/2)]:
            if item < len(self.nums) / 2:
                count += 1
        if count < (250):
            return "BAD"
        else:
            return "GOOD"



class Magic(Base):

    def __init__(self):
        super().__init__()
        self.test_cases = []

    def parse_input(self):
        self.num_tests = int(input())
        for x in range(0, self.num_tests*ROWS_PER_TEST):
            line = input()
            self.input_rows.append(line)


    def run_case(self, test_case):
        result = test_case.detect()
        return str(result)




    def run(self):
        for x in range(0, self.num_tests):
            new_test = TestCase()
            new_test.parse_lines(self.input_rows[0 + (x * ROWS_PER_TEST) : ROWS_PER_TEST + (x * ROWS_PER_TEST)])
            self.test_cases.append(new_test)

        for test_case in self.test_cases:
            self.output_rows.append(self.run_case(test_case))


if __name__ == "__main__":
    start()