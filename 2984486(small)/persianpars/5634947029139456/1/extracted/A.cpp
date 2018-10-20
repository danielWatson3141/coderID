// written by Amirmohsen Ahanchi //
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#include <queue>
#include <map>
#include <fstream>
#include <cstring>
#include <list>
#include <iterator>
#include <complex>
#include <cassert>

#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second
#define Size(n) ((int)(n).size())
#define Foreach(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define dbg(x) "#" << #x << ": " << x 
#define spc << " " <<

using namespace std;

//#define cin fin
//#define cout fout

typedef long long LL;
typedef pair <int, int> PII; 

const int maxN = 150 + 5;

LL a[maxN], b[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		int n, k;
		cin >> n >> k;
		char c;
		rep(i, n) rep(j, k)
			cin >> c, a[i] += ((LL)(c-'0')<<(LL)j);
		rep(i, n) rep(j, k)
			cin >> c, b[i] += ((LL)(c-'0')<<(LL)j);
		map <LL, int> d;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[a[i]^b[j]]++;
		/*
		rep(i, n) cerr << a[i] << " ";
		cerr << endl;
		rep(i, n) cerr << b[i] << " " ;
		cerr << endl;
		*/
		int ans = -1;
		Foreach(it, d)
			if (it->f2 == n)
			{
				int x = 0;
				for (int y = it->f1; y > 0; x += y&1, y >>= 1);
//				int x = __builtin_popcount(it->f1);
				if (ans == -1 || ans > x) ans = x;
			}
		cout << "Case #" << t+1 << ": "; 
		if (ans == -1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
		
	}

	return 0;
}

