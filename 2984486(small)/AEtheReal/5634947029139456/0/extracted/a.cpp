#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back
#define INF 1000000000

int n,l;
string x[3][222];
char t[222];

int main() {	
int nt; scanf("%d", &nt); FOR(tt,1,nt+1){
	scanf("%d%d", &n, &l);
	FOR(j,0,2)FOR(i,0,n){
		scanf("%s", t);
		x[j][i] = t;
		FOR(k,0,l) x[j][i][k] -= '0';
	}
	sort(x[0], x[0]+n);
	sort(x[1], x[1]+n);
	FOR(c,0,n) x[2][c] = x[0][c];
	int ans = INF;
	FOR(i,0,n)FOR(j,0,n){
		int cans = 0;
		FOR(k,0,l){
			cans += (x[0][i][k] ^ x[1][j][k]);
		}
		if(cans >= ans) continue;
		FOR(c,0,n){
			FOR(k,0,l){
				x[2][c][k] = (x[0][c][k]^x[0][i][k]^x[1][j][k]);
			}
		}
		sort(x[2], x[2]+n);
		bool bad = false;
		FOR(c,0,n) if(x[2][c] != x[1][c]){
			bad = true;
			break;
		}
		if(bad) continue;
		ans = cans;
	}
	printf("Case #%d: ", tt);
	if(ans == INF) printf("NOT POSSIBLE\n");
	else printf("%d\n", ans);

}	
return 0;
}


