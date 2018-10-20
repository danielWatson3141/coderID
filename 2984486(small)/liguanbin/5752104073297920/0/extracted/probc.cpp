#include <cstdio>
#include <iostream>
using namespace std;
int A[2000];
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C-small-attempt1.out","w",stdout);
	int T;
	int N;
	scanf("%d",&T);
	for (int t = 1; t <= T; ++t)
	{
		scanf("%d",&N);
		for (int i = 0; i < N; ++i)
		{
			scanf("%d",&A[i]);
		}
		if (A[0] == 0)
		{
			printf("Case #%d: BAD\n",t);
		}
		else
		{
			int num = 0;
			for (int i = 0; i < N; ++i)
			{
				if (A[i] >= i)
				{
					num++;
				}
			}
			if (num > N/2)
			{
				printf("Case #%d: GOOD\n",t);
			}
			else
			{
				printf("Case #%d: BAD\n",t);
			}
		}
	}
}