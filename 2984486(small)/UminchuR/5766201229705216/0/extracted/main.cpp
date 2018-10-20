#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007

vector<vector<PII>> g;
int n;
int memo[1001][1001];


int DFS0(int v, int p){
	int ret = 1;
	REP(i, g[v].size()){
		if(g[v][i].first==p)continue;
		g[v][i].second=DFS0(g[v][i].first, v);
		ret += g[v][i].second;
	}
	return ret;
}

int DFS1(int v, int p){
	int ret = 66666;
	if(memo[v][p]!=-1)return memo[v][p];
	if(p==1000){
		if(g[v].size()==0)return memo[v][p]=0;
		else if(g[v].size()==1)return memo[v][p]=n-1;
		else if(g[v].size()==2)return memo[v][p]=DFS1(g[v][0].first, v)+DFS1(g[v][1].first, v);
		else{
			REP(j,g[v].size()){
				FOR(k,j+1,g[v].size()){
					ret=min(ret, n-1-g[v][j].second-g[v][k].second+DFS1(g[v][j].first, v)+DFS1(g[v][k].first, v));
				}
			}
			return memo[v][p]=ret;
		}
	}else{
		int nv=g[v].size();
		if(nv==1){
			return memo[v][p]=0;
		}else if(nv==2){
			REP(i,nv){
				if(g[v][i].first!=p){
					return memo[v][p]=g[v][i].second;
				}
			}
		}else if(nv==3){
			ret = 0;
			REP(i,nv){
				if(g[v][i].first!=p)ret += DFS1(g[v][i].first, v);
				return memo[v][p]=ret;
			}
		}
		else{
			REP(j,nv){
				if(g[v][j].first==p)continue;
				FOR(k,j+1,g[v].size()){
					if(g[v][k].first==p)continue;
					int tret = 0;
					REP(l,g[v].size()){
						if(g[v][l].first==p)continue;
						if(l==j || l==k)tret += DFS1(g[v][l].first, v);
						else tret+=g[v][l].second;
					}
					ret = min(ret, tret);
				}
			}
			return memo[v][p]=ret;
		}
	}
}


void init(){
	memset(memo, -1, sizeof(memo));
	REP(i,n-1){
		int x,y;
		scanf("%d%d", &x, &y);
		x--;y--;
		g[x].PB(MP(y,0));
		g[y].PB(MP(x,0));
	}
	DFS0(0, -1);
	REP(i,n){
		int idx=-1, cnt=0;
		REP(j,g[i].size()){
			if(g[i][j].second==0)idx=j;
			else cnt += g[i][j].second;
		}
		if(idx!=-1)g[i][idx].second = n-1-cnt;
	}
}

void solve(){
	g.clear();
	cin>>n;
	g=vector<vector<PII>>(n);
	init();
	int ret = 66666;
	REP(i,n){
		ret = min(ret, DFS1(i, 1000));
	}
	printf("%d\n", ret);
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	REP(t,T){
		printf("Case #%d: ", t+1);
		solve();
	}
	return 0;
}