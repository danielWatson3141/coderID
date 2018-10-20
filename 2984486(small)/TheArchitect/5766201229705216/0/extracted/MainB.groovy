package A1
/**
 * Created by Robert on 12.04.2014.
 */
public class MainB {

    static BufferedWriter out = new File("output.txt").newWriter()

    public static void main(String[] args) {
        List.metaClass.nest { depth ->
            nestList([delegate], depth, 0)
        }

        List<String> lines = new File("B-small-attempt0.in").text.split("\n").toList().collect { it.trim() }
        List cases = lines.drop(1).nest(1)
        int x = 1
        for (List<String> _case : cases) {
            solveCase(_case, x)
            x++
        }
        out.close()
    }

    static void solveCase(List<String> c, int i) {
        List<Integer[]> edges = c[1].collect { String it ->
            String[] split = it.split(" ")
            return [split[0].asType(Integer.class), split[1].asType(Integer.class)]
        }
        int nrNodes = edges.size() + 1

        if (nrNodes == 1 || nrNodes == 3)
            out.writeLine("Case #${i}: 0")
        else if (nrNodes == 2)
            out.writeLine("Case #${i}: 1")
        else {
            List<Integer> deleteNodes = []
            List<Integer> twoEdgeNodes = []
            for (int n = 1; n <= nrNodes; n++) {
                if (deleteNodes.contains(n))
                    continue
                List<Integer> connectedNodes = getConnectedNodes(n, edges)
                if (connectedNodes.size() > 3) {
                    List<List<Integer>> deletePossibilities = []
                    for (int conNode : connectedNodes) {
                        def copy = edges.collect()
                        copy.removeAll { it[1] == n && it[0] == conNode || it[0] == n && it[1] == conNode }
                        deletePossibilities.add(getReachableNodes(conNode, copy))
                    }
                    for (int x = connectedNodes.size() - 3; x > 0; x--) {
                        def min = deletePossibilities.min { List<Integer> it -> it.size() }
                        deletePossibilities.remove(min)
                        deleteNodes.addAll(min)
                    }
                }
                if (connectedNodes.size() == 2) {
                    twoEdgeNodes.add(n)
                }
            }
            if (twoEdgeNodes.empty) {
                out.writeLine("Case #${i}: ${deleteNodes.unique().size() + 1}")
            } else if (twoEdgeNodes.size() == 1) {
                out.writeLine("Case #${i}: ${deleteNodes.unique().size()}")
            } else {
                List<List<Integer>> deletePossibilities = []
                for (int n : twoEdgeNodes) {
                    List<Integer> connectedNodes = getConnectedNodes(n, edges)
                    def copy = edges.collect()
                    copy.removeAll { it[1] == n && it[0] == connectedNodes[0] || it[0] == n && it[1] == connectedNodes[0] }
                    List<Integer> side1 = getReachableNodes(connectedNodes[0], copy)
                    copy = edges.collect()
                    copy.removeAll { it[1] == n && it[0] == connectedNodes[1] || it[0] == n && it[1] == connectedNodes[1] }
                    List<Integer> side2 = getReachableNodes(connectedNodes[1], copy)
                    if(side1.size() < side2.size())
                        deletePossibilities.add(side1)
                    else
                        deletePossibilities.add(side2)
                }
                deletePossibilities=deletePossibilities.sort {it.size()}
                (twoEdgeNodes.size()-1).times {
                    deleteNodes.addAll(deletePossibilities.first())
                    deletePossibilities.remove(0)
                }

                out.writeLine("Case #${i}: ${deleteNodes.unique().size()}")
            }
        }
    }

    private static int getConnectedNodesCount(int node, List<Integer[]> edges) {
        return edges.sum { it[0] == node || it[1] == node ? 1 : 0 }
    }

    private static List<Integer> getReachableNodes(int node, List<Integer[]> edges) {
        List<Integer> reached = []
        List<Integer> nextDepth = [node]
        while (nextDepth) {
            int n = nextDepth.remove(0)
            if (reached.contains(n))
                continue
            reached.add(n)
            nextDepth.addAll(getConnectedNodes(n, edges))
        }
        return reached
    }

    private static List<Integer> getConnectedNodes(int node, List<Integer[]> edges) {
        return edges.collectMany {
            if (it[0] == node)
                return [it[1]]
            if (it[1] == node)
                return [it[0]]
            return []
        }
    }

    private static List nestList(List<List> list, int depth, int nrSubGroups) {
        def ret = []
        int groupCount = 0
        while (nrSubGroups == 0 && list[0] || groupCount < nrSubGroups) {
            def group = []
            groupCount++
            if (depth <= 1) {
                int n = list[0].first().toString().asType(Integer.class) - 1
                group.add(list[0].first())
                list[0] = list[0].drop(1)
                group.add(list[0].take(n))
                list[0] = list[0].drop(n)
            } else {
                int n = list[0].first().toString().asType(Integer.class) - 1
                group.add(list[0].first())
                list[0] = list[0].drop(1)
                group.add(nestList(list, depth - 1, n))
            }
            ret.add(group)
        }
        return ret
    }
}
