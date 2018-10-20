#include<stdio.h>
#include<algorithm>
long long a[200], b[200];
int main()
{
	int i, j, k, L, N, cnt = 0, ans, T;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for(k=1; k<=T; k++)
	{
		scanf("%d%d", &N, &L);
		for(i=1; i<=N; i++) a[i] = b[i] = 0;
		for(i=1; i<=N; i++)
		{
			for(j=1; j<=L; j++)
			{
				int t;
				scanf("%1d", &t);
				a[i] = a[i]*2+t;
			}
		}
		for(i=1; i<=N; i++)
		{
			for(j=1; j<=L; j++)
			{
				int t;
				scanf("%1d", &t);
				b[i] = b[i]*2+t;
			}
		}
		cnt = 0;
		ans = 2147483647;
		std::sort(a+1, a+1+N);
		std::sort(b+1, b+1+N);
		for(i=1; i<=N; i++)
		{
			long long t;
			cnt = 0;
			t = a[1]^b[i];
			long long T = t;
			while(T)
			{
				if(T%2 == 1)
				{
					cnt++;
				}
				T/=2;
			}
			//if(ans <= cnt) continue;
			for(j=1; j<=N; j++)
			{
				b[j]^=t;
			}
			std::sort(b+1, b+1+N);
			for(j=1; j<=N; j++)
			{
				if(a[j]!=b[j]) break;
			}
			if(j==N+1)
			{
				if(ans >= cnt) ans = cnt;
			}
			for(j=1; j<=N; j++)
			{
				b[j]^=t;
			}
			std::sort(b+1, b+1+N);
		}
		if(ans == 2147483647)
			printf("Case #%d: NOT POSSIBLE\n", k);
		else
			printf("Case #%d: %d\n", k, ans);
	}
	return 0;
}