#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n;
vector<int> e[N];
int dp[N];

int dfs(int x, int fa){
    vector<int> son;
    for(int i = 0; i < e[x].size(); ++i){
        if(e[x][i] != fa){
            int ret = dfs(e[x][i], x);
            son.push_back(ret);
        }
    }
    if(son.size() <= 1) return 1;
    sort(son.begin(), son.end());
    return son[son.size() - 1] + son[son.size() - 2] + 1;
}
int main(){
    int _, cas = 1;
    for(scanf("%d", &_); _--; ){
        printf("Case #%d: ", cas++);
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) e[i].clear();
        for(int i = 0, x, y; i < n - 1; ++i){
            scanf("%d %d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            ans = max(ans, dfs(i, -1));
        }
        printf("%d\n", n - ans);
    }
    return 0;
}