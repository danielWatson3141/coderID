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
#define maxn 1009
int T;
vector<int> adj[maxn];
int size[maxn],f[maxn],fa[maxn];
void dfs(int p)
{
	size[p]=1;
	REP(i,adj[p]) if(fa[p]!=*i){
		fa[*i]=p;
		dfs(*i);
	}
	int max1=0,max2=0,cn=0;
	REP(i,adj[p]) if(fa[p]!=*i){
		cn++;
		size[p]+=size[*i];
		int tmp=size[*i]-f[*i];
		if(tmp>max1){
			max2=max1;
			max1=tmp;
		}else if(tmp>max2){
			max2=tmp;
		}
	}
	if(cn==1){
		f[p]=size[p]-1;
	}else{
		f[p]=size[p]-1-max1-max2;
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
		cerr<<CN<<endl;
		printf("Case #%d: ",++CN);
		int n;
		scanf("%d",&n);
		int i,u,v;
		for(i=1;i<=n;i++) adj[i].clear();
		for(i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			adj[u].PB(v);
			adj[v].PB(u);
		}
		int ans=INF;
		for(i=1;i<=n;i++){
			fa[i]=0;
			dfs(i);
			tension(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
