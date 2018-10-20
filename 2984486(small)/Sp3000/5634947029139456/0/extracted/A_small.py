infile = open("A-small-attempt0.in", "rU")
outfile = open("A.out", "w")

ncases = int(infile.readline())

def dist(string1, string2):
    total = 0

    for i in xrange(len(string1)):
        if string1[i] != string2[i]:
            total += 1

    return total

def xor(string1, string2):
    output = ""

    for i in xrange(len(string1)):
        if string1[i] != string2[i]:
            output += "1"
        else:
            output += "0"

    return output

for case in xrange(1, ncases + 1):
    n, l = [int(x) for x in infile.readline().strip().split(" ")]

    flows = infile.readline().strip().split(" ")
    devices = infile.readline().strip().split(" ")

    devices.sort()

    minimum = -1
    
    for device_from in devices:        
        for flow_to in flows:
            switching = xor(device_from, flow_to)
            switches_required = dist(device_from, flow_to)

            if minimum != -1 and switches_required > minimum:
                continue

            new_flows = []

            for f in flows:
                new_flows.append(xor(switching, f))

            new_flows.sort()

            for i in xrange(len(devices)):
                if devices[i] != new_flows[i]:
                    break

            else:
                if minimum == -1 or switches_required < minimum:
                    minimum = switches_required

    if minimum == -1:
        outfile.write("Case #%d: NOT POSSIBLE\n" % case)

    else:
        outfile.write("Case #%d: %d\n" % (case, minimum))
        
infile.close()
outfile.close()
