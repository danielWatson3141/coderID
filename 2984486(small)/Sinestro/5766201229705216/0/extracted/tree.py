import networkx as nx
import matplotlib.pyplot as plt

num_cases = int(raw_input())

for case in range(1, num_cases + 1):
    num_nodes = int(raw_input())
    graph = nx.Graph()

    for _ in range(num_nodes - 1):
        x, y = raw_input().split(' ')
        graph.add_edge(x, y)

    if num_nodes == 3:
        print "Case #%i: 0" % case
        continue

    strike = []
    suspects = [x for x in graph.nodes() if graph.degree(x) == 1]

    for suspect in suspects:
        only_neighbor = graph.neighbors(suspect)[0]
        if graph.degree(only_neighbor) == 2:
            strike.append(suspect)

    graph.remove_nodes_from(strike)

    print "Case #%i: %i" % (case, num_nodes - len(graph.nodes()))
