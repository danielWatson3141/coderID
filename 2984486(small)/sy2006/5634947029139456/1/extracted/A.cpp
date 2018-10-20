#include <cstdio>
#include <algorithm>
#include <bitset>
#define mp make_pair
#define pb push_back
#define fir first
#define sec second
using namespace std;
typedef long long ll;

inline void R(int &x) {
	char ch = getchar(); x = 0;
	for (; ch<'0'; ch=getchar());
	for (; ch>='0'; ch=getchar()) x = x*10 + ch-'0';
}
const int inf = (1<<30)-1;
char ch[50];
ll a[155], b[155], c[155];
int n, l;
int chk(ll msk) {
	for (int i=0; i<n; ++i)
		c[i] = a[i] ^ msk;
	sort(c, c+n);
	for (int i=0; i<n; ++i)
		if (b[i] != c[i])
			return inf;
	return __builtin_popcountll(msk);
}
void read(ll a[]) {
	for (int i=0; i<n; ++i) {
		scanf("%s", ch);
		a[i] = 0;
		for (int j=0; j<l; ++j)
			a[i] |= ((ll)(ch[j]=='1')) << j;
	}
}
void run(int C) {
	printf("Case #%d: ", C);
	scanf("%d%d", &n, &l);
	
	read(a); read(b);
	sort(b, b+n);
	
	int ans = inf;
	for (int i=0; i<n; ++i)
		ans = min(chk(a[0] ^ b[i]), ans);
	if (ans >= inf)
		puts("NOT POSSIBLE"); else
		printf("%d\n", ans);
}
int main() {
	int T; R(T);
	for (int i=1; i<=T; ++i) run(i);
	return 0;
}
