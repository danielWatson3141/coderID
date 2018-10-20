#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector> 
using namespace std;

const int L = 50, N = 160;

char outlet[N][L];
char device[N][L];
bool inverse[L]; int l;

bool match (int a, int b)
{
	for (int i = 0; i < l; i++)
	{
		if (inverse[i] && outlet[a][i] == device[b][i]) return false;
		else if (!inverse[i] && outlet[a][i] != device[b][i]) return false;
	}
	return true;
}

int main ()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int n; scanf("%d %d", &n, &l);
		for (int i = 0; i < n; i++) scanf("%s", outlet[i]);
		for (int i = 0; i < n; i++) scanf("%s", device[i]);
		int ans = -1;
		for (int tt = 0; tt < n; tt++)
		{
			// printf("LET %d\n", tt);
			int tans = 0;
			for (int i = 0; i < l; i++)
			{
				inverse[i] = (outlet[0][i] != device[tt][i]);
				if (inverse[i]) ++tans;
			}
			// if (ans >= 0 && ans <= tans) continue;
			bool matched[N];
			memset(matched, 0, sizeof matched);
			matched[tt] = true;
			bool all_match = true;
			for (int i = 1; i < n; i++)
			{
				bool ok = false;
				for (int j = 0; j < n; j++) if (!matched[j])
				{
					if (match(i, j))
					{
						// printf("%d (%s): %d (%s)\n", i, outlet[i], j, device[j]);
						ok = true, matched[j] = true;
						break;
					}
				}
				if (!ok)
				{
					// printf("MIS_MATCH: %d\n", i);
					all_match = false;
					break;
				}
			}
			if (all_match)
			{
				if (ans == -1 || ans > tans) ans = tans;
			}
		}
		printf("Case #%d: ", kase);
		if (ans == -1) printf("NOT POSSIBLE\n");
		else printf("%d\n", ans);
	} 
	return 0;
}
