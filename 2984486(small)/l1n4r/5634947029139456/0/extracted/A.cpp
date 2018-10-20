
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <memory.h>
using namespace std;

int count_bits(int n)
{
	int c;
	for (c = 0; n; c++)
	{
		n &= n - 1;
	}
	return c;
}

int m[16];
int w[16];

int main()
{
	//freopen("A-small.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	static char s[1024];
	gets(s);

	int test_cases;
	sscanf(s, "%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		gets(s);

		int n, l;
		sscanf(s, "%d %d", &n, &l);

		gets(s);
		for (int i = 0, k = 0; i < n; i++)
		{
			m[i] = 0;
			for (int j = 0; j < l; j++, k++)
			{
				if (s[k] == '1')
				{
					m[i] |= (1<<j);
				}
			}
			k++;
		}

		gets(s);
		for (int i = 0, k = 0; i < n; i++)
		{
			w[i] = 0;
			for (int j = 0; j < l; j++, k++)
			{
				if (s[k] == '1')
				{
					w[i] |= (1<<j);
				}
			}
			k++;
		}

		sort(w, w+n);

		int ans = -1;

		const int mask = (1<<l)-1;
		int s = mask;
		while (1)
		{
			int c = 0;
			for (int j = 0; j < l; j++)
			{
				if (s & (1 << j))
				{
					for (int i = 0; i < n; i++)
					{
						m[i] ^= (1 << j);
					}
					c++;
				}
			}

			sort(m, m+n);

			bool possible = true;
			for (int i = 0; i < n; i++)
			{
				if (m[i] != w[i])
				{
					possible = false;
					break;
				}
			}

			for (int j = 0; j < l; j++)
			{
				if (s & (1 << j))
				{
					for (int i = 0; i < n; i++)
					{
						m[i] ^= (1 << j);
					}
				}
			}

			if (possible)
			{
				if (ans<0 || c<ans)
				{
					ans = c;
				}
			}

			if (!s)
			{
				break;
			}

			s = (s-1)&mask;
		}

		if (ans < 0)
		{
			printf("Case #%d: NOT POSSIBLE\n", test_case);
		}
		else
		{
			printf("Case #%d: %d\n", test_case, ans);
		}
	}

	//fclose(stdout);
	//fclose(stdin);

	return 0;
}