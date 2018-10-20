#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

__int64 chartoint64(char *s)
{
	__int64 res = 0;
	int len = strlen(s);
	for (int i = 0; i < len; ++i )
	{
		res *= 2;
		res += s[i] - '0';
	}
	return res;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	__int64 A[500],B[500];
	scanf("%d",&T);
	for (int t = 1; t <= T; ++t)
	{
		int N,L;
		char str[500];
		scanf("%d%d",&N,&L);
		for (int i = 0; i < N; ++i)
		{
			scanf("%s",&str);
			A[i] = chartoint64(str);
		}
		for (int i = 0; i < N; ++i)
		{
			scanf("%s",&str);
			B[i] = chartoint64(str);
		}
		int ans = 100000000;
		for (int i = 0; i <N; ++i)
		{
			__int64 flipping = A[i] ^ B[0];
			vector<__int64> AA;
			vector<__int64> BB;
			for (int j = 0; j < N; ++j)
			{
				AA.push_back(A[j]);
				BB.push_back(B[j] ^ flipping);
			}
			sort(AA.begin(), AA.end());
			sort(BB.begin(), BB.end());
			if (AA == BB)
			{
				int numoffilp = 0;
				__int64 temp = flipping;
				while (temp > 0)
				{
					numoffilp += (temp%2);
					temp/=2;
				}
				if (ans > numoffilp)
				{
					ans = numoffilp;
				}
			}
		}
		printf("Case #%d: ",t);
		if (ans <= L)
		{
			printf("%d\n",ans);
		}
		else
		{
			printf("NOT POSSIBLE\n");
		}
	}
	return 0;
}