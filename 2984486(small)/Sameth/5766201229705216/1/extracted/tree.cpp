#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector <vector <int> > edges;
vector <bool> unsearched;
vector <int> subtree;

int search (int node) {
    unsearched [node] = false;
    int firstbest = 0, secondbest = 0;
    int actsol, deleted = 0;
    int numberofchildren = 0;
    int wouldhavetodelete;
    for (int i = 0; i < edges [node].size(); i++) {
        if (unsearched [edges [node] [i]]) {
            numberofchildren ++;
            actsol = search (edges [node] [i]);
            deleted += actsol;
            wouldhavetodelete = subtree [edges [node] [i]] - actsol;
            if (wouldhavetodelete >= firstbest) {
                deleted += secondbest;
                secondbest = firstbest;
                firstbest = wouldhavetodelete;
            }
            else if (wouldhavetodelete > secondbest) {
                deleted += secondbest;
                secondbest = wouldhavetodelete;
            }
            else deleted += wouldhavetodelete;
        }
    }
    if (numberofchildren < 2) return subtree [node] - 1;
    else return deleted;
}

int countnodes(int node) {
    unsearched [node] = false;
    int nodes = 1;
    for (int i = 0; i < edges [node].size(); i++) {
        if (unsearched [edges [node] [i]]) nodes += countnodes (edges [node] [i]);
    }
    subtree [node] = nodes;
    return nodes;
}

int main () {
    int t, n, x, y, bestsol, actsol;
    scanf("%d", &t);
    for (int cases = 1; cases <= t; cases ++) {
        scanf("%d", &n);
        edges.resize(n);
        bestsol = 1047;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &x, &y);
            x --;
            y --;
            edges [y].push_back(x);
            edges [x].push_back(y);
        }
        for (int i = 0; i < n; i++) {
            unsearched.resize(n, true);
            subtree.resize(n, 0);
            countnodes(i);
            unsearched.clear();
            unsearched.resize(n, true);
            actsol = search (i);
            bestsol = min (bestsol, actsol);
            unsearched.clear();
        }
        printf("Case #%d: %d\n", cases, bestsol);

        edges.clear();
        subtree.clear();
    }
}
