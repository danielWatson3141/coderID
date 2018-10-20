#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAXN 1001

int F[MAXN];
int A[MAXN],S[MAXN];
bool Vis[MAXN];

int T,N;

int dp(int n)
{
	int i,j;
	F[0] = 0;
	for (i=1;i<=n;i++)
	{
		F[i] = 1;
		for (j=0;j<i;j++)
			if (S[j] > S[i])
			{
				F[i] = max(F[j] + 1, F[i]);
			}
	}
	int ans = 0;
	for (i=1;i<=n;i++)
	{
		ans = max(ans,F[i]);
	}
	return ans;
}

int C1,C2;

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i,j,n,ans;
	scanf("%d",&T);
	S[0] = -1;
	for (int cases=1;cases<=T;cases++)
	{
		bool good = true;
		scanf("%d",&N);
		for (i=0;i<N;i++)
			scanf("%d",&A[i]);
		printf("Case #%d: ",cases);
		
		ans = 0;
		memset(Vis,0,sizeof Vis);
		for (j=0;j<N;j++)
		{
			if (!Vis[j])
			{
				i = j;
				n = 0;
				do
				{
					Vis[i] = 1;
					S[++n] = i;
					i = A[i];
				}while (!Vis[i]); 
				ans = max(ans,dp(n));
				if (ans >= 3)
				{
					good = false;
				}
			}
		}
		
		if (ans > 50)
		{
			printf("GOOD");
		}
		else
		{
			printf("BAD");
		}
		/*
		n = 0;
		for (i=0;i<N;i++)
		{
			n += i - A[i];
		}
		
		printf("%d",ans);*/
		
		printf("\n");
	}
	return 0;
}
