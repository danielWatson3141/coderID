#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;

int Comp(const void *p1,const void *p2)
{
	return strcmp((char *)p1,(char *)p2);
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	char a[200][50];
	char b[200][50];
	char c[200][50];
	int mask[50];
	int aa[200], bb[200];
	
	for (int nt = 1; nt <= T; ++nt)
	{
		int N, L;
		scanf("%d%d", &N, &L);
		for (int i = 0; i < N; ++i)
			scanf("%s", &a[i]);
		for (int i = 0; i < N; ++i)
			scanf("%s", &b[i]);

		for (int i = 0; i < L; ++i)
		{
			aa[i] = bb[i] = 0;
			for (int j = 0; j < N; ++j)
			{
				aa[i] += (a[j][i] - '0');
				bb[i] += (b[j][i]  - '0');
			}
		}
		aa[L] = bb[L] = 0;
		
		int ans = 100000;
		//sort(b+1, b+N);
		qsort(b+1, N-1, sizeof(b[0]), Comp);
		for (int k = 0; k < N; ++k)
		{
			int as = 0;
			for (int i = 0; i <= L; ++i)
				if (a[k][i] == b[0][i])
				{
					if ( aa[i] != bb[i])
					{
						as = 100000;
						break;
					}

					mask[i] = 0;
					for (int j = 0; j < k; ++j)
						c[j][i] = a[j][i];
					for (int j = k+1; j < N; ++j)
						c[j-1][i] = a[j][i];
				}
				else
				{

					if ( aa[i] + bb[i] != N)
					{
						as = 100000;
						break;
					}

					mask[i] = 1;
					as++;

					for (int j = 0; j < k; ++j)
						c[j][i] ='0'+'1'-a[j][i];
					for (int j = k+1; j < N; ++j)
						c[j-1][i] = '0'+'1'-a[j][i];
				}
			//sort(c, c+N-1);
			if (as != 100000)
			{
				qsort(c, N-1, sizeof(c[0]), Comp);
				for (int j = 0; j < N - 1; ++j)
					for (int i = 0; i < L; ++i)
						if (c[j][i] != b[j+1][i])
						{
							as = 100000;
							j = N;
							break;
						}
			}
			if (as < ans)
				ans = as;
		}
		
		if (ans == 100000)
			printf("Case #%d: NOT POSSIBLE\n", nt);
		else
			printf("Case #%d: %d\n", nt, ans);

		
	}
	return 0;
}