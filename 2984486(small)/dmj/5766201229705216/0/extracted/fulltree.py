#!/usr/bin/env python

import sys
import logging
import argparse


def check(adj, start):
    def remove_all(u, parent):
        r = 0
        for v in adj[u]:
            if v != parent:
                r += remove_all(v, u) + 1
        return r

    def check_node(u, parent):
        # return number needed to remove
        children = [x for x in adj[u] if x != parent]
        if len(children) == 0:
            return 0
        elif len(children) == 1:
            return 1 + remove_all(children[0], u)
        elif len(children) == 2:
            r = 0
            for v in children:
                r += check_node(v, u)
            return r
        else:
            xs = []
            for v in children:
                xs.append((check_node(v, u), 1 + remove_all(v, u), v))
            xs = [(x[0] - x[1], x) for x in xs]
            xs.sort()
            r = xs[0][1][0] + xs[1][1][0]
            for x in xs[2:]:
                r += x[1][1]
            return r
            # TODO

    return check_node(start, -1)



def solve(adj):
    best = len(adj) + 100

    for k in adj.keys():
        b = check(adj, k)
        if b < best:
            best = b
    return best

def main(inp, output):
    T = int(next(inp))

    for case in range(1,T+1):
        N = int(next(inp))
        adj = {}
        for i in xrange(1, N+1):
            adj[i] = []

        for i in xrange(N-1):
            X, Y = [int(x) for x in next(inp).split()]
            adj[X].append(Y)
            adj[Y].append(X)
        r = solve(adj)
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
