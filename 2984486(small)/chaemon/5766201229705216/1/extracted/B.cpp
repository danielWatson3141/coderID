// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

int N;
vector<vector<int> > adj, child;
vector<int> dp, child_size;

void build(int u, int p=-1){
	int cs=1;
	REP(i,adj[u].size()){
		int v=adj[u][i];
		if(v==p)continue;
		child[u].push_back(v);
		build(v,u);
		cs+=child_size[v];
	}
	child_size[u]=cs;
}

int calc(int u){
	if(dp[u]>=0)return dp[u];
	if(child[u].size()==0)return dp[u]=0;
	if(child[u].size()==1)return dp[u]=child_size[u]-1;
	int diff=0;
	int mini=INF, mini2=INF;
	int mini_id=-1, mini2_id=-1;
	int csum=0;
	REP(i,child[u].size()){
		int v=child[u][i];
		int t=calc(v)-child_size[v];
		csum+=child_size[v];
		if(mini>t){
			mini2=mini;
			mini=t;
			mini2_id=mini_id;
			mini_id=i;
		}else if(mini2>t){
			mini2=t;
			mini2_id=i;
		}
	}
//	return dp[u]=min(child[u].size(),child[u].size()-2+mini+mini2);
	dp[u]=min(csum,csum+mini+mini2);
//	cout<<u<<": "<<mini_id<<" "<<mini2_id<<" "<<dp[u]<<endl;
	return dp[u];
}

void main2(){
	adj.clear();
	cin>>N;
	adj.assign(N,vector<int>());
	REP(i,N-1){
		int X,Y;
		cin>>X>>Y;
		X--;Y--;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	int ans = INF;
	REP(r,N){
//	int r=1;
		child.clear();
		child.assign(N,vector<int>());
		child_size.clear();
		child_size.assign(N,0);
		build(r);
		dp.clear();
		dp.assign(N,-1);
		int c=calc(r);
		ans=min(c,ans);
//		cout<<"result: "<<r<<" "<<c<<endl;
	}
	cout<<ans<<endl;
}

// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<": ";
		main2();
	}
	return 0;
}
//}}}
