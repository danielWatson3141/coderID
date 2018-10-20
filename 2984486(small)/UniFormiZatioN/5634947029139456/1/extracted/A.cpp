#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define FOR(ReprI,ReprS,ReprN) for(ReprI=ReprS;ReprI<ReprN;ReprI++)
#define scan(ReprN) scanf("%d",&ReprN)
#define scanLL(ReprN) scanf("%I64d",&ReprN)

#define MAX 160
#define LEN 50
long long A[MAX],B[MAX],ReA[MAX];
int rank(long long x)
{
	int s=0,i;
	for(i=0;i<LEN;i++)
		if((x>>i)&1) s++;
	return s;
}

int main()
{
//	freopen("A-large.in","r",stdin);
//	freopen("A-large_out.txt","w",stdout);
	int Test,Case,i,j;
	int N,L,Ac1,Bc1,ans,temp;
	long long K;
	scanf("%d",&Test);
	for(Case=1;Case<=Test;Case++)
	{
		scan(N);scan(L);
		ans=0;
		FOR(i,0,N*2)
		{
			getchar(); K=0;
			FOR(j,0,L) K=(K<<1)|(getchar()-'0');
			if(i<N) A[i]=K;
			else B[i-N]=K;
		}
		FOR(j,0,L)
		{
			Ac1=Bc1=0;
			FOR(i,0,N)
			{
				Ac1+=((A[i]>>j)&1);
				Bc1+=((B[i]>>j)&1);
			}
			if(Ac1!=Bc1)
			{
				if(Ac1!=N-Bc1) break;
				FOR(i,0,N) A[i]^=((long long)1<<j);
				ans++;
			}
		}
		temp=MAX+1;
		std::sort(B,B+N);
		FOR(j,0,N)
		{
			FOR(i,0,N) ReA[i] = A[i] ^ A[0] ^ B[j];
			std::sort(ReA,ReA+N);
			FOR(i,0,N)
				if(ReA[i]!=B[i]) break;
			Ac1 = rank(A[0]^B[j]);
			if(i==N && temp>Ac1) temp=Ac1;
		}
		printf("Case #%d: ",Case);
		if(temp>MAX) puts("NOT POSSIBLE");
		else printf("%d\n",ans+temp);
	}
	return 0;
}
