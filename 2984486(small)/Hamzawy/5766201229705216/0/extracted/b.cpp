/*
 * b.cpp
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
#define rep(i,m) for(int i=0;i<m;i++)
//#define repI(i,m) for(decltype(m.begin()) i = m.begin();i!=m.end();++i)
//#define repRI(i,m) for(decltype(m.rbegin()) i = m.rbegin();i!=m.rend();++i)
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

vii adj;

int mem[1010][1010];
int mem_count[1010][1010];
int count(int n, int p)
{
	int& res = mem_count[n][p];
	if (res != -1) return res;
	res = 1;
	for (int i = 0; i < adj[n].size(); ++i)
	{
		if (adj[n][i] == p) continue;
		res += count(adj[n][i], n);
	}
	return res;
}

int calc(int n, int p)
{
	int &res = mem[n][p];
	if (res != -1) return res;
	res = adj.size();
	int cnt = 0;
	int arr[4];
	for (int i = 0; i < adj[n].size() && cnt <= 2; ++i)
	{
		if (adj[n][i] == p) continue;
		arr[cnt++] = adj[n][i];
	}
	if (!cnt) return res = 0;
	if (cnt > 2) return res = adj.size();
	if (cnt == 1) return res = count(arr[0], n);
	return res = calc(arr[0], n) + calc(arr[1], n);
}

void dfs(int n, int p)
{
	//	cerr << n << endl;
	for (int i = 0; i < adj[n].size(); ++i)
	{
		if (adj[n][i] == p) continue;
		cerr << n << "->" << adj[n][i] << endl;
	}
	for (int i = 0; i < adj[n].size(); ++i)
	{
		if (adj[n][i] == p) continue;
		dfs(adj[n][i], n);
	}
}

int main()
{
	freopen("b.in", "rt", stdin);
#ifdef SMALL_INPUT
	freopen("b-small-attempt1.in", "rt", stdin);
	freopen("b-small.txt", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("b-large.in", "rt", stdin);
	freopen("b-large.txt", "wt", stdout);
#endif
	int tc;
	scanf("%d", &tc);
	rep(T,tc)
	{

		int n, x, y;
		scanf("%d", &n);
		adj.clear();
		adj.resize(n + 1);
		for (int i = 0; i < n - 1; ++i)
		{
			scanf("%d%d", &x, &y);
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		memset(mem, -1, sizeof mem);
		memset(mem_count, -1, sizeof mem_count);
		int res = n;
		for (int i = 1; i <= n; ++i)
			count(i, 0);
		int root;
		for (int i = 1; i <= n; ++i)
		{
			if (res > calc(i, 0))
			{
				res = calc(i, 0);
				root = i;
			}
		}
		printf("Case #%d: %d\n", T + 1, res);
		dfs(root, 0);
		cerr << res << endl;

#ifdef SMALL_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
#ifdef LARGE_INPUT
		cerr << T + 1 << " of " << tc << " is done." << endl;
#endif
	}
	return 0;
}
