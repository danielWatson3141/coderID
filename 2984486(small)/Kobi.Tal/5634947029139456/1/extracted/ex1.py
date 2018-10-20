def get_content(path):
    return [line.strip() for line in open(path, 'rb')]
            
            
def calc(content):
    cases = content.pop(0)
    ret = []
    for case in xrange(int(cases)):
        items, switches = content.pop(0).split()
        outlets = [int(i, 2) for i in content.pop(0).split()]
        switches = [int(i, 2) for i in content.pop(0).split()]

        matrix = []
        for i, outlet in enumerate(outlets):
            matrix.append('')
            matrix[i] = []
            for switch in switches:
                matrix[i].append(outlet ^ switch)

        curr_min = min(matrix[0])
        reset = True
        exit = False
        while reset:
            reset = False
            for row in matrix:
                if curr_min not in row:
                    bigger = [a for a in row if a > curr_min]
                    if len(bigger) == 0:
                        exit = True
                        curr_min = None
                        break
                    curr_min = min(bigger)
                    reset = True
                    break
            if exit or not reset:
                break

        for row in matrix:
            if curr_min not in row:
                curr_min = None
                break

        if curr_min is not None:
            ret.append('Case #{}: {}'.format(case + 1, "{0:b}".format(curr_min).count('1')))
        else:
            ret.append('Case #{}: {}'.format(case + 1, 'NOT POSSIBLE'))
    return ret

    
if __name__ == '__main__':
    content = get_content(r'C:\gjam\1A\1\A-large.in')
    ret = calc(content)
    with open(r'C:\gjam\1A\1\out.txt', 'wb') as fwriter:
        for line in ret:
            fwriter.write(line)
            fwriter.write('\r\n')
