#pylint: disable=missing-docstring,invalid-name
import sys
import os

def decide(N, nums):
    '''
    Based on Wiki page http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle we can assume
    that BAD algorithm should have higher probability for number ending shifted to the right,
    while GOOD algorithmm has same probabilities for a number shifted right or left.

    Also 1000 is quite large, so "big numbers" rule should work, thus let's just try to assume
    that for GOOD algo numbers to the left and to the right should be roughly equal
    '''
    rightMoved = sum(1 if num > pos else 0 for (pos, num) in enumerate(nums))
    print '=> %s (%.3f%%)' % (rightMoved, 100.0 * rightMoved / N)
    if rightMoved >= N * 0.5:
        return 'BAD'
    return 'GOOD'

def main():
    with open(sys.argv[1], 'r') as inp, open('%s.out' % (os.path.splitext(sys.argv[1])[0]), 'w') as out: #pylint: disable=line-too-long
        T = int(inp.readline())
        for t in xrange(T):
            N = int(inp.readline())
            nums = [int(x) for x in inp.readline().split()]
            out.write('Case #%s: %s\n' % (t + 1, decide(N, nums)))

if __name__ == '__main__':
    main()
