#!/usr/bin/python

import sys
from itertools import combinations


def main():
    data = sys.stdin
    nb = int(data.readline())
    for icase in xrange(nb):
        nb_nodes = int(data.readline().strip())
        nodes = {}
        for inode in xrange(nb_nodes - 1):
            x1, y1 = map(int, data.readline().split())
            if y1 not in nodes:
                nodes[y1] = [x1]
            else:
                nodes[y1].append(x1)
            if x1 not in nodes:
                nodes[x1] = [y1]
            else:
                nodes[x1].append(y1)

        # return node connected
        def destroy_childs(root, father):
            sum_destroyed = 1
            for c in nodes[root]:
                if c != father:
                    sum_destroyed += destroy_childs(c, root)
            return sum_destroyed

        # return node destroyed
        def build_tree(start_of_subtree, father, fake_list=None):
            connections = list(nodes[start_of_subtree])
            if fake_list is not None:
                connections = fake_list
            if father is not None:
                connections.remove(father)
            if len(connections) == 0:
                # proper tree
                return 0
            elif len(connections) == 2:
                return build_tree(connections[0], start_of_subtree) + build_tree(connections[1], start_of_subtree)
            else:
                # case were we need to destroy
                for c in connections:
                    return destroy_childs(c, start_of_subtree)


        # algo: partir des nodes avec 2 enfants, et recuperer parties gauches
        # et droites et continuer
        # si on est sur une node qui n'a pas 0 ou 2 enfants, on coupe la node
        # fille et ses sous nodes et on compte combien de nodes on a vire
        M = False
        possible_start_nodes = [s for s, v in nodes.items() if len(v) >= 2]
        if len(possible_start_nodes) == 0:
            if nb_nodes == 1:
                minimum_removal = 0
            elif nb_nodes == 2:
                minimum_removal = 1
        else:
            minimum_removal = None
            for start in possible_start_nodes:
                if len(nodes[start]) == 2:
                    to_remove_to_get_tree = build_tree(start, None)
                    if to_remove_to_get_tree != None:
                        if minimum_removal is None or to_remove_to_get_tree < minimum_removal:
                            minimum_removal = to_remove_to_get_tree
                else:
                    for c in combinations(nodes[start], 2):
                        # first, count nodes to remove
                        to_remove_to_get_tree = build_tree(start, None, c)
                        for n in nodes[start]:
                            if n not in c:
                                to_remove_to_get_tree += destroy_childs(n, start)
                        if to_remove_to_get_tree != None:
                            if minimum_removal is None or to_remove_to_get_tree < minimum_removal:
                                minimum_removal = to_remove_to_get_tree

        assert(minimum_removal != None)

#        # idee de l'algo : partir des enfants et remonter jusq'au premier
#        # parent
#        res = {} # contient les parents seulement
#        for n, v in nodes.items():
#            if len(v) == 1:
#                # this is a child, get parent
#                if v[0] not in res:
#                    res[v[0]] =
        # autre algo : dans le cas d'une node a deux, compter le nombre de
        # nodes de chaque cote  et virer la node qui a le cote ou y'en a moins

        res = icase
        print "Case #%d: %d" % (icase + 1, minimum_removal)


if __name__ == "__main__":
    main()
