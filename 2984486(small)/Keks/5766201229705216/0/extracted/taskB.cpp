#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 

#define pb push_back 
#define mp make_pair 
#define float long double 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 

vector<int> vec[1111];
int a[1111], d[1111];

void rec(int v, int p)
{
	int k = 0;
	for(int i = 0; i < vec[v].size(); i++)
	{
		if (vec[v][i] != p)
		{
			rec(vec[v][i], v);
			k++;
		}
	}
	d[v] = 1;
	if (k < 2)
		return;
	k = 0;
	for(int i = 0; i < vec[v].size(); i++)
	{
		if (vec[v][i] != p)
		{
			a[k++] = d[vec[v][i]];
		}
	}
	sort(a, a + k);
	d[v] = a[k - 1] + a[k - 2] + 1;
}

int main(){ 
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; test++)
	{
		cerr<<test<<endl;
		int n;
		cin >> n;
		for(int i = 0; i < n - 1; i++)
		{
			int x, y;
			cin >> x >> y;
			vec[x].pb(y);
			vec[y].pb(x);
		}
		int ans = n - 1;
		for(int i = 1; i <= n; i++)
		{
			cerr << i << endl;
			rec(i, 0);
			ans = min(ans, n - d[i]);
		}
			
		printf("Case #%d: %d\n", test, ans);		
		for(int i = 1; i <= n; i++)
			vec[i].clear();
	}
	
	
	return 0; 
} 
