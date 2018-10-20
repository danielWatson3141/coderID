#include <cstdio>
#include <cstring>
#include <algorithm>
#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define EXP(i,l) for (int i=(l); i; i=qn[i])
#define LLD long long
using namespace std;

int n;
int p[1005];
int sol[1005];

double Est(){
	double T = 0, R = 0;
	FOR(i,0,n) T += abs(i - sol[p[i]]), R += abs(i - 500);
	return T - R;
}


void solve(int tc){
	FILE *f = fopen("data.cpp", "r");
	FOR(i,0,1000) fscanf(f, "%*d%d%*d", &sol[i]);
	fclose(f);

	scanf("%d", &n);
	FOR(i,0,n){
		scanf("%d", &p[i]);
	}
	double T = Est();
	printf("Case #%d: %s\n", tc, T >= -242 ? "GOOD" : "BAD");
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
