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
#include <climits>
#include <cstring>

using namespace std;

#define mp make_pair
#define pp push_back
#define Sort(x) sort(x.begin(), x.end())
#define rep(i, x, y) for(int i = x; i < y; ++i)
#define Rep(i, x, y) for(int i = x; i <= y; ++i)
#define dRep(i, x, y) for(int i = x;i >= y; --i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long
#define all(v) v.begin(),v.end()
#define ii pair<int, int>
#define mem(x, v) memset(x, v, sizeof(x))
#define nl '\n'
#define MOD 1000000007

vector<string>outlet;
vector<string>devices;
	
bool possible(string change)
{
	vector<string>dev = devices;
	rep(i, 0, devices.size())
	{
		dev[i] = devices[i];
		rep(j, 0, devices[i].size())
			if(change[j] == '1')
			{
				dev[i][j] = '1' - dev[i][j] + '0';
			}
	}
	Sort(dev);
	return dev == outlet;
}

int main()
{
	int t;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("charging.txt", "w", stdout);
	cin >> t;
	int n, length;
	int res = -1;
	string temp;
	int x = 0;
	Rep(i, 1, t)
	{
		cin >> n >> length;
		outlet.resize(n);
		devices.resize(n);
		res = -1;
		rep(j, 0, outlet.size())
			cin >> outlet[j];
		rep(j, 0, outlet.size())
			cin >> devices[j];
		Sort(outlet);
		rep(j, 0, outlet.size())
		{
			temp.clear();
			x = 0;
			temp.resize(devices[0].size(), '0');
			rep(k, 0, devices[0].size())
				if(outlet[j][k] != devices[0][k])
					temp[k] = '1', x++;
			if(possible(temp))
			{
				if(res == -1)
					res = x;
				else
					res = min(res, x);
			}
		}

		cout << "Case #" << i << ": ";
		if(res == -1)
		{
			cout << "NOT POSSIBLE" << nl;
		}
		else
			cout << res << nl;
	}
	return 0;
}