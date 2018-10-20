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

ll a[150], b[150], c[150], d[150];
int l, n, ans;

void rec(int cur, ll mask)
{
	if (cur == l)
	{
		ans = min(ans, __builtin_popcountll(mask));
		return;
	}
	for(int i = 0; i < n; i++)
	{
		c[i] = (a[i] & ((1LL << (cur + 1)) - 1)) ^ mask;
		d[i] = (b[i] & ((1LL << (cur + 1)) - 1));
	}
	sort(c, c + n);
	sort(d, d + n);
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		if (c[i] != d[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		rec(cur + 1, mask);
	
	mask = mask | (1LL << cur);
	for(int i = 0; i < n; i++)
	{
		c[i] = (a[i] & ((1LL << (cur + 1)) - 1)) ^ mask;
		d[i] = (b[i] & ((1LL << (cur + 1)) - 1));
	}
	sort(c, c + n);
	sort(d, d + n);
	flag = true;
	for(int i = 0; i < n; i++)
	{
		if (c[i] != d[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		rec(cur + 1, mask);
	
}

int main(){ 
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; test++)
	{
		cerr << test << endl;
		printf("Case #%d: ", test);
		scanf("%d%d", &n, &l);
		for(int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			b[i] = 0;
			for(int j = 0; j < l; j++)
			{
				b[i] *= 2;
				if (s[j] == '1')
					b[i] += 1; 
			}
		}
		for(int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			a[i] = 0;
			for(int j = 0; j < l; j++)
			{
				a[i] *= 2;
				if (s[j] == '1')
					a[i] += 1; 
			}
		}
		ans = l + 1;
		rec(0, 0);
		if (ans == l + 1)
		{
			printf("NOT POSSIBLE\n");
		} else {
			printf("%d\n", ans);
		}
	}
	
	
	return 0; 
} 
