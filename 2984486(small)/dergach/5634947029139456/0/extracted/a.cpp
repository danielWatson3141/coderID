#pragma comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9

int bitcount(ll n)
{
	int res = 0;
	for(int i = 0; i < 50; i++)
		if(n & (1LL << i))
			res++;
	return res;
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		int res = mod;
		int N, L;
		scanf("%d %d", &N, &L);
		vector <ll> a(N), b(N);
		string s;
		for(int i = 0; i < N; i++)
		{
			cin >> s;
			for(int j = 0; j < s.size(); j++)
				if(s[j] == '1')
					a[i] |= (1LL << j);
		}
		for(int i = 0; i < N; i++)
		{
			cin >> s;
			for(int j = 0; j < s.size(); j++)
				if(s[j] == '1')
					b[i] |= (1LL << j);
		}
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
			{
				ll f = (a[i] ^ b[j]);
				map <ll, int> mp;
				for(int k = 0; k < N; k++)
				{
					mp[(a[k]^f)]++;
					mp[b[k]]--;
				}
				bool ok = true;
				for(map <ll, int> :: iterator it = mp.begin(); it != mp.end(); it++)
				{
					if(it->second != 0)
						ok = false;
				}
				if(ok)
				{
					res = min(res, bitcount(f));
				}
			}
		if(res == mod)
			printf("Case #%d: NOT POSSIBLE\n", t);
		else
			printf("Case #%d: %d\n", t, res);
	}
	return 0;
}
