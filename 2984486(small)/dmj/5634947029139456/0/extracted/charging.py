#!/usr/bin/env python

import sys
import logging
import argparse
import itertools

def solve(outlets, devices):
    devices = set(devices)
    outlets = [list(o) for o in outlets]
    L = len(outlets[0])

    def check(perm):
        for o in outlets:
            tmp = list(o)
            for i in perm:
                if tmp[i] == '1':
                    tmp[i] = '0'
                else:
                    tmp[i] = '1'
            t = ''.join(tmp)
            if t not in devices:
                return False
        return True

    for num in xrange(L+1):
        for perm in itertools.combinations(range(L), num):
            if check(perm):
                return num
    return "NOT POSSIBLE"


def main(inp, output):
    T = int(next(inp))
    for case in range(1,T+1):
        N, L = [int(x) for x in next(inp).split()]
        outlets = [x for x in next(inp).split()]
        devices = [x for x in next(inp).split()]
        r = solve(outlets, devices)
        s = "Case #%d: %s" % (case, r)
        print(s)
        output.write(s + "\n")
        logging.info(s)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="run code jam problem")
    parser.add_argument("filename", type=str, help="input filename")
    parser.add_argument("-v", "--verbose", action="store_true",
                        help="enable verbose logging")

    args = parser.parse_args()
    if args.verbose:
        level=logging.DEBUG
    else:
        level=logging.INFO
    logging.basicConfig(level=level,
                        filename="logfile.txt",
                        filemode="w")
    outfile = args.filename + ".out"

    with open(args.filename) as inp:
        with open(outfile, "w") as outp:
            main(inp, outp)
