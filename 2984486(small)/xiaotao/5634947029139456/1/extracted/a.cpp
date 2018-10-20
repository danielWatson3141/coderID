#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=151;
typedef long long LL;
char str[50];
int n;
LL a[Maxn], b[Maxn], c[Maxn];

bool check(LL x)
{
	int i;
	for (i=0; i<n; ++i) c[i]=a[i]^x;
	sort(c, c+n);
	for (i=0; i<n; ++i)
		if (c[i]!=b[i]) return false;
	return true;
}

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T, m, i, j, k, ans;
	scanf("%d", &T);
	for (int tt=1; tt<=T; ++tt)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; ++i)
		{
			scanf("%s", str);
			a[i]=0;
			for (j=0; j<m; ++j) a[i]=a[i]*2+str[j]-'0';
		}
		for (i=0; i<n; ++i)
		{
			scanf("%s", str);
			b[i]=0;
			for (j=0; j<m; ++j) b[i]=b[i]*2+str[j]-'0';
		}
		sort(b, b+n);
		ans=m+1;
		for (i=0; i<n; ++i)
		{
			k=0;
			for (LL x=a[0]^b[i]; x; x>>=1) k+=x&1;
			if (k<ans && check(a[0]^b[i])) ans=k;
		}
		printf("Case #%d: ", tt);
		if (ans>m) puts("NOT POSSIBLE"); else printf("%d\n", ans);
	}
	return 0;
}
