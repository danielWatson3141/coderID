#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool vis[1004];
vector<int> son[1004];
int N;

int solve(int u){
    vis[u] = true;
    vector<int> A;
    for (int i = 0; i < son[u].size(); i++){
        int v = son[u][i];
        if (!vis[v]){
            A.push_back(solve(v));
        }
    }
    if (A.size() <= 1) return 1;
    sort(A.begin(), A.end(), greater<int>());
    return A[0] + A[1] + 1;
}

int main(){
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++){
        cin >> N;
        for (int i = 1; i <= N; i++)
            son[i].clear();
        for (int i = 1; i < N; i++){
            int x, y;
            scanf("%d %d", &x, &y);
            son[x].push_back(y);
            son[y].push_back(x);
        }
        int ans = 0;
        for (int i = 1; i <= N; i++){
            memset(vis, 0, sizeof(vis));
            int k = solve(i);
            if (k > ans)
                ans = k;
        }
        printf("Case #%d: %d\n", o, N - ans);
    }
}
