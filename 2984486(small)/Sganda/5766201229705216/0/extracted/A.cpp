#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iomanip>
#include<cmath>

#define LL long long
#define PB push_back
#define MP make_pair
#define INF 1000000007
#define MOD 1000000007
#define sd(x) scanf("%d", &x)

using namespace std;

int n, coun[1001], parent[1001];
vector<int> adj[1001];
int find(int x){
    int i;
    for(i = 0; i < adj[x].size(); i++){
        if(parent[x] == adj[x][i]){
            continue;
        }
        parent[adj[x][i] ] = x;
        find(adj[x][i]);
    }
    int l1 = 0, l2 = 0;
    for(i = 0; i < adj[x].size(); i++){
        if(l2 <= coun[adj[x][i] ]){
            l1 = l2;
            l2 = coun[adj[x][i] ];
        }
        else{
            l1 = max(l1, coun[adj[x][i]]);
        }
    }
    if(l1 == 0 && l2 == 0){
        coun[x] = 1;
        return 0;
    }
    if(l2 > 0 && l1 == 0){
        coun[x] = 1;
        return 0;
    }
    coun[x] = l1 + l2 + 1;
    return 0;
}

int dod(int root){
    int i;
    for(i = 0; i <= n; i++){
        coun[i] = 0;
        parent[i] = 0;
    }
    find(root);
    return n - coun[root];
}

int solve(){
    int i, x, y, ans2, ans;
    cin>>n;
    for(i = 0; i <= n; i++){
        adj[i].clear();
    }
    for(i = 0; i < n-1; i++){
        sd(x);
        sd(y);
        adj[x].PB(y);
        adj[y].PB(x);
    }
    ans = n;
    for(i = 1; i <= n; i++){
        ans2 = dod(i);
        ans = min(ans2, ans);
    }
    cout<<ans<<endl;
    return 0;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, op = 1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<op<<": ";
        solve();
        op++;
    }
    return 0;
}
