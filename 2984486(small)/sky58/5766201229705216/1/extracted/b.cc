#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
int num[1010],dp[1010];
vector<int> gr[1010],ch[1010];
int dfs(int v,int u){
	int ret=1;
	rep(i,gr[v].size()){
		int w=gr[v][i];if(w==u) continue;ret+=dfs(w,v);ch[v].pb(w);
	}
	return num[v]=ret;
}
int dfs2(int v){
	int n=ch[v].size();//cerr<<v<<' '<<n<<endl;
	if(n==1) return dp[v]=num[ch[v][0]];
	if(n==0) return dp[v]=0;
	vector<int> t;int ret=0;
	rep(i,n){
		int w=ch[v][i];ret+=num[w];t.pb(dfs2(w)-num[w]);
	}
	sort(All(t));return dp[v]=ret+t[0]+t[1];
}
int main()
{
	int t,a,b,n;
	cin>>t;
	rep(i,t){
		rep(j,1010) gr[j].clear();
		cin>>n;
		rep(j,n-1){
			cin>>a>>b;a--;b--;gr[a].pb(b);gr[b].pb(a);
		}
		int ret=114514;
		rep(j,n){
			rep(k,n+5) ch[k].clear();dfs(j,-1);//cerr<<'a'<<endl;
			dfs2(j);ret=min(ret,dp[j]);
			//rep(k,n) cerr<<k<<' '<<num[k]<<endl;
			//cerr<<j<<' '<<dp[j]<<endl;
		}
		printf("Case #%d: %d\n",i+1,ret);
	}
}
