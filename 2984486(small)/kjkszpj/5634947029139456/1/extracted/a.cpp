#include <algorithm>
#include <cstdio>
#include <set>
#define REP(i, n) for (i = 0; i < (n); i++)
#define REP1(i, n) for (i = 1; i <= (n); i++)
using namespace std;

const int N = 150 +10;
const int OO = 1000000000;

int ans, n, nowtd, tdnum;

long long a[N], b[N];

set <long long> contain;

long long getin(int m)
{
	char ch;

	long long result = 0;

	while (m)
	{
		ch = getchar();
		if (ch == '0' || ch == '1')
		{
			result = (result << 1LL) + ch - '0';
			m--;
		}
	}
	return result;
}

void ri()
{
	int i, m;

	ans = OO;
	scanf("%d%d", &n, &m);
	REP(i, n) a[i] = getin(m);
	REP(i, n) b[i] = getin(m);
}

int ponderthis(long long x)
{
	int i, result = 0;

	contain.clear();
	REP(i, n) contain.insert(b[i]);
	REP(i, n) contain.erase(a[i] ^ x);
	if (contain.size()) return OO;
	while(x)
	{
		result += x & 1;
		x >>= 1LL;
	}
	return result;
}

void solve()
{
	int i;

	REP(i, n) ans = min(ans, ponderthis(a[0] ^ b[i]));
}

void print()
{
	printf("Case #%d: ", nowtd);
	if (ans == OO) printf("NOT POSSIBLE\n"); else printf("%d\n", ans);
}

int main()
{
	scanf("%d", &tdnum);
	REP1(nowtd, tdnum)
	{
		ri();
		solve();
		print();
	}
	return 0;
}
