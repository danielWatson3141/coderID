__author__ = 'Syed Raziq Mohideen'

inputFile = open("A-small-attempt1.in", 'r')

count =  int(inputFile.readline())

for y in range(1, count+1):
    devices, switches = [int(i) for i in inputFile.readline().split()]

    deviceRequirements = [int(i, 2) for i in inputFile.readline().split()]
    availableOutlets = [int(i, 2) for i in inputFile.readline().split()]

    deviceRequirements.sort()

    leastPossibleSwitches = "NOT POSSIBLE"

    for z in range(0, 2**switches):
        g = lambda x: z ^ x
        temporaryOutlets = map(g, availableOutlets)
        temporaryOutlets.sort()

        if temporaryOutlets == deviceRequirements:
            if leastPossibleSwitches == "NOT POSSIBLE":
                leastPossibleSwitches = ("{0:b}".format(z)).count('1')
            elif ("{0:b}".format(z)).count('1') < leastPossibleSwitches:
                leastPossibleSwitches = ("{0:b}".format(z)).count('1')

    #print deviceRequirements
    #print availableOutlets

    print "Case #%s: %s" % (y, leastPossibleSwitches)

