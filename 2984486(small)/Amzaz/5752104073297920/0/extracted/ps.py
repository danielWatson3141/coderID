
def process_game():
    N = int(raw_input())
    r = map(int, raw_input().split())
    count = 0
    for i, e in enumerate(r):
        if i == e:
            count += 1
    if count <= 1:
        print "GOOD"
    else:
        print "BAD"

for i in xrange(1, int(raw_input()) + 1):
    print "Case #%d:" % (i),
    process_game()
