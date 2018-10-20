#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 1005;
int n , dp[N] , size[N];
vector <int> edge[N];
void dfs (int u , int pre) {
    size[u] = 1;dp[u] = 0;
    vector <int> son;
    for (int i = 0 ; i < edge[u].size() ; i ++) {
        int v = edge[u][i];
        if (v == pre) continue;
        dfs (v , u);
        size[u] += size[v];
        son.push_back (v);
    }
    if (son.size() == 1) {
        dp[u] = size[son[0]];
    }
    else if (son.size()) {
        dp[u] = size[u] - 1;
        for (int i = 0 ; i < son.size() ; i ++) {
            son[i] = -size[son[i]] + dp[son[i]]; 
        }
        sort (son.begin () , son.end ());
        for (int i = 0 ; i < 2 ; i ++)
            dp[u] += son[i];
    }
}
int main () {
#ifndef ONLINE_JUDGE
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int cas = 0;
    int t;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 1 ; i <= n ; i ++)
            edge[i].clear ();
        for (int i = 1 ; i < n ; i ++) {
            int u , v;scanf ("%d %d" , &u , &v);
            edge[u].push_back (v);
            edge[v].push_back (u);
        }
        int ans = n;
        for (int root = 1 ; root <= n ; root ++) {
            dfs (root , -1);
            ans = min (ans , dp[root]);
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}