#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

using namespace std;

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

#define DBG2 1

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

char s[50];
ll readMask()
{
	scanf("%s", s);
	ll mask = 0;
	for (int i = 0; s[i]; ++i)
		mask = mask * 2 + (s[i] - '0');
	return mask;
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		int n, l;
		scanf("%d%d", &n, &l);
		vector <ll> a(n);
		vector <ll> b(n);
		for (int i = 0; i < n; ++i)
			a[i] = readMask();
		for (int i = 0; i < n; ++i)
			b[i] = readMask();
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int res = -1;
		for (int i = 0; i < n; ++i)
		{
			ll diff = a[0] ^ b[i];
			vector <ll> c = b;
			for (int j = 0; j < n; ++j)
				c[j] = b[j] ^ diff;
			sort(c.begin(), c.end());
			if (a == c)
			{
				int cur = 0;
				for (int j = 0; j < l; ++j)
					if (diff & (1 << j))
						++cur;
				if (res == -1 || res > cur)
					res = cur;
			}
		}
		if (res == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", res);
	}

	return 0;
}
