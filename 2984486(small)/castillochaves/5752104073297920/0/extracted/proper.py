def solve(f):
    f.readline()
    sequence = map(int, f.readline().split())
    is_good = 3
    if sum(sequence[:150]) < 150 * 500 * 0.98:
        is_good -= 1
    if sum(sequence[:200]) < 200 * 500 * 0.98:
        is_good -= 1
    if sum(sequence[:250]) < 250 * 500 * 0.98:
        is_good -= 1
    if sum(sequence[:300]) < 300 * 500 * 0.98:
        is_good -= 1
    if sum(sequence[:350]) < 350 * 500 * 0.98:
        is_good -= 1
    if sum(sequence[:400]) < 400 * 500 * 0.98:
        is_good -= 1
    if sum(sequence[:450]) < 450 * 500 * 0.98:
        is_good -= 1
    if is_good < 0:
        return "BAD"
    return "GOOD"


test_answer = {
    1: "",
    2: "",
}

if __name__ == '__main__':
    import sys
    test = False
    try:
        file_name = sys.argv[1]
    except IndexError:
        file_name = 'test.txt'
        test = True
    if len(sys.argv) > 1:
        file_name = sys.argv[1]
    with open(file_name) as f:
        T = int(f.readline())
        good = 0
        bad = 0
        for i in range(1, T + 1):
            answer = solve(f)
            if test:
                assert answer == test_answer[i]
            else:
                if answer == "BAD":
                    bad += 1
                else:
                    good += 1
                print "Case #%d: %s" % (i, answer)
        print >> sys.stderr, good, bad
