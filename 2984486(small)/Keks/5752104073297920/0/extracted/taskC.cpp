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

int ans;
int b[1111], c[1111];

const int qwe = 3000;

void merge(int l, int r)
{
	if (l + 1 >= r)
	{
		return;
	}
	int m = (l + r + 1) / 2;
	merge(l, m);
	merge(m, r);
	int i = l, j = m;
	for(int k = l; k < r; k++)
	{
		if ((j >= r) || (i < m && b[i] <= b[j]))
		{
			c[k] = b[i++];
		} else {
			c[k] = b[j++];
			ans += m - i;
		}
	}
	for(int i= l; i < r; i++)
	{
		b[i] = c[i];
	}
}

int main(){ 
	
	int tests;
	cin >> tests;
	int good = 0, bad = 0;
	for(int test = 1; test <= tests; test++)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		ans = 0;
		merge(0, n);
		if (n * (n - 1) / 4 - qwe < ans && ans < n * (n - 1) / 4 + qwe)
		{
			printf("Case #%d: GOOD\n", test);
			good++;
		}
		else
		{
			printf("Case #%d: BAD\n", test);
			bad++;
		}
	}
	cerr << good << " " << bad;
	return 0; 
} 
