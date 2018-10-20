import sys

def ReadIn():
    cases = int(input().strip())
    for c in range(1, cases + 1):
        N, L = [int(x) for x in input().split()]
        outlets = input().split()
        devices = input().split()
        yield c, outlets, devices

def calcSwitchs(outlet, device):
    switchs = ''.join('0' if x == y else '1' for x,y in zip(outlet, device))
    #print('switchs = %s' % switchs)
    return switchs

def performSwitchs(outlets, switchs):
    ret = []
    change = {}
    change['0'] = {'0':'0', '1':'1'}
    change['1'] = {'0':'1', '1':'0'}
    for outlet in outlets:
        ret.append(''.join(change[s][o] for o, s in zip(outlet, switchs)))
    return ret
    

def match(outlets, devices, switch):
    newOutlets = performSwitchs(outlets, switch)
    #print('outlets %s => %s' % (outlets, newOutlets))
    newOutlets.sort()
    return newOutlets == devices

def Solve(outlets, devices):
    devices.sort()
    L = len(outlets[0])
    ret = L + 10
    for outlet in outlets:
        for device in devices:
            switchs = calcSwitchs(outlet, device)
            switchsOn = sum(c == '1' for c in switchs)
            if match(outlets, devices, switchs):
                ret = min(ret, switchsOn)
    if ret == L + 10: return 'NOT POSSIBLE'
    else: return ret

if __name__ == '__main__':
    for case, outlets, devices in ReadIn():
        print('Case #%d: %s' % (case, Solve(outlets, devices)))