#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

int N, x;





void input()
{
	vector<int> k;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &x);
		k.push_back(x);
	}
	set<vector<int> > kk;
	if (k[0] < 20) printf("BAD\n");
	else printf("GOOD\n");
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d: ", test);
		input();
	}

	return 0;
}