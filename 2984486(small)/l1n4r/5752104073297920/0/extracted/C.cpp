
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
#include <unordered_map>
#include <iomanip>
#include <memory.h>
using namespace std;

int a[1024];

int main()
{
	int test_cases;
	scanf("%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a+i);
		}

		int s = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] >= i)
			{
				s++;
			}
		}
		const bool good = 2*s >= n;

		printf("Case #%d: %s\n", test_case, (good ? "GOOD" : "BAD"));
	}

	return 0;
}