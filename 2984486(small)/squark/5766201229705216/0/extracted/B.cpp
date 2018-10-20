#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 1004;

vector<int> e[MAXN];

int f[MAXN];
bool vis[MAXN];
int ans;
int n;

void dfs(int i){
    int  j;
    vis[i] = true;
    vector<int> t;
    for(j = 0; j < e[i].size(); j++){
        if(!vis[e[i][j]]){
            dfs(e[i][j]);
            t.pb(f[e[i][j]]);
        }
    }
    if(t.size() >= 2){
        sort(t.begin(), t.end(), greater<int>());
        f[i] = t[0] + t[1] + 1;
    }
    else
        f[i] = 1; 
}

void dfs0(int i){
    memset(vis, 0, sizeof vis);
    dfs(i);
    ans = min(ans, n-f[i]);
}

int main() {
#ifdef __FIO
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int i0 = 1;
	int T;
	scanf("%d", &T);
	for (i0 = 1; i0 <= T; i0++) {
		int i, j, k;
		scanf("%d", &n);
		for(i = 1; i < n; i++){
		    scanf("%d%d", &j, &k);
		    j--;
		    k--;
		    e[j].pb(k);
		    e[k].pb(j);
		}
		
		ans = n-1;
		
		for(i = 0; i < n; i++)
            dfs0(i);
		
		for(i = 0; i < n; i++)
            e[i].clear();
        
        printf("Case #%d: %d\n", i0, ans);
	}
	return 0;
}
