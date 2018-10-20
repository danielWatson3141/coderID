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

#define N 1000

int mas[1010];
int distr_good[1010][1010];
int distr_bad[1010][1010];

void precalc()
{
	int i, j;

	for (i = 0; i<100000; i++)
	{

		for (j = 0; j < N; j++) mas[j] = j;
		for (j = 0; j < N; j++)
		{
			int t = j + rand() % (N - j);
			swap(mas[j], mas[t]);
			distr_good[mas[j]][j]++;
		}
	}

	for (i = 0; i<100000; i++)
	{

		for (j = 0; j < N; j++) mas[j] = j;
		for (j = 0; j < N; j++)
		{
			int t = rand() % N;
			swap(mas[j], mas[t]);
		}
		for (j = 0; j < N; j++)
		{
			distr_bad[mas[j]][j]++;
		}
	}
}

void Solve()
{
	int i, j, k, n, m;

	in_int1(n);
	int good = 0;
	int bad = 0;
	for (i = 0; i<n; i++)
	{
		in_int1(j);
		good += distr_good[j][i];
		bad += distr_bad[j][i];
	}

	if (good >= bad) printf(" GOOD");
	else printf(" BAD");
}

int main(int argc, char**argv)
{
	if (argc > 1) freopen(argv[1], "rt", stdin);
	else freopen("input.txt", "rt", stdin);

	freopen("output.txt", "wt", stdout);
	int test;

	precalc();
	in_int1(test);
	for (int step = 1; step <= test; step++)
	{
		printf("Case #%d:", step);
		Solve();
		printf("\n");
	}
	return 0;
}