def main():
    T = int(raw_input())
    for t in xrange(T):
        (N, L) = (int(x) for x in raw_input().split())
        outlets = [int(x,2) for x in raw_input().split()]
        flows = [int(x,2) for x in raw_input().split()]
        matrix = make_matrix(outlets, flows)
        possibilities = get_possible(matrix)
        answer = "Case #" + str(t+1) + ": "
        if len(possibilities) > 0:
            answer = answer + str(get_smallest(possibilities))
        else:
            answer = answer + "NOT POSSIBLE"
        print answer

def make_matrix(outlets, flows):
    ret = []
    for flow in flows:
        row = {}
        for i in xrange(len(outlets)):
            row[outlets[i] ^ flow] = i
        ret.append(row)
    return ret

def get_possible(matrix):
    ret = []
    indices_used = set()
    for answer in (matrix[0]):
        possible = True
        indices_used.clear()
        indices_used.add(matrix[0][answer])
        for i in xrange(1, len(matrix)):
            #check other indices
            if answer in matrix[i] and matrix[i][answer] not in indices_used:
                indices_used.add(matrix[i][answer])
            else:
                possible = False
                break
        if possible:
            ret.append(answer)
    return ret

def get_smallest(possibilities):
    #finds number with smallest number of bits
    smallest = count_bits(possibilities[0])
    for possibility in possibilities[1:]:
        bits = count_bits(possibility)
        if bits < smallest:
            smallest = bits
    return smallest

def count_bits(n):
    ret = 0
    while n > 0:
        ret += n & 1
        n = n >> 1
    return ret


if __name__ == "__main__":
    main()
