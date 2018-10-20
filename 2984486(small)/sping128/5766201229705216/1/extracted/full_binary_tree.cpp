//
// full_binary_tree.cpp
//
// Siwakorn Srisakaokul - ping128
// Written on Friday, 25 April 2014.
//

#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <map>
#include <ctype.h>
#include <string.h>

#include <assert.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PII2;

#define MAXN 1005

int N;
vector<int> adj[MAXN];
vector<int> children[MAXN];
int num_node[MAXN];

void dfs(int at, int parent) {
    num_node[at] = 1;
    children[at].clear();
    int sz = adj[at].size();
    for (int i = 0; i < sz; i++) {
        int v = adj[at][i];
        if (v != parent) {
            dfs(v, at);
            children[at].push_back(v);
            num_node[at] += num_node[v];
        }
    }
}

int temp[MAXN];
int mem[MAXN];

int dfs2(int at, int parent) {
    int sz = children[at].size();
    if (sz == 0) {
        return mem[at] = 0;
    }
    if (sz == 1) {
        return mem[at] = num_node[children[at][0]];
    }
    if (sz == 2) {
        return mem[at] = dfs2(children[at][0], at) + dfs2(children[at][1], at);
    }

    int sum = 0;
    for (int i = 0; i < sz; i++) {
        int v = children[at][i];
        dfs2(v, at);
    }

    for (int i = 0; i < sz; i++) {
        int v = children[at][i];
        temp[i] = mem[v] - num_node[v];
        sum += num_node[v];
    }

    int minn1 = 0;
    int minn2 = 1;
    if (temp[minn1] > temp[minn2]) swap(minn1, minn2);
    for (int i = 2; i < sz; i++) {
        if (temp[i] <= temp[minn1]) {
            minn2 = minn1;
            minn1 = i;
        } else if (temp[i] <= temp[minn2]) {
            minn2 = i;
        }
    }
    return mem[at] = sum + temp[minn1] + temp[minn2];
}

int compute(int root) {
    int ans;
    dfs(root, -1);
    ans = dfs2(root, -1);
    return ans;
}

int temp2[MAXN][2];

void solve() {
    scanf("%d", &N);
    for (int i = 0; i < MAXN; i++) {
        num_node[i] = 0;
        children[i].clear();
        adj[i].clear();
        temp[i] = 0;
    }
    int u, v;
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &u, &v);
        temp2[i][0] = u;
        temp2[i][1] = v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int minn = 1000000;
    for (int i = 1; i <= N; i++) {
        minn = min(minn, compute(i));
    }

    printf("%d\n", minn);
}

int main() {
    int test;
    scanf("%d", &test);
    for (int i = 0; i < test; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
