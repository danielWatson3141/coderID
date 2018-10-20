#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#include <set>

typedef long long int LL;
using namespace std;

LL flip (LL v, LL mask, int l)
{
	for (int k = 0; k < l; ++k)
		if ((mask>>k)&1) v = v ^ (1<<k);
	return v;
}

int main (void)
{
	int T;
	cin >> T;
	int caso = 1;
	while (T--)
	{
		int n, l;
		cin >> n >> l;
		vector <LL> o(n), e(n);

		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			LL r = 0;
			for (int j = 0; j < s.size(); ++j)
				if (s[j] == '1') r = r | (1<<j);
			o[i] = r;
		}

		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			LL r = 0;
			for (int j = 0; j < s.size(); ++j)
				if (s[j] == '1') r = r | (1<<j);
			e[i] = r;
		}

		int res = -1;
		for (int i = 0; i < (1<<l)-1; ++i)
		{
			set<LL> O;
			for (int j = 0; j < n; ++j)
				O.insert(flip(o[j], i, l));

			bool ok = true;
			for (int j = 0; j < n; ++j)
				if (O.find(e[j]) == O.end()) ok = false;

			if (ok) {
				if (res == -1) res = __builtin_popcount(i);
				else res = min(res, __builtin_popcount(i));
			}
		}
		printf("Case #%d: ", caso++);
		if (res == -1) printf("NOT POSSIBLE\n");
		else printf("%d\n", res);
	}	

	return 0;
}