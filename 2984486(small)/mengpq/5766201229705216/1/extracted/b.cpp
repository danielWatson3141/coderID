#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <assert.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define foreach(it, s) for (__typeof(s.begin()) it = s.begin(); it != s.end(); ++it)
#define X first
#define Y second

const int MAX_N = 100001;
const int MAX_M = 100001;
const int MOD = 1e9 + 7.5;
const double EPS = 1e-8;

int n;
vector<int> g[MAX_N];
int f[MAX_N], son[MAX_N];

void init(){
    int x, y;
    cin >> n;
    for (int i = 0; i < n; i++) g[i].clear();
    for (int i = 1; i < n; i++){
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

int calc(int idx){
    return son[idx] + 1 - f[idx];
}

int dfs(int node, int fa){
    son[node] = 0;
    f[node] = 0;
    int t = 0;
    foreach(it, g[node]) if (*it != fa){
        ++t;
        dfs(*it, node);
        son[node] += son[*it] + 1;
    }

    if (t == 0){
    } else if (t == 1){
        foreach(it, g[node]) if (*it != fa) f[node] = son[*it] + 1;
    } else{
        int idx1 = -1, idx2 = -1;
        foreach(it, g[node]) if (*it != fa){
            if (idx1 == -1 || calc(*it) > calc(idx1)){
                idx1 = *it;
            }
        }
        foreach(it, g[node]) if (*it != fa && *it != idx1){
            if (idx2 == -1 || calc(*it) > calc(idx2)){
                idx2 = *it;
            }
        }
        f[node] = son[node] - (son[idx1] + 1 - f[idx1] + son[idx2] + 1 - f[idx2]);
    }
    return f[node];
}

void solve(int ca){
    int ret = n - 1;
    for (int i = 0; i < n; i++){
        ret = min(ret, dfs(i, -1));
    }
    printf("Case #%d: %d\n", ca, ret);
}

int main(){
    int ca;
    cin >> ca;
    for (int i = 0; i < ca; i++){
        init();
        solve(i + 1);
    }
    return 0;
}
