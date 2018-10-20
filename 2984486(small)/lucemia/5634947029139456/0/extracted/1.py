import StringIO
import sys

def do_flip(A, l):
    return [a[:l] + ('0' if a[l] == '1' else '1') + a[l+1:] for a in A]

def subset(A, l):
    return set(a[:l+1] for a in A)

def main(input):
    T = int(input.readline())

    for i in range(T):
        print "Case #%s:"% (i+1),

        N, L = map(int, input.readline().split())

        A = input.readline().split()
        B = set(input.readline().split())

        if set(A) == set(B):
            print 0
            continue

        can_flip = []
        step = 0
        for l in xrange(L):
            As = len([a[l] for a in A if a[l] == '1'])
            Bs = len([b[l] for b in B if b[l] == '1'])

            # print A,B, As, Bs
            if As != Bs and As+Bs != N:
                # print 'NOT POSSIBLE'
                can_flip = []
                break

            if As == Bs:
                can_flip.append(l)
            else:
                # flip is required
                step += 1
                A = do_flip(A, l)

        # print can_flip,
        possibleA = []
        possibleA.append((A, step))

        for l in can_flip:
            # print possibleA
            sB = subset(B, l)

            should_remove_A = []
            should_add_A = []
            for A, step in possibleA:
                sA = subset(A, l)
                tA = do_flip(A, l)
                stA = subset(tA, l)

                if sA == sB:
                    pass
                else:
                    # print '-1'
                    # print 'should remove', A, sA, sB
                    should_remove_A.append(A)

                if stA == sB:
                    # print 'should add'
                    # print '+1'
                    should_add_A.append((tA, step+1))

            # print 'update', possibleA, should_remove_A, should_add_A
            possibleA = [k for k in possibleA if k[0] not in should_remove_A]
            possibleA.extend(should_add_A)
            # print possibleA

        possibleA = [k for k in possibleA if set(k[0]) == B]
        if possibleA:
            # print set(possibleA[0][0]) == set(B)

            possibleA.sort(key=lambda i:i[1])
            print possibleA[0][1]
        else:
            print 'NOT POSSIBLE'

input = sys.stdin
main(input)
