#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

using namespace std;

int nodes;

vector<int> edges[15];
bool deleted[15];
bool visited[15];
int nDel;

int best;

bool checkValid(int root, int from) {
    visited[root] = true;
    int nChildren = 0;
    for (int other : edges[root]) {
        if (other == from) continue;
        if (deleted[other]) continue;

        ++nChildren;
        if (!checkValid(other, root)) return false;
    }
    return nChildren == 2 || nChildren == 0;
}

void check() {
    int childrenCount[15];
    memset(childrenCount, 0, sizeof(childrenCount));

    for (int i = 0; i < nodes; ++i) {
        if (deleted[i]) continue;
        for (int other : edges[i]) {
            if (deleted[other]) continue;
            childrenCount[i]++;
        }
    }

    // First, find the root - it's the only one with 2 children or 1 node with 0
    // children
    int root = -1;
    for (int i = 0; i < nodes; ++i) {
        if (deleted[i]) continue;
        if (childrenCount[i] == 2 || childrenCount[i] == 0) {
            if (root == -1)
                root = i;
            else
                // Invalid!
                return;
        }
    }
    if (root == -1) return;

    // Now, just walk the tree
    memset(visited, 0, sizeof(visited));
    if (checkValid(root, -1)) {

        for (int i = 0; i < nodes; ++i) {
            if (!visited[i] && !deleted[i]) return;
        }

        best = nDel;
    }
}

void solver(int node) {
    if (nDel >= best)
        return;

    if (node == nodes) {
        check();
        return;
    }

    // try not deleting first
    solver(node + 1);

    ++nDel;
    deleted[node] = true;
    solver(node + 1);
    deleted[node] = false;
    --nDel;
}

void solve(int caseN)
{
    for (int i = 0; i < 15; ++i) edges[i].clear();
    memset(deleted, 0, sizeof(deleted));

    scanf("%d", &nodes);
    for (int i = 0; i < nodes - 1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    best = 100000;
    nDel = 0;
    solver(0);

    printf("Case #%d: %d\n", caseN, best);
}

int main(void)
{
    int nC;
    scanf("%d", &nC);
    for (int cC = 0; cC < nC; ++cC) {
        solve(cC + 1);
    }

    return 0;
}
