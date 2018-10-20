


/*
    Prob:   Google Code Jam Round1A 2014
    Author: peanut
    Time:   26/04/14 10:44
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const int MaxN = 1000 + 50;

int T, n;
vector<int> adj[MaxN];
int size[MaxN], remn[MaxN];

void dfs(int v, int p) {
    size[v] = remn[v] = 1;
    vector<int> child;
    child.clear();
    for (int k = 0; k < adj[v].size(); ++ k) {
        if (adj[v][k] != p) {
            dfs(adj[v][k], v);
            size[v] += size[adj[v][k]];
            child.push_back(remn[adj[v][k]]);
        }
    }
    if (child.size() >= 2) {
        sort(child.begin(), child.end());
        reverse(child.begin(), child.end());
        remn[v] += child[0] + child[1];
    }
}

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        string post = argv[1][0] == 's' ? 
                      "-small-attempt" + string(argv[2]):
                      "-large";  
        string input_file  = string(argv[0]) + post + ".in",
               output_file = string(argv[0]) + post + ".out";
        freopen(input_file.c_str(), "r", stdin);
        freopen(output_file.c_str(), "w", stdout);
    }
    
    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++ testcase) {
        scanf("%d", &n);
        for (int k = 0; k <= n; ++ k)
            adj[k].clear();
        for (int k = 1; k < n; ++ k) {
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int res = n;
        for (int k = 1; k <= n; ++ k) {
            memset(size, 0, sizeof size);
            memset(remn, 0, sizeof remn);
            dfs(k, 0);
            res = min(res, n - remn[k]);
        }
        printf("Case #%d: %d\n", testcase, res);
    }

    return 0;
}
