#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;


int main()
{
	int T;
	vector<int> a, b, c;
	string g;
	long long int s;
	int minimum;
	
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		minimum = 100;
		int N, L;
		scanf("%d %d\n", &N, &L);
		a.resize(N);
		b.resize(N);
		c.resize(N);
		
		for(int i = 0; i < N; i++)
		{
			cin >> g;
			a[i] = 0;
			for(int j = 0; j < L; j++)
			{
				a[i] *= 2;
				a[i] += (g[j]-'0');
			}
			//printf("%d\n", a[i]);
		}
		scanf("\n");
		for(int i = 0; i < N; i++)
		{
			cin >> g;
			b[i] = 0;
			for(int j = 0; j < L; j++)
			{
				b[i] *= 2;
				b[i] += (g[j]-'0');
			}
			//printf("%d\n", b[i]);
		}
		
		sort(b.begin(), b.end());
		
		for(int x = 0; x < N; x++)
		{
			s = a[0] ^ b[x];
			
			for(int i = 0; i < N; i++)
			{
				c[i] = a[i] ^ s;
			}
			sort(c.begin(), c.end());
			
			bool ok = true;
			
			for(int i = 0; i < N; i++)
			{
				if(c[i] != b[i]) ok = false;
			}
			
			if(ok)
			{
				int possible = 0;
				for(int i = 0; i < L; i++)
				{
					if(s & (1 << i)) possible++;
				}
				minimum = min(minimum, possible);
			}
		}
		if(minimum == 100)
		{
			printf("NOT POSSIBLE\n");
		}
		else printf("%d\n", minimum);
	}

	return 0;
}
