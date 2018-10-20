def getMask(device, outlet):
    mask = ['0'] * len(device)
    for i in xrange(len(device)):
        if(device[i] != outlet[i]):
            mask[i] = '1'
    return mask

def getMaskLen(mask):
    ans = 0
    for i in xrange(len(mask)):
        if(mask[i] == '1'):
            ans += 1
    return ans

def applyMask(arr, mask):
    for i in xrange(len(arr)):
        new = ['0'] * len(mask)
        for j in xrange(len(mask)):
            if((mask[j] == '1' and arr[i][j] == '0') or (mask[j] == '0' and arr[i][j] == '1')):
                new[j] = '1'
        arr[i] = new
        
    
def isAns(devices, outlets, mask):
    devices = [x[:] for x in devices]
    outlets = [x[:] for x in outlets]
    applyMask(outlets, mask)
    devices.sort()
    outlets.sort()
    if(devices == outlets):
        return True
    return False
    
    
def main():
    input = open('input.txt', 'r')
    output = open('output.txt', 'w')

    T = int(input.readline()) #number of test cases
    
    for casenum in xrange(1, T+1):
        line = input.readline().strip().split(' ')
        div_num = int(line[0])
        mask_len = int(line[1])
        outlets = input.readline().strip().split(' ')
        outlets = [list(x) for x in outlets]
        devices = input.readline().strip().split(' ')
        devices = [list(x) for x in devices]
        
        ans = mask_len + 1
        for i in xrange(div_num):
            mask = getMask(devices[0], outlets[i])
            bits_num = getMaskLen(mask)
            if(isAns(devices, outlets, mask)):
                if(bits_num < ans):
                    ans = bits_num
        
        if(ans == mask_len + 1):
            ans = 'NOT POSSIBLE'
        outstr = 'Case #' + str(casenum) + ': '
        outstr += str(ans)
        outstr += '\n'
        output.write(outstr)

    input.close()
    output.close()
    
main()