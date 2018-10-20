#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;

vector<ll> source;
vector<ll> destin;
const int N = 200;
ll b[N][N];
bool used[N];
int n = 0, l = 0;
inline int getone(ll x)
{
	int ret = 0;
	while(x)
	{
		ret += 1;
		x &= (x - 1);
	}
	return ret;
}
inline ll convert(string x)
{
	ll ret = 0;
	int len = x.length();
	for(int i = 1; i <= len; ++i)
	{
		if(x[len - i] == '1')
		{
			ret += (ll(1) << (i - 1));
		}
	}
	return ret;
}
inline int solve()
{
	ll m = 0;
	vector<int> ret;
	int i = 0, j = 0, k = 0;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			b[i][j] = source[i] ^ destin[j];
		}
	}
	for(i = 0; i < n; ++i)
	{
		m = b[0][i];
		memset(used, 0, sizeof(used));
		used[i] = true;
		for(j = 1; j < n; ++j)
		{
			for(k = 0; k < n; ++k)
			{
				if(b[j][k] == m && !used[k])
				{
					used[k] = true;
				}
			}
		}
		for(j = 0; j < n; ++j)
		{
			if(!used[j]) { break; }
		}
		if(j == n) { ret.push_back(getone(m)); }
	}
	if(ret.size() == 0) { return -1; }
	sort(ret.begin(), ret.end());
	return ret[0];
}
int main()
{
	int t = 0, r = 0;		
	int i = 0, j = 0;
	char buffer[2048];

	FILE* in = freopen("D:/Lab/Contests/Contests/file/A-large.in", "r", stdin);
	FILE* out = freopen("D:/Lab/Contests/Contests/file/A-large.out", "w", stdout);

	fscanf(in, "%d", &t);

	for(i = 0; i < t; i++)
	{
		source.clear();
		destin.clear();
		fscanf(in, "%d %d", &n, &l);

		for(j = 0; j < n; ++j)
		{
			fscanf(in, "%s", buffer);
			source.push_back(convert(buffer));
		}
		for(j = 0; j < n; ++j)
		{
			fscanf(in, "%s", buffer);
			destin.push_back(convert(buffer));
		}
		r = solve();
		if(r == -1)
		{
			fprintf(out, "Case #%d: %s\n", (i + 1), "NOT POSSIBLE");
		}
		else
		{
			fprintf(out, "Case #%d: %d\n", (i + 1), r);
		}
	}

	fclose(out);
	fclose(in);

	return 0;
}