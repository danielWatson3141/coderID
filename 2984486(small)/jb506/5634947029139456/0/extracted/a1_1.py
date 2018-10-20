import sys

ROWS_PER_TEST = 3
import itertools
import sys

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
        for row in self.output_rows:
            print("Case #%d: %s" %(self.counter, row))
            self.counter += 1


class TestCase():
    def __init__(self):
        self.init_flows = []
        self.required_flows = []
        self.num_flows = 0
        self.num_devices = 0

    def parse_lines(self, lines):
        temp_flows = lines[1].split(" ")
        for temp in temp_flows:
                self.init_flows.append([int(flowchar) for flowchar in temp])
        temp_flows = lines[2].split(" ")
        for temp in temp_flows:
                self.required_flows.append([int(flowchar) for flowchar in temp])
        self.num_flows = int(lines[0].split(" ")[1])
        self.num_devices = int(lines[0].split(" ")[0])

    def play(self):
        current_flows = self.init_flows[:]

        rows = [j for j in range(0, self.num_flows)]

        for i in range(0, self.num_flows):
            if i == 0:
                if self.can_match(current_flows, self.required_flows):
                    return 0
            combos = itertools.combinations(rows, i)
            for combo in combos:
                test_flows = current_flows[:]
                for combo_part in combo:
                    test_flows = self.flip_flows(test_flows, combo_part)
                if self.can_match(test_flows, self.required_flows):
                    return i

        return -1


    def flip_flows(self, flows, index):
        # in form of [[1,0,0], [1,1,1], [1,1,0]]
        newflows = []
        for flow in flows:
            tempflow = []
            for i in range(0, len(flows[0])):
                if i != index:
                    tempflow.append(flow[i])
                else:
                    tempflow.append((flow[i] + 1) % 2)
            newflows.append(tempflow)
        return newflows


    def can_match(self, flowsone, flowstwo):
        good = True
        for flow in flowsone:
            if flow not in flowstwo:
                good = False
                break
        return good



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
        result = test_case.play()
        if result == -1:
            return str("NOT POSSIBLE")
        else:
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