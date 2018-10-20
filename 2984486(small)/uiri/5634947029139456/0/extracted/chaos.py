import sys, copy

input = sys.stdin.readlines()
input.reverse()
cases = int(input.pop())
for case in xrange(1,cases+1):
    devicesvoltages = input.pop().strip().split(' ')
    voltages = int(devicesvoltages.pop())
    numdevices = int(devicesvoltages.pop())
    outlets = input.pop().strip().split(' ')
    devices = input.pop().strip().split(' ')
    devicecollection = []
    devicecollection.append(([], devices))
    results = []
    for i in xrange(voltages+1):
        newdevicecollection = []
        for devicetuple in devicecollection:
            tryoutlets = copy.copy(outlets)
            trydevices = copy.copy(devicetuple[1])
            wtf = False
            for device in trydevices:
                if len(tryoutlets) == 0:
                    wtf = True
                if device in tryoutlets:
                    tryoutlets.remove(device)
            if not wtf and len(tryoutlets) == 0:
                results.append(len(devicetuple[0]))
            try:
                k = devicetuple[0][-1]+1
            except IndexError:
                k = 0
            for j in range(k,voltages):
                newdevices = []
                for device in devicetuple[1]:
                    if device[j] == '0':
                        newdevices.append(device[:j] + '1' + device[j+1:])
                    if device[j] == '1':
                        newdevices.append(device[:j] + '0' + device[j+1:])
                switchstack = copy.copy(devicetuple[0])
                switchstack.append(j)
                newdevicecollection.append((switchstack, newdevices))
        devicecollection = newdevicecollection
    result = 'NOT POSSIBLE'
    if len(results):
        result = str(min(results))
    print "Case #"+str(case)+": "+result
