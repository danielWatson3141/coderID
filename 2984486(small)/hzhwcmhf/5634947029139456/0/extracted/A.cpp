#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <iomanip>
#include <string>
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include <cassert>
#include <complex>
using namespace std;
#ifdef _GLIBCXX_DEBUG
string filename(__FILE__,string(__FILE__).find(".cpp"));
#endif
#define PB push_back
#define MP make_pair
#define SIZE(a) ((int)a.size())
#define REP(x,a) for(typeof(a.begin()) x=a.begin();x!=a.end();x++)
#define ACS(a,b) (a?a->b:0)
#define EACS(a,b,c) (a?a->b:c)
#define AUTO(a,b) typeof(b) a=(b)
#define ft first
#define sd second
const int INF=0x3f3f3f3f;
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;
template<class T>
inline bool tension(T &a,const T &b)
{
	if(b<a){
		a=b;
		return true;
	}
	return false;
}
template<class T>
inline bool relax(T &a,const T &b)
{
	if(a<b){
		a=b;
		return true;
	}
	return false;
}
int T;
typedef vector<int> vi;
#define maxn 159
#define maxl 49
int N,L,ans;
char a[maxn][maxl],b[maxn][maxl];
void dfs(int p,int cost,const vector<pair<vi,vi> > &ss)
{
	if(p==L+1){
		tension(ans,cost);
		return;
	}
	
	vector<pair<vi,vi> > s0,s1;
	REP(sa,ss){
		int i;
		vi a0,a1,b0,b1;
		for(i=0;i<SIZE(sa->ft);i++){
			if(a[sa->ft[i]][p]=='0'){
				a0.PB(sa->ft[i]);
			}else{
				a1.PB(sa->ft[i]);
			}
			if(b[sa->sd[i]][p]=='0'){
				b0.PB(sa->sd[i]);
			}else{
				b1.PB(sa->sd[i]);
			}
		}
		if(SIZE(a0)==SIZE(b0)){
			s0.PB(MP(a0,b0));
			s0.PB(MP(a1,b1));
		}
		if(SIZE(a0)==SIZE(b1)){
			s1.PB(MP(a0,b1));
			s1.PB(MP(a1,b0));
		}
	}
	if(SIZE(s0)==SIZE(ss)*2){
		dfs(p+1,cost,s0);
	}
	if(SIZE(s1)==SIZE(ss)*2){
		dfs(p+1,cost+1,s1);
	}
}
int main()
{
	freopen((filename+".in").c_str(),"r",stdin);
	freopen((filename+".out").c_str(),"w",stdout);
	//freopen((filename+".err").c_str(),"w",stderr);
	scanf("%d",&T);
	int CN=0;
	while(T--){
		scanf("%d %d",&N,&L);
		int i;
		ans=INF;
		for(i=1;i<=N;i++){
			scanf(" %s",a[i]+1);
		}
		for(i=1;i<=N;i++){
			scanf(" %s",b[i]+1);
		}
		vector<pair<vi,vi> > adj;
		vi as,bs;
		for(i=1;i<=N;i++){
			as.PB(i),bs.PB(i);
		}
		adj.PB(MP(as,bs));
		dfs(1,0,adj);
		if(ans==INF){
			printf("Case #%d: NOT POSSIBLE\n",++CN);
		}else{
			printf("Case #%d: %d\n",++CN,ans);
		}
	}
	return 0;
}
