#include <iostream>
#include <cstring>
#include <stdio.h>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair

#define ll long long
const int maxn = 16;
int out[maxn];
bool vis[maxn];
int edge[maxn][maxn];
int origin[maxn][maxn];
int n;

const int inf = 1e8;

void init(){
    memset(origin, 0, sizeof(origin));
}

void dfs(int s){
    vis[s] = true;
    for(int i = 0; i < n; ++i)
        if( edge[s][i] && !vis[i] ){
            out[s]++;
            dfs(i);
        }
}

bool legal(int s ){
    bitset<maxn> b = s;
    memset(edge, 0, sizeof(edge)  );
    for(int i = 0; i < n; ++i)
    if( b[i] == 0 ){
        for(int j = 0; j < n; ++j)
            if( b[j] == 0 )
                edge[i][j] = origin[i][j];
    }

    for(int i = 0; i < n; ++i){
        memset(vis, 0, sizeof(vis) );
        memset(out, 0, sizeof(out) );
        if( b[i] ) continue;
        dfs( i );
        bool flag = true;
        for(int j = 0; j < n; ++j)
            if( b[j] == 0 && (!vis[j] || !( out[j] == 0 || out[j] == 2) ) )
                flag = false;
        if( flag ) return true;
    }
    return false;
}
int main(){
    freopen("Bin.txt", "r", stdin );
    freopen("Bout.txt", "w", stdout );
    int tcase;
    int tno= 0;
    cin>>tcase;
    while(tcase--){
        init();
        cin>>n;
        for(int i =  1; i < n; ++i){
            int a, b;
            cin>>a>>b;
            a--;    b--;
            origin[a][b] = origin[b][a] = 1;
        }
        int res = inf;
        for(int s = 0; s < (1<<n); ++s){
            bitset<maxn> b = s;
            if( legal(s) ){
                res = min(res, (int) b.count() );
            }
        }
        printf("Case #%d: %d\n", ++tno, res);
    }
    return 0;
}
