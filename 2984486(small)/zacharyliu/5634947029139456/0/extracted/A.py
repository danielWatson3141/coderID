with open('A.in') as f:
    with open('A.out', 'w') as f2:
        lines = f.readlines()
        output = ""
        for i in range(int(lines[0])):
            L = int(lines[1 + i*3].split(" ")[1])
            outlets = [int(n, 2) for n in lines[2 + i*3].split(" ")]
            devices = sorted([int(n, 2) for n in lines[3 + i*3].split(" ")])
            print(outlets, devices)

            mincount = L + 1
            for x in range(2**L):
                new_outlets = sorted([n ^ x for n in outlets])
                if new_outlets == devices:
                    thiscount = bin(x).count("1")
                    if thiscount < mincount:
                        mincount = thiscount

            output += "Case #" + str(i+1) + ": "
            if mincount != L + 1:
                output += str(mincount)
            else:
                output += "NOT POSSIBLE"

            output += "\n"

        print(output)
        f2.write(output)