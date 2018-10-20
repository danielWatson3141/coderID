#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
#include <assert.h>
#include <bitset>
#include <deque>

using namespace std;
#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define ll long long
#define B 33
#define MAX 100010
#define eps 1e-7
#define pi 3.14159
#define ull unsigned long long
#define MOD 1000000009

typedef vector<int> vi;
typedef pair<int,int>ii;
typedef vector<ii> vii;

int n,l,t;
string in;
int vis[11];
vector<string> out,dev;

void change(int colum)
{
	for (int i = 0; i < n; ++i)
	{
		out[i][colum] = '1' - out[i][colum] + '0';
	}
}

int solve(int curr)
{

	if (curr == l)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; ++i)
		{
			bool ok = false;
			for (int j = 0; j < n; ++j)
			{
				if (dev[i] == out[j] && !vis[j])
				{
					vis[j] = 1;
					ok = true;
					break;
				}
			}

			if (!ok)
				return INF;
		}

		return 0;
	}

	change(curr);
	
	int ret = INF;

	ret = min(ret, solve(curr + 1) + 1);
	
	change(curr);

	ret = min(ret, solve(curr + 1));

	return ret;
}

int main(void)
{
	ios :: sync_with_stdio(false);
	cin >> t;
	int cases = 0;
	while (t--)
	{
		cin >> n >> l;
		out.clear();
		dev.clear();

		for (int i = 0; i < n; ++i)
		{
			cin >> in;
			out.pb(in);
		}

		for (int i = 0; i < n; ++i)
		{
			cin >> in;
			dev.pb(in);
		}

		int ret = solve(0);

		if (ret >= INF)
		{
			cout << "Case #" << ++cases << ": " << "NOT POSSIBLE" << "\n";
		}
		else
			cout << "Case #" << ++cases << ": " << ret << "\n";
	}
	return 0;
}