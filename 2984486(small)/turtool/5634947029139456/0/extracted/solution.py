from itertools import chain, combinations

formatStringOutput = "Case #{0}: {1}"

def main():
        with open('test.in', 'r') as f:
                data = f.readlines()
        numberOfDataSets = int(data[0])
        data = data[1:]
        dataSets = []
        for x in xrange(len(data)/3):
                dataSets.append(([int(x) for x in data[0].strip().split()],[x for x in data[1].strip().split()],[x for x in data[2].strip().split()]))
                data = data[3:]
        probNum = 0
        for x in dataSets:
                probNum += 1
                solution = solve(probNum, x[0], x[1], x[2])
                if solution is not None:
                        print str.format(formatStringOutput, probNum, len(solution))
                else:
                        print str.format(formatStringOutput, probNum, "NOT POSSIBLE")

def solve(probNum, limits, l1, l2):
        l2Set = set(l2)
        switchCombinations = powerset_generator(range(limits[1]))
        if l1 == l2:
                return []
        for combination in switchCombinations:
                ll = [x for x in l1]
                for s in combination:
                        switch(s, ll)
                if set(ll) == l2Set:
                        return combination
        return None
                        

def switch(position, l1):
        p = 0
        for y in l1:
                if y[position] == '0':
                        tmp = list(y)
                        tmp[position] = '1'
                        l1[p] = "".join(tmp)
                elif y[position] == '1':
                        tmp = list(y)
                        tmp[position] = '0'
                        l1[p] = "".join(tmp)
                p += 1

def powerset_generator(i):
    for subset in chain.from_iterable(combinations(i, r) for r in range(len(i)+1)):
        yield set(subset)

if __name__ == "__main__":
	main()
