#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define MAX 150

int t, n, l;
vector< vector<char> > device;
char s[MAX];

bool check(vector< vector<char> > outlet)
{
	sort(outlet.begin(), outlet.end());
	if(outlet == device) return 1;
	return 0;
}

int solve(vector< vector<char> > outlet, int j)
{
	if(check(outlet)) return 0;

	if(j == l) return INF;
		
	int sol1 = solve(outlet, j+1);

	for(int i=0; i<n; ++i)
	{
		if(outlet[i][j] == '1') outlet[i][j] = '0';
		else outlet[i][j] = '1';
	}
	
	return min(sol1, 1 + solve(outlet, j+1));
}

int main()
{		
	scanf("%d", &t);
	for(int tc=1; tc<=t; ++tc)
	{
		scanf("%d %d", &n, &l);
		device.clear();

		vector< vector<char> > outlet;
		for(int i=0; i<n; ++i)
		{
			scanf(" %s ", s);
			vector<char> v;
			for(int j=0; j<l; ++j) v.pb(s[j]);
			outlet.pb(v);
		}
		for(int i=0; i<n; ++i)
		{
			scanf(" %s ", s);
			vector<char> v;
			for(int j=0; j<l; ++j) v.pb(s[j]);
			device.pb(v);
		}
		sort(device.begin(), device.end());

		int sol = solve(outlet, 0);	
		
		printf("Case #%d: ", tc);
		if(sol == INF) puts("NOT POSSIBLE");
		else printf("%d\n", sol);
	}

	return 0;
}
