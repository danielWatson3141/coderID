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

int nxt[55003], h = 0, bac[55003], tar[55003];  
int N, costt;

void insert(int u, int v){
	nxt[++h] = -1;	
	nxt[bac[u]] = h;
	tar[h] = v;
	bac[u] = h;
	nxt[++h] = -1;	
	nxt[bac[v]] = h;
	tar[h] = u;
	bac[v] = h;
}

int list[50004];

int DFS(int u, int p){
	if (p == -1) costt = 0;
	int  cnt = 0, total = 0;
	for (int i = nxt[u]; i > 0; i = nxt[i]){
		if (tar[i] != p){
			list[++cnt] = DFS(tar[i], u);
			total += list[cnt];
		}
	}
	int t = total + 1;
	if (cnt == 0) return t;
	if (cnt == 1) {
		costt += total;
		t = 1;
		return 1;
	} else {
		sort(list+1, list+cnt+1);
		t = list[cnt] + list[cnt - 1] + 1;
		costt += (total - t + 1);
		return t;
	}
}


int solve(){
	scanf("%d", &N);
	FOE(i, 1, N){
		nxt[i] = -1;
		bac[i] = i;	
	}
	h = N+1;
	int res = 999999;
	FOE(i, 1, N-1){
		int a, b; scanf("%d%d", &a, &b);
		insert(a, b);
	}
	FOE(i, 1, N) {DFS(i, -1);  res = min(res, costt);}
	return res;
}


int main(){
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    FOE(i, 1, T) {
        int t = solve(); printf("Case #%d: %d\n", i, t);
    }
    return 0;
}
