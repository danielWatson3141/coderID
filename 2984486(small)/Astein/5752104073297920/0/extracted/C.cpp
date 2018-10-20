#define _CRT_SECURE_NO_WARNINGS

#include <map>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> a;

void good(int N)
{
	for (int i = 0; i < N; ++i) {
		int rnd = (rand() % (N - i)) + i;
		swap(a[i], a[rnd]);
	}
}

void bad(int N)
{
	for (int i = 0; i < N; ++i) {
		int rnd = rand() % N;
		swap(a[i], a[rnd]);
	}
}

map<pair<int, int>, int> mv;
map<int, int> mv2;
map<int, int> mv3;

int main()
{
/*	srand(time(0));

	N = 1000;
	a.resize(N);
	double av1 = 0, av2 = 0;
	for (int trial = 0; trial < 10000; ++trial)
	{
		for (int i = 0; i < N; ++i) a[i] = i;
		bad(N);
		vector<int> pa = a;
		int ns1 = 0, ns2 = 0;
		for (int i = 0; i < N; ++i)
		{
			if (a[i] != i) {
				swap(a[i], a[a[i]]); 
				ns1++;
			}
		}
		a = pa;
		int ns = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			if (a[i] != i) {
				swap(a[i], a[a[i]]);
				ns2++;
			}
		}
		av1 += ns1;
		av2 += ns2;
		mv[make_pair(ns1, ns2)]++;
		mv2[ns1 - ns2] ++;
		mv3[ns1 + ns2] ++;
	}

	return 0;
*/
	int T;
	scanf("%d", &T);

	for (int cn = 1; cn <= T; ++cn)
	{
		int N;
		scanf("%d", &N);
		a.resize(N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &a[i]);

		vector<int> pa = a;
		int ns1 = 0, ns2 = 0;
		for (int i = 0; i < N; ++i)
		{
			if (a[i] != i) {
				swap(a[i], a[a[i]]);
				ns1++;
			}
		}
		a = pa;
		int ns = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			if (a[i] != i) {
				swap(a[i], a[a[i]]);
				ns2++;
			}
		}

		if (ns1 - ns2 < -10) printf("Case #%d: BAD\n", cn); else printf("Case #%d: GOOD\n", cn);
	}

}