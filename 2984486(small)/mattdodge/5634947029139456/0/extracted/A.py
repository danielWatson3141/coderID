from copy import copy


def out(case_num, st):
    print("Case #%d: %s" % (case_num, st))


def is_good(have, want):
    return set(have) == set(want)


def switch_have(old_have, pos):
    new_have = []
    for old_st in old_have:
        new_have.append(old_st[:pos] +
                        str(1 - int(old_st[pos])) +
                        old_st[pos + 1:])
    return new_have


def run_case(case_num, input):
    N, L = [int(x) for x in input.readline().rstrip("\n").split(" ")]
    have = input.readline().rstrip("\n").split(" ")
    want = input.readline().rstrip("\n").split(" ")

    num_ones_have = [sum([int(x[i]) for x in have]) for i in range(L)]
    num_ones_want = [sum([int(x[i]) for x in want]) for i in range(L)]

    switches_needed = 0

    possible_haves = [(0, have)]

    for i in range(L):
        h = num_ones_have[i]
        w = num_ones_want[i]

        if h == w and (N - h) != w:
            # we have the right number, we can't switch
            continue
        elif (N - h) == w and h != w:
            # we have a good number, but we should switch
            new_possible = []
            for poss in possible_haves:
                new_possible.append((poss[0] + 1, switch_have(poss[1], i)))

            possible_haves = copy(new_possible)
        elif (N - h) != w and N != w:
            # it won't work
            out(case_num, "NOT POSSIBLE")
            return
        else:
            # we can switch or we don't have to...
            new_possible = []
            for poss in possible_haves:
                new_possible.append(poss)
                new_possible.append((poss[0] + 1, switch_have(poss[1], i)))

            possible_haves = copy(new_possible)

    if is_good(have, want):
        out(case_num, switches_needed)
    else:
        min_switches = L + 1
        for poss in possible_haves:
            if is_good(poss[1], want) and poss[0] < min_switches:
                min_switches = poss[0]

        if min_switches <= L:
            out(case_num, min_switches)
        else:
            out(case_num, "NOT POSSIBLE")


# GCJ boiler plate...call run_case for each case given
if __name__ == '__main__':
    import sys
    sys.setrecursionlimit(10000)
    with sys.stdin as f:
        [run_case(i + 1, f) for i in range(int(f.readline()))]
