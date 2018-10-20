#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory.h>
#include <time.h> 

using namespace std;
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s); i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LL long long
#define eps 1e-6
#define pi acos(-1.0)

LL max(LL a,LL b){if (a>b){return a;} else {return b;}}
LL min(LL a,LL b){if (a<b){return a;} else {return b;}}

struct P{
    double x, y;
    P(){}
    P(double x, double y):x(x) , y(y){}
    P operator+ (const P &a) const {return P(x+a.x, y+a.y);}
    P operator- (const P &a) const {return P(x-a.x, y-a.y);}
    double operator^ (const P &a) const {return x*a.x+y*a.y;}
    void in(){scanf("%lf%lf", &x, &y);}
    void out(){printf("REQUIRED %.7f %.7f\n", x, y);}
    double dist(P a, P b) {return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
    double sqdist(P a, P b) {return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}

};

int N;
int ans[999999];
int a[2001];

bool solve(){
	scanf("%d", &N);
	FOE(i, 0, N-1) scanf("%d", &a[i+1]);
	int inv[2001];
	FOE(i, 1, N) inv[i] = 0;
	FOE(i, 1, N){
		int t = a[i];
		FOE(j, 1, i-1) if (a[j] > a[i]) inv[t]++;	
	}
	int w = N;
	int t = 0;
	FOE(i, 1, N){
		t = t + w * inv[i];
		w--;	
	}
	if (t < N) return false;
	if ((N*N - t) < N) return false;
	return true;
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T;
    srand (time(NULL));
    scanf("%d", &T);
    FOE(i, 1, T) {
    	bool yes = solve();
    	if (yes) printf("Case #%d: GOOD\n", i); else printf("Case #%d: BAD\n", i);
    }
    return 0;
}
