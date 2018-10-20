#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <numeric>
#include <algorithm>

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <limits.h>

using namespace std;

typedef long long ll;

#define mem(a,b) memset(a,b, sizeof a)
#define SZ(x)	(int)x.size()
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin());it!=(x.end());++it)
#define ERR 1e-7
#define PI (2.0*acos(0))
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define rep(i,n,m) for(int i = (int)n,_m=(int)m;i<_m;++i)
#define bj(stat,b) (stat & (1<<b))
#define bc(stat,b) (stat & (~(1<<b)))
#define vi vector<int> 
#define vs vector<string>

template <class T> T Abs(T x) {return x<0?-x:x;}

#define MAXN 1001
int N;
vi g[MAXN];
bool mark[MAXN];
int dp[MAXN][MAXN];
int node[MAXN][MAXN];

int rec_node(int x, int r) {
	int &ans=node[x][r];
	if(ans!=-1) return ans;
	
	ans = 1;
	rep(i,0,SZ(g[x])) {
	//	if(x==1 || x==3) {
	//		printf("%dE: node %d is %d with pp %d\n",x, g[x][i], mark[g[x][i]], r);
	//	}
		if(g[x][i]!=r) {
	//		printf("C: tree %d has node %d\n", x, g[x][i]);
			int cnt = rec_node(g[x][i], x);
			ans += cnt;

		//	if(r==3) {
		//		printf("D: %d, %d\n",g[x][i], cnt);
		//	}
		}
	}
	//printf("D: tree %d has %d nodes\n", x, ans);
	return ans;
}
int rec(int x, int r) {
	int &ans = dp[x][r];
	if(ans!=-1) return ans;

	vi egs;
	rep(i,0,SZ(g[x])) {
		//if(!mark[g[x][i]]) {
		if(g[x][i]!=r) {
			egs.pb(g[x][i]);		
		}
	}
	if(SZ(egs)==0) ans = 0;
	else if(SZ(egs)==1) {
		ans= rec_node(egs[0],x); // delete all the child tree nodes
		//mark[egs[0]]=true;
	}
	else {


		//mark[egs[0]]=true;
		//mark[egs[1]]=true;
		//ans = min(rec_node(egs[0],x)+rec_node(egs[1],x),rec(egs[0],x) + rec(egs[1], x));
		
		//ans = rec(egs[0],x) + rec(egs[1], x);
		ans = N;
		rep(i,0,SZ(egs)) {
			rep(j,i+1,SZ(egs)) {
				ans = min(ans, rec(egs[i],x)+rec(egs[j],x)+rec_node(x,r)-rec_node(egs[i],x)-rec_node(egs[j],x)-1);	
			}
		}

	}

	return ans;
}

int
main()
{
	int T;
	scanf("%d\n",&T);
	for(int t=1;t<=T;t++) {
		cin>>N;
		int u,v;
		rep(i,0,N+1) {
			g[i].clear();
		}
		rep(i,0,N-1) {
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}

		int min_=N;

		        mem (dp, -1);
		        mem (node, -1);
		rep(i,1,N+1) {


			//mem (mark, false);
			//mark[0]=true;
			//mark[i]=true;
			int cnt = rec(i,0);
			
			//printf("%d %d\n",i,cnt);
			
			min_=min(min_,cnt);
		}
		printf("Case #%d: %d\n", t, min_);
	}
}
