#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>
#include <math.h>

#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SIZE(v) ((int)(v).size())
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
typedef long long ll;
typedef std::pair<ll, ll> PII;
typedef std::vector<PII> VPII;
using namespace std;

int N;
int a[16];
int edge[16][16];
int go(int cur_i)
{
	int res = 0;
	a[cur_i] = 1;
	int cnt_out = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i] == 0 && edge[i][cur_i])	cnt_out++;
	}

	int max1 = 0;
	int max1_idx = -1;
	int max2 = 0;
	int max2_idx = -1;

	if (cnt_out == 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (a[i] == 0 && edge[i][cur_i])
			{
				a[i] = 1;
				int res1 = go(i);
				res += res1;
			}
		}
	}
	else if (cnt_out > 2)
	{
		for (int i = 0; i < N; i++)
		{
			if (a[i] == 0 && edge[i][cur_i])
			{
				a[i] = 1;
				int res_ = go(i);
				if (res_ > max1)
				{
					max2 = max1;
					max2_idx = max1_idx;
					max1 = res_;
					max1_idx = i;
				}
				else if (res_ > max2)
				{
					max2 = res_;
					max2_idx = i;
				}
			}
		}
		res += (max1 + max2);
	}
	return res + 1;
}

void solve()
{
	cin >> N;
	int aa, b;
	FOR(i, 0, N){
		FOR(j, 0, N){
			edge[i][j] = 0;
			edge[j][i] = 0;
		}
		a[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> aa >> b;
		edge[aa - 1][b - 1] = 1;
		edge[b - 1][aa - 1] = 1;
	}
	int max_res = 0;
	int res = 0;
	for (int i = 0; i < N; i++){
		FOR(j, 0, N)	a[j] = 0;
		res = go(i);
		if (res > max_res)
		{
			max_res = res;
		}
	}
	cout << N - max_res << endl;
}



int main()
{
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1); 
		solve();
	}
	return 0;
}
