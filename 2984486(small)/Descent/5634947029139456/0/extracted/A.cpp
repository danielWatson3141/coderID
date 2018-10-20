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

int n, m, flip[50];
char a[200][50], b[200][50];
LLD A[200], B[200];

LLD convert(char s[], int flag){
	LLD ret = 0;
	FOR(i,0,m){
		int b = (s[i] == '1');
		if (flip[i] && flag) b = 1 - b;
		if (b) ret += 1 << i;
	}
	return ret;
}

void solve(int tc){
	scanf("%d%d", &n, &m);
	FOR(i,0,n) scanf("%s", a[i]);
	FOR(i,0,n) scanf("%s", b[i]);
	
	int ret = (1 << 30);
	FOR(i,0,n){
		int cnt = 0;
		FOR(k,0,m){
			flip[k] = (a[0][k] != b[i][k]);
			cnt += flip[k];
		}
		FOR(j,0,n){
			A[j] = convert(a[j], 1);
			B[j] = convert(b[j], 0);
		}
		sort(A, A + n);
		sort(B, B + n);
		FOR(j,0,n) if (A[j] != B[j]) cnt = (1 << 30);
		ret = min(ret, cnt);
	}
	
	printf("Case #%d: ", tc);
	if (ret > m) puts("NOT POSSIBLE");
	else printf("%d\n", ret);
}

int main(){
	int tc;
	scanf("%d", &tc);
	FOE(i,1,tc) solve(i);
	return 0;
}
