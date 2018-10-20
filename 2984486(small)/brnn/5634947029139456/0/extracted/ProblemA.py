from decimal import *
getcontext().prec = 100

fin = open('inputA.txt')
fout = open('outputA.txt','w')
num_tests = int(fin.readline())

for test_num in range(1, num_tests + 1):
    line = fin.readline().split(" ")
    N = int(line[0])
    L = int(line[1])

    flows_line = fin.readline().split(" ")
    devices_line = fin.readline().split(" ")

    flows = []
    devices = []
    min_flip = L+1

    for i in range(N):
        flows.append([])
        devices.append([])
        for j in range(L):
            flows[i].append(int(flows_line[i][j]))
            devices[i].append(int(devices_line[i][j]))

    for i in range(N):
        for j in range(N):
            flow_str = flows[i]
            device_str = devices[j]
            flip_pos = []
            for k in range(L):
                if flow_str[k] != device_str[k]:
                    flip_pos.append(k)
            
            possible = True
            new_flows = []
            for k in range(N):
                temp = list(flows[k])
                for m in flip_pos:
                    if temp[m] == 1:
                        temp[m] = 0
                    else:
                        temp[m] = 1
                new_flows.append(temp)

            for k in range(N):
                if devices[k] in new_flows:
                    new_flows.remove(devices[k])
                else:
                    possible = False
                    break

            if possible:
                min_flip = min(min_flip, len(flip_pos))

    if min_flip == L+1:
        fout.write("Case #" + str(test_num) + ": " + "NOT POSSIBLE" + "\n")
    else:
        fout.write("Case #" + str(test_num) + ": " + str(min_flip) + "\n")
    
fin.close()
fout.close()
