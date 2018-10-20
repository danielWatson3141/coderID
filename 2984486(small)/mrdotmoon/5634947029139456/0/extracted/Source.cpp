#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define INF 1000000000
#define EPS 1e-9

int N, L;
__int64 pre[151], after[151];
__int64 graph[151][151];
bool used[151];

__int64 bitCount(__int64 a)
{
	return a == 0 ? 0 : bitCount(a & (a - 1)) + 1;
}


__int64 doit(int cur, __int64 expected)
{
	if (cur == N)
	{
		return bitCount(expected);
	}
	
	if (cur == 0)
	{
		__int64 res = INF;
		for (int i = 0; i < N; i++)
		{
			used[i] = true;
			res = min(res, doit(cur + 1, pre[cur] ^ after[i]));
			used[i] = false;
		}
		return res;
	}
	
	__int64 res = INF;
	for (int i = 0; i < N; i++)
	{
		if (used[i] || ((pre[cur] ^ after[i]) != expected)) continue;
		used[i] = true;
		res = min(res, doit(cur + 1, expected));
		used[i] = false;
	}
	return res;
}

void _main()
{
	scanf("%d%d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		char str[45];
		scanf("%s", str);
		pre[i] = 0;
		for (int j = 0; j < L; j++)
		{
			pre[i] *= 2;
			pre[i] += str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		char str[45];
		scanf("%s", str);
		after[i] = 0;
		for (int j = 0; j < L; j++)
		{
			after[i] *= 2;
			after[i] += str[j] - '0';
		}
	}

	memset(used, 0, sizeof(used));
	__int64 res = doit(0, -1);
	if (res == INF) puts("NOT POSSIBLE");
	else printf("%I64d\n", res);
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		printf("Case #%d: ", cases);
		_main();
	}
}