#pragma comment(linker, "/STACK:16777216")
#include <iostream>
#include <climits>
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <ctime>
#include <functional>
#include <iterator>
#include <complex>
#include <queue>
#include <cassert>
#include <sstream>
#include <cstdlib>

using namespace std;

double pi = acos((double) -1);
int INF = 2147483647;

int dfs(vector<vector<int>>& graph, int s, int n, vector<char>& used, int& nodes_to_remove, bool root = false) {
    used[s] = true;
    int children_count = 0;
    vector<int> diff_vect;
    for (vector<int>::iterator i=graph[s].begin(); i!=graph[s].end(); ++i)
        if (!used[*i]) {
            int child_nodes_to_remove = 0;
            int result = dfs (graph, *i, n, used, child_nodes_to_remove);
            children_count += result;
            nodes_to_remove += child_nodes_to_remove;
            diff_vect.push_back(result - child_nodes_to_remove);
        }
    if (root && graph[s].size() == 1 || !root && graph[s].size() == 1 + 1) {
        nodes_to_remove = children_count;
    }
    else if (root && graph[s].size() > 2 || !root && graph[s].size() > 2 + 1) {
        for (int z = 0; z < 2; z++) {
            int max_index = -1;
            int max_el = -1;
            for (int i = 0; i < diff_vect.size(); i++) {
                if (diff_vect[i] > max_el) {
                    max_el = diff_vect[i];
                    max_index = i;
                }
            }
            diff_vect.erase(diff_vect.begin() + max_index);
        }

        for (int i = 0; i < diff_vect.size(); i++) {
            nodes_to_remove += diff_vect[i];
        }
    }
    return children_count + 1;
}

int main() {
    clock_t tStart = clock();
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        int n;
        scanf("%d", &n);
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<char> used(n);

        int nodes_to_remove_min = INF;
        int min_index;
        for (int i = 0; i < n; i++) {
            if (i == 13) {
                int gg = 1;
            }

            used.assign(n, false);
            int nodes_to_remove = 0;
            dfs(graph, i, n, used, nodes_to_remove, true);
            if (nodes_to_remove < nodes_to_remove_min) {
                nodes_to_remove_min = nodes_to_remove;
                min_index = i;
            }
        }

        printf("Case #%d: %d\n", test, nodes_to_remove_min);
    }
    //printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}
