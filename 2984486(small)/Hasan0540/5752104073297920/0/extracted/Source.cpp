#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
int n, v[1024];
int main()
{
	freopen("src.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	srand(time(0));
	scanf("%d", &t);
	int g = rand() % t;
	vector<int> sol(g, false);
	sol.resize(t, true);
	for (int it = 0; it < 1024;++it)
	for (int i = 0; i<t; ++i)
		swap(sol[i], sol[rand() % (t - i) + i]);
	for (int k = 1; k <= t; ++k){
		printf("Case #%d: ", k);
		if (sol[k-1])
			puts("BAD");
		else
			puts("GOOD");
	}
	return 0;
}