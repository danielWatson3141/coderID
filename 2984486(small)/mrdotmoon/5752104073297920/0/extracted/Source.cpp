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

int perm[1000];
int N;

bool judge()
{
	if (perm[0] > N / 4 && perm[0] < N / 4 * 3)
		return false;
	return true;
}
void _main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &perm[i]);

	if (judge()) puts("GOOD");
	else puts("BAD");
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int cases = 1; cases <= T; cases++)
	{
		printf("Case #%d: ", cases);
		_main();
	}
}