#include<cstdio>
#include<cstring>
#include<algorithm>
typedef unsigned long long ulong;

const int NMAX=150;

int N,L; ulong A[NMAX],B[NMAX];

int popcount(ulong x)
{
	int ret=0;
	while(x!=0){ret+=x&1;x>>=1;}
	return ret;
}

int solve()
{
	static ulong X[NMAX];
	int ret=L+1;
	for(int i=0;i<N;i++)
	{
		const ulong mask=A[0]^B[i];
		for(int j=0;j<N;j++)X[j]=A[j]^mask;
		std::sort(X,X+N);
		if(memcmp(X,B,N*sizeof(ulong))!=0)continue;
		ret=std::min(ret,popcount(mask));
	}
	return ret;
}

ulong input_bin()
{
	ulong ret=0;
	scanf(" ");
	for(int i=0;i<L;i++)ret=ret<<1|getchar()-'0';
	return ret;
}

void input()
{
	scanf("%d%d",&N,&L);
	for(int i=0;i<N;i++)A[i]=input_bin();
	for(int i=0;i<N;i++)B[i]=input_bin();
	std::sort(B,B+N);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		input();
		printf("Case #%d: ",t);
		const int a=solve();
		if(a<=L)printf("%d\n",a);
		else puts("NOT POSSIBLE");
	}
	return 0;
}
