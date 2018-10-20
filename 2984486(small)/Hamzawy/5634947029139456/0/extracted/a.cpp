/*
 * a.cpp
 *
 *  Created on: Apr 25, 2014
 *      Author: AhmedSamir
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#ifdef _MSC_VER
#define rep(i,m) for(decltype(m) i=0;i<m;i++)
#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#else
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define repI(i,m) for(__typeof(m.begin()) i = m.begin();i!=m.end();++i)
#define repRI(i,m) for(__typeof(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
#endif
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define EPS (1e-9)
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;

#define SMALL_INPUT
//#define LARGE_INPUT
char str[200];
int main()
{
	freopen("a.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("a-small-attempt0.in", "rt", stdin);
	freopen("a-small.txt", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("a-large.in", "rt", stdin);
	freopen("a-large.txt", "wt", stdout);
#endif
	int tc;
	scanf("%d", &tc);
	rep(T,tc)
	{

		int n, m;
		scanf("%d%d", &n, &m);
		vector<string> v1(n), v2(n);
		for (int i = 0; i < n; ++i)
		{
			scanf(" %s", str);
			v1[i] = str;
		}
		for (int i = 0; i < n; ++i)
		{
			scanf(" %s", str);
			v2[i] = str;
		}

		sort(all(v1));

		int res = m + 1;

		for (int mask = 0; mask < (1 << m); ++mask)
		{
			vector<string> temp = v2;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					if ((mask >> j) & 1) temp[i][j] = temp[i][j] == '0' ? '1' : '0';
				}
			}
			sort(all(temp));
			if (temp == v1) res = min(res, __builtin_popcount(mask));
		}
		if (res <= m) printf("Case #%d: %d\n", T + 1, res);
		else printf("Case #%d: NOT POSSIBLE\n", T + 1);

#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}
