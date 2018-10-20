from random import choice
i = 0
while True:
    i += 1
    fout = open('C%s.out' % i,'w+')
    for case in range(120):
        print >>fout, "Case #%s: %s" % ( (case +1), choice(["GOOD","BAD"]))

