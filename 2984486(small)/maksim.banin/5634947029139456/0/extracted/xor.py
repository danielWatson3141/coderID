#!/usr/bin/env python


def satisfies(toggle, frm, to):
    f = map(lambda x: x ^ toggle, frm)
    return sorted(to) == sorted(f)


def count_bits(val):
    return bin(val).count("1")

if __name__ == '__main__':
    fin = open('xor.in')
    TEST_COUNT = int(fin.readline())
    # print TEST_COUNT

    fout = open('xor.out', 'w')
    for test in range(TEST_COUNT):
        n, l = fin.readline().strip().split()
        print n, l
        has = map(lambda s: int(s, 2), fin.readline().strip().split(' '))
        # print alice[0]
        wants = map(lambda s: int(s, 2), fin.readline().strip().split(' '))

        print has, wants

        best_xor = None

        for w in wants:
            for h in has:
                xor = w ^ h
                if satisfies(xor, has, wants) and (best_xor is None or count_bits(xor) < count_bits(best_xor)):
                    best_xor = xor

        if best_xor is None:
            IMPOSSIBLE = "NOT POSSIBLE"
            answer = 'Case #%d: %s' % (test + 1, IMPOSSIBLE)
        else:  
            answer = 'Case #%d: %s' % (test + 1, count_bits(best_xor))
        print answer
        fout.write(answer + '\n')

    fout.close()
