#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 2000;

vector <int> G[maxn];

int ga = 0, root;
int dfs2(int u, int p) {
    vector <int> D;
    for (int i = 0; i < (int)G[u].size(); ++i) {
        int v = G[u][i];
        if (v != p) {
            D.push_back(dfs2(v, u));
        }
        sort(D.rbegin(), D.rend());
        D.resize(min((int)D.size(), 2));
    }
    if (D.size() <= 1) {
        return 1;
    } else {
        return D[0] + D[1] + 1;
    } 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        int N;
        for (int i = 0; i < maxn; ++i){
            G[i].resize(0);
        }
        cin >> N;
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ga = N;
        for (int i = 0; i < N; ++i) {
            root = i;
            ga = min(ga, N - dfs2(root, root));    
        }
        printf("Case #%d: %d\n", test, ga);
    } 

}