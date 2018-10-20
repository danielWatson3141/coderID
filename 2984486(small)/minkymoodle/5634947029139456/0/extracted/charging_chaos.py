

IN = 'A-small-attempt2.in'
OUT = 'out.txt'

def main():
    in_f = open(IN, 'r')
    out_f = open(OUT, 'w')
    T = int(in_f.readline())
    for case in range(1, T+1):
        N, L = map(int, in_f.readline().split())
        initial = in_f.readline().split()
        final = in_f.readline().split()
        out_f.write('case #' + str(case) + ': ')

        s = solve(N, L, initial, final)
        if s < 0:
            out_f.write('NOT POSSIBLE\n')
        else:
            out_f.write(str(s) + '\n')

    in_f.close()
    out_f.close()

def solve(N, L, initial, final):
    f = initial[0]

    i = 0
    tries = []
    for device in final:
        print 'f: ' + f
        print 'device: ' + device
        flips = xor(f, device)
        print 'flips: ' + flips
        other_outlets = initial[1:]
        other_outlets = [xor(flips, outlet) for outlet in other_outlets]
        other_outlets.sort()

        other_devices = final[:i] + final[i+1:]
        other_devices.sort()

        print 'other devices: ' + str(other_devices)
        print 'other outlets: ' + str(other_outlets)

        if equal_strings(other_outlets, other_devices):
            tries.append(num_ones(flips))
        i += 1

    if tries == []:
        return -1
    else:
        return min(tries)

def xor(s1, s2):
    ret = ''
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            ret += '1'
        else:
            ret += '0'
    return ret

def equal_strings(arr1, arr2):
    if len(arr1) != len(arr2):
        return False
    for i in range(len(arr1)):
        if arr1[i] != arr2[i]:
            return False
    return True

def num_ones(flips):
    ones = 0
    for char in flips:
        if char == '1':
            ones += 1
    return ones

main()




