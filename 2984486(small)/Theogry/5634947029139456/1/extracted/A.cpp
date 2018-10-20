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

int solve(){
    int N, L;
    scanf("%d%d", &N, &L);
    string x;
    int x2[151][50][6];
	FOE(i, 1, N){
        cin>>x;
        FOE(j, 0, L-1) x2[i][j+1][0] = (int)(x[j] - '0');
    }
    FOE(i, 1, N){
        cin>>x;
        FOE(j, 0, L-1) x2[i][j+1][1] = (int)(x[j] - '0');
    }
    int res = -1;
    FOE(i, 1, N){
    	//match i th 1
    	int ans = 0;
		int flip[50];
		FOE(j, 1, L) if (x2[1][j][0] != x2[i][j][1]) {ans++; flip[j] = 1;} else flip[j] = 0;
		bool ok = true;
		FOE(i, 1, N){
			bool match = false;
			FOE(j, 1, N){
				bool matching = true;
				FOE(k, 1, L) if (abs((x2[i][k][0] - x2[j][k][1])) != flip[k]) matching = false;
				if (matching) match = true;
			}
			if (!match) ok = false;
		}
		if (ok){if (res == -1) res = ans; else res = min(res, ans);}
    }
    return res;
}


int main(){
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    FOE(i, 1, T) {
        int t = solve();
        if (t == -1) printf("Case #%d: NOT POSSIBLE\n", i);
        else printf("Case #%d: %d\n", i, t);
    }
    return 0;
}
