/*
 * totoroXD
 *
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
const int INF = 1011110000, MOD=1000000000;
const int dx[]={1,0,-1,0}, dy[]={0,1,0,-1};
const double EPS = 1e-6;

int n, kase=1, dp[1111], nanc[1111];
vector<int> G[1111];

int dpr(int v, int par){
	int &res=dp[v];
	if(res!=-1)return res;
	int deg=0;
	nanc[v]=0;
	vector<int> chdp;
	for(int i=0; i<G[v].size(); i++){
		int u=G[v][i];
		if(u!=par){
			deg++;
			chdp.push_back(dpr(u, v)-nanc[u]-1);
			nanc[v]+= nanc[u]+1;
		}
	}
	if(deg==0)res=0;
	else if(deg==1){
		res = nanc[v];
	}else{
		sort(chdp.begin(), chdp.end());
		res = nanc[v]+chdp[0]+chdp[1];
	}
	//printf("dp(%d) = %d\n",v,res);
	return res;
}
bool input(){
	scanf("%d",&n);
	for(int i=0; i<n; i++)G[i].clear();
	for(int i=0,a,b; i<n-1; i++){
		scanf("%d%d",&a,&b);
		G[a-1].push_back(b-1);
		G[b-1].push_back(a-1);
	}
	return 1;
}
void solve(){
	int res=n-1;
	for(int rt=0; rt<n; rt++){
		memset(dp, -1, sizeof(dp));
		//printf("rt = %d\n",rt);

		res=min(res, dpr(rt,rt));
	}
	printf("Case #%d: %d\n",kase++, res);
}
void pre(){
}
int main(){
	pre();
    int zz=1;
    cin>>zz;
    while(zz--){
    	input();
    	solve();
    }
    return 0;
}

/*

3
3
2 1
1 3
7
4 5
4 2
1 2
3 1
6 4
3 7
4
1 2
2 3
3 4

*/

