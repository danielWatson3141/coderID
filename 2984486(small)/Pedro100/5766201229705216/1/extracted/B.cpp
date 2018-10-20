#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
#define fr(i,a,b)  for(int i=a;i<b;i++)
#define rep(x,y) for(int(x)=(0);(x)<(y);(x)++)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define dbg(x) cout << #x << " == " << x << endl
#define _ << " _ " <<
vector<int> adj[2010];

int rec(int v, int p){
	int f= adj[v].size();
	if(p!=-1) f--;
	if(f<2) return 1;
	
	int p1=0, p2=0;
	rep(i,adj[v].size()){
		int w = adj[v][i];
		if(w==p) continue;
		int h = rec(w,v);
		if(h>p1) p2=p1, p1=h;
		else if(h>p2) p2=h;
	}
	return p2+p1+1;
}

int main(){
	int cas;
	scanf("%d",&cas);
	fr(u,1,cas+1){
		int n;
		scanf("%d",&n);
		rep(i,n) adj[i].clear();
		rep(i,n-1){
			int a, b;
			scanf("%d %d",&a,&b);
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		
		int rsp = 10000000;
		rep(i,n){	
			int h = rec(i,-1);
			//printf(">>> %d\n",h);
			rsp = min(rsp, n - h);
		}
		printf("Case #%d: %d\n",u,rsp);
	}
	
	return 0;
}
