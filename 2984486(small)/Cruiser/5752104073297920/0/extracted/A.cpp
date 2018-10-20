#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

#define MAXN 8001
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)

int n = 1000;
int d[MAXN][1000];
int p[1000];

void main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	forn(g, MAXN) {
		srand(time(0) * (g + 5));
		
		forn(i, n)
			p[i] = i;
		forn(i, n) {
			int j = rand() % n;
			swap(p[i], p[j]);
		}
		forn(i, n)
			d[g][i] = p[i];
	}
	int a = 0, b = 0;
	__int64 tot = 0;
	forn(tt, t) {
		cin >> n;
		forn(i, n)
			cin >> p[i];
		int mn = 2000000000;
		forn(g, MAXN) {
			int c = 0;
			forn(i, n)
				c += (p[i] - d[g][i]) * (p[i] - d[g][i]);
			mn = min(mn, c);
		}
		//cout << mn << endl;
		tot += mn;
		cout << "Case #" << (tt+1) << ": ";
		if (mn <= 146602100)
			{puts("BAD"); ++a;}
		else
			{puts("GOOD"); ++b;}
	}
	cout << tot / t << endl;
	cout << a << " " << b;

}