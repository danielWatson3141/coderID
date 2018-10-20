from codejam import readfile, takeby

problems = takeby(3, readfile()[1:])

def sum_digits(num):
    num = bin(num)[2:]
    return sum(int(a) for a in num)

def score_problem(counts, devices, outlets):
    devices = [int(x,2) for x in  devices.split()]
    outlets = [int(x,2) for x in outlets.split()]
    outlets = set(outlets)
    fail = False
    min_score = 1000
    for outlet in outlets:
        for device in devices:
            trial = device ^ outlet
            score = sum_digits(trial)
            for device2 in devices:
                if device2 ^ trial not in outlets:
                    fail = True
                    break
            if fail:
                fail = False
                continue
            if score < min_score: min_score = score
    if min_score == 1000:
        return "NOT POSSIBLE"
    return min_score

for i, problem in enumerate(problems, 1):
    score = score_problem(problem[0],problem[1],problem[2])
    print "Case #%d: %s" % (i, score)
