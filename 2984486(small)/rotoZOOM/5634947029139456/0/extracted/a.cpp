#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define in_str(b) scanf("%s",(b))
#define in_int1(a) scanf("%d",&(a))
#define in_int2(a,b) scanf("%d%d",&(a),&(b))
#define in_int3(a,b,c) scanf("%d%d%d",&(a),&(b),&(c))
#define in_int4(a,b,c,d) scanf("%d%d%d%d",&(a),&(b),&(c),&(d))

long long outlet[160];
long long device[160];

long long FromString(char *buf)
{
	long long r = 0;
	for (int i = 0; buf[i]; i++) r = r + r + buf[i] - '0';
	return r;
}

void Solve()
{
	int i, j, k, n, m, l;
	char buf[50];

	in_int2(n, l);
	for (i = 0; i<n; i++)
	{
		in_str(buf);
		outlet[i] = FromString(buf);
	}

	for (i = 0; i<n; i++)
	{
		in_str(buf);
		device[i] = FromString(buf);
	}

	sort(device, device + n);

	int best = l + 1;

	long long t[150];
	for (i = 0; i<(1 << l); i++)
	{
		memcpy(t, outlet, n*sizeof(t[0]));
		for (j = 0; j < n; j++)
		{
			t[j] ^= i;
		}
		sort(t, t + n);
		for (j = 0; j < n && t[j] == device[j]; j++);
		if (j == n)
		{
			int cnt = 0;
			for (j = 0; j < l; j++) if (i & (1 << j)) cnt++;
			best = min(best, cnt);
		}
	}
	if (best == l + 1)printf(" NOT POSSIBLE");
	else printf(" %d", best);
}

int main(int argc, char**argv)
{
	if (argc > 1) freopen(argv[1], "rt", stdin);
	else freopen("input.txt", "rt", stdin);

	freopen("output.txt", "wt", stdout);
	int test;

	in_int1(test);
	for (int step = 1; step <= test; step++)
	{
		printf("Case #%d:", step);
		Solve();
		printf("\n");
	}
	return 0;
}