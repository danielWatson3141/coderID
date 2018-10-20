#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sys/time.h>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
ll GETi() { ll i;scanf("%lld",&i); return i;}
//-------------------------------------------------------

int N;
vector<int> E[1001];
int D[1001],ND[1000];
int C[1001];
int mask,did;

/*
int dfs(int cur,int pre,int d) {
	C[cur]=pre;
	int i,tot=0,nu=0;
	ND[cur]=1;
	
	vector<pair<int,int> > V;
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre) continue;
		V.push_back(make_pair(dfs(tar,cur,d+1),tar));
		ND[cur]+=ND[tar];
	}
	if(V.size()==0) return 0;
	if(V.size()==1) return ND[V[0].second];
	if(V.size()==2) return V[0].first+V[1].first;
	
	tot=10000;
	FOR(x,V.size()) for(y=x+1;y<.size();y++) {
	}
	
	sort(V.begin(),V.end());
	
	FOR(i,V.size()-2) tot+=ND[V[i].second];
	return tot;
}
*/
int valid(int cur,int pre) {
	int v=1;
	int nu=0,i;
	did |= 1<<cur;
	FOR(i,E[cur].size()) {
		int tar=E[cur][i];
		if(tar==pre) continue;
		if((mask&(1<<tar))==0) continue;
		nu++;
		v &= valid(tar,cur);
	}
	if(nu!=0 && nu!=2) v=0;
	return v;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	
	cin>>N;
	FOR(i,N) E[i].clear();
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	int ret=N;
	FOR(mask,1<<N) {
		FOR(x,N) if(mask&(1<<x)) {
			did=0;
			if(valid(x,-1) && did==mask) {
				ret=min(ret,N-__builtin_popcount(mask));
			}
		}
	}
	/*
	FOR(i,N) {
		ZERO(D);
		ZERO(C);
		ZERO(ND);
		_P("%d %d\n",i,dfs(i,-1,0));
		ret=min(ret,dfs(i,-1,0));
	}
	*/
	_P("Case #%d: %d\n",_loop,ret);
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


