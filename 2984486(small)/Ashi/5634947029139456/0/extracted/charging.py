#!/usr/bin/python

def flip(required, original, l, switch, total):
    changed = []
    if switch < l:
        for i in range(0, len(original)):
            temp = list(original[i])
            temp[switch] = '0' if temp[switch] == '1' else '1'
            newsetting = "".join(temp)
            changed.append(newsetting)
        found = True
        for i in range(0, len(original)):
            if required[i] not in changed:
                found = False
                break
        if found == True:
            return total + 1
        else:
            res = 100000
            for i in range(switch, l):
                res = min(flip(required, changed, l, i+1, total+1), res)
            return res
    return 100000
        
if __name__ == "__main__":
    t = int(raw_input())
    cases = t
    res = []
    while t > 0:
        n, l = raw_input().split(" ")
        n = int(n)
        l = int(l)
        actual = raw_input().split(" ")
        required = raw_input().split(" ")
        total = 100000
        found = True
        for i in range(0, len(actual)):
            if required[i] not in actual:
                found = False
                break
        if found == True:
            res.append(0)
        else:
            for i in range(0, l):
                total = min(flip(required, actual, l, i, 0), total)
            if total == 100000:
                total = "NOT POSSIBLE"
            res.append(total)
        t = t - 1
    for i in range(1, cases+1):
        print "Case #" + str(i) + ":", str(res[i-1])
