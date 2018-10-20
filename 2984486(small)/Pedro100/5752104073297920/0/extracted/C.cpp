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
#define T 1000

long double g[T][T], g2[T][T];

int main(){
	int cas;
	scanf("%d",&cas);
	rep(i,T) g[i][i]=1.0;
	long double tt=T;
	long double p=1.0/tt;
	rep(i,T){
		rep(a,T) rep(b,T) g2[a][b]=0.0;
		rep(a,T) rep(b,T){
			if(b==i){
				long double f = g[a][b]/tt;
				rep(z,T)
					g2[a][z]+=f;
			}else{
				g2[a][i] += p*g[a][b];
				g2[a][b] +=(1.0-p)*g[a][b];
			}
		}
		rep(a,T) rep(b,T) g[a][b]=g2[a][b];
	}
	
	fr(u,1,cas+1){
		int n;
		scanf("%d",&n);
		
		long double s=0.0;
		rep(i,n){
			int v;
			scanf("%d",&v);
			s += g[v][i];
		}
		//printf(">>>> %.10lf  %.10lf\n",s,s2);
		
		printf("Case #%d: ",u);
		if(s>1.0+1e-9) printf("BAD\n");
		else printf("GOOD\n");
	}
	
	return 0;
}
