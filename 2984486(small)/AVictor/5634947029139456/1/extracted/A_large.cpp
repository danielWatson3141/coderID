#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <limits>
#include <set>
#include <map>
#include <cassert>
#include <fstream>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

string A[200], B[200];
long long a[200], b[200], c[200];

int main()
{
	int test_cnt;
	cin >> test_cnt;
	for(int test_num=1;test_num<=test_cnt;test_num++)
	{
		int N, L;
		cin >> N >> L;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			a[i] = 0;
			for(int j=0;j<L;j++)
			{
				a[i] = 2*a[i]+A[i][j]-'0';
			}
		}
		sort(a, a+N);
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			b[i] = 0;
			for(int j=0;j<L;j++)
			{
				b[i] = 2*b[i]+B[i][j]-'0';
			}
			c[i] = b[i];
		}	
		int best = -1;
		for(int j=0;j<N;j++)
		{
			ll x = a[0] ^ c[j];
			
			for(int i=0;i<N;i++) b[i] ^=x;
			
			sort(b, b+N);
			bool ok = true;
			for(int i=0;i<N;i++)
				if (a[i] != b[i])
				{
					ok = false;
					break;
				}
			if (ok)
			{
				int y = 0;
				for(int i=0;i<L;i++)
					if ((x >> i)&1) y++;
				if (best == -1 || best > y) best = y;
				
			}
			for(int i=0;i<N;i++) b[i] ^=x;
		}
		if (best == -1)
			printf("Case #%d: NOT POSSIBLE\n", test_num);
		else
			printf("Case #%d: %d\n", test_num, best);		
		
	}
    return 0;
}
