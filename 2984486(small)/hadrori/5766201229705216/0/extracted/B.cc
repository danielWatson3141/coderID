#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <complex>

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);

vector<int> edge[1024];
int memo[1024][1024];
int N;

void init(){
    for(int i = 0; i < 1024; i++)
        edge[i].clear();
    memset(memo, -1, sizeof(memo));
}

void input(){
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}

int counter(int node, int par){
    int ret = 1;
    for(int i = 0; i < edge[node].size(); i++)
        if(edge[node][i] != par) ret += counter(edge[node][i], node);
    return ret;
}

int rec(int node, int par){
    if(par != -1 and memo[node][par] >= 0) return memo[node][par];
    int ret = 0;
    int n = edge[node].size();
    int a = 1, b = 3;
    if(par == -1){ a--; b--;}
    if(n == a or n == b){
        for(int i = 0; i < n; i++)
            if(edge[node][i] != par)
                ret += rec(edge[node][i], node);
    }
    else if(n == a+1){
        for(int i = 0; i < n; i++)
            if(edge[node][i] != par) ret += counter(edge[node][i], node);
    }
    else{
        vector<pii> res;
        int cnt1[1024], cnt2[1024];
        for(int i = 0; i < n; i++)
            if(edge[node][i] != par){
                cnt1[i] = rec(edge[node][i], node);
                cnt2[i] = counter(edge[node][i], node);
                res.push_back(pii(cnt2[i]-cnt1[i], i));
            }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        int c = res[0].second, d = res[1].second;
        ret += cnt1[c] + cnt1[d];
        for(int i = 0; i < n; i++)
            if(i != c and i != d)
                ret += cnt2[i];
    }
    if(par != -1) return memo[node][par] = ret;
    else return ret;
}
void solve(){
    int ans = N;
    for(int i = 0; i < N; i++)
        ans = min(ans, rec(i, -1));
    cout << ans << endl;
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        init(); input();
        solve();
    }
    return 0;
}
