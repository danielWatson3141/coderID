T = int(raw_input())
for t in range(T):
    N, L = map(int, raw_input().split(" "))
    start = map(lambda x: int(x, 2), raw_input().split(" "))
    goal = set(map(lambda x: int(x, 2), raw_input().split(" ")))
    ans = 9999
    x = start[0]
    for y in goal:
        z = x^y
        g = [xx^z for xx in start]
        if set(g) == goal:
            ans = min(ans, format(z, 'b').count('1'))
    if ans == 9999:
        ans = "NOT POSSIBLE"
    print "Case #%d:" % (t+1), ans
