#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>

using namespace std;
FILE *in; FILE *out;

const int MAX = 1024;
const int INF = 1000000001;

int n;
vector <int> v[MAX];

int countNodes(int node, int parent) {
    int ret = 1;
    for (int i = 0; i < (int)v[node].size(); i++)
        if (v[node][i] != parent) ret += countNodes(v[node][i], node);
    return ret;
}

int recurse(int node, int parent) {
    int allNodes = 0;
    vector <int> win;
    for (int i = 0; i < (int)v[node].size(); i++) {
        if (v[node][i] != parent) {
            int nodes = countNodes(v[node][i], node);
            int remove = recurse(v[node][i], node);
            allNodes += nodes;
            win.push_back(nodes - remove);
        }
    }
    if ((int)win.size() == 0)
        return 0;
    else if ((int)win.size() == 1)
        return allNodes;

    sort(win.rbegin(), win.rend());
    return allNodes - win[0] - win[1];
}

int eval(int root) {
    return recurse(root, -1);
}

void solve(int testNum) {
    for (int i = 0; i < MAX; i++)
        v[i].clear();

    fscanf(in, "%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        fscanf(in, "%d %d", &node1, &node2);
        node1--; node2--;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }
    int ans = INF;
    for (int root = 0; root < n; root++)
        ans = min(ans, eval(root));
    fprintf(out, "%d\n", ans);
}

int main(void) {
	unsigned sTime = clock();
	in = fopen("FullBinaryTree.in", "rt");
	out = fopen("FullBinaryTree.out", "wt");
	
	int numTests;
	fscanf(in, "%d", &numTests);
	for (int test = 1; test <= numTests; test++) {
		fprintf(stderr, "Currently executing testcase %d...\n", test);
		fprintf(out, "Case #%d: ", test);
		solve(test);
	}
	fprintf(stderr, "Total execution time %.3lf seconds.\n",
        (double)(clock() - sTime) / (double)CLOCKS_PER_SEC);
	return 0;
}
