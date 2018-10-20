

def findSol(outlets, devs):
    sample=[e for e in outlets][0]
    possible={sample^e for e in devs}
    answers={e for e in possible if flip(outlets,e)==devs}
    sols={bin(e).count('1') for e in answers}
    sols.add(100)
    return min(sols)

def flip(outlets, config):
    return {e^config for e in outlets}

def fromStrings():
    ignore=input()
    outlets={int(e,2) for e in input().split()}
    devs={int(e,2) for e in input().split()}
    reply=findSol(outlets,devs)
    if reply==100:
        reply="NOT POSSIBLE"
    return str(reply)


if __name__=="__main__":
    cases=int(input())
    for i in range(1,cases+1):
        print("Case #"+str(i)+": "+fromStrings())
