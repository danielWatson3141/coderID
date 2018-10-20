#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <vector>
#define LL long long
using namespace std;

vector<int>v[1111];
int sz[1111];
void init(int s, int pre){
    int len = v[s].size();
    sz[s] = 0;
    for(int i = 0; i < len; ++i){
        int ss = v[s][i];
        if(ss == pre) continue;
        init(ss, s);
        sz[s] += sz[ss];
    }
}

int dfs(int s, int pre){
    int len = v[s].size();
    int dw1 = 0, dw2 = 0;
    for(int i = 0; i < len; ++i){
        int ss = v[s][i];
        if(ss == pre) continue;
        int tmp = dfs(ss, s);
        if(tmp > dw1) {
            dw2 = dw1;
            dw1 = tmp;
        } else if(tmp > dw2){
            dw2 = tmp;
        }
    }
    if(pre == 0){
        if(len == 1) return 1;
        return dw1 + dw2 + 1;
    } else {
        if(len <= 2) return 1;
        else return dw1 + dw2 + 1;
    }
}

int main(){
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int t, tt = 0;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int ans = n;
        for(int i = 1; i <= n; ++i){
            int tmp = dfs(i, 0);
            ans = min(ans, n - tmp);
            //cout<<"  ===  "<<i<<"  "<<tmp<<"  "<<ans<<endl;
        }
        printf("Case #%d: %d\n", ++tt, ans);
        for(int i = 1; i <= n; ++i) v[i].clear();
    }
    return 0;
}
