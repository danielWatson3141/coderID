#include <cstdio>
#include <algorithm>
#include <cstring>
long long e[50],a[500],b[500];
int bh,na,nb,i,j,ot[160][160],dv[160][160],n,L,min,ans,t,cas,CAS,ch,p[160],flg;

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	e[0]=1;
	for (i=1; i<=42; ++i) e[i]=e[i-1]<<1;
	scanf("%d",&CAS);
	for (cas=1; cas<=CAS; ++cas)
	{
		scanf("%d%d",&n,&L);
		for (i=1; i<=n; ++i)
		for (j=1; j<=L; ++j)
		{
			for (ch=getchar(); ch<=32; ch=getchar());
			ot[i][j]=ch-48;
		}
		nb=0;
		for (i=1; i<=n; ++i)
		{
			for (j=1; j<=L; ++j)
			{
				for (ch=getchar(); ch<=32; ch=getchar());
				dv[i][j]=ch-48;
			}
			if (i>1)
			{
				b[++nb]=0;
				for (j=1; j<=L; ++j)
				if (dv[i][j]) b[nb]+=e[j-1];
			}
		}
		std::sort(b+1,b+nb+1);

//		for (i=1; i<=nb; ++i) printf("b %I64d\n",b[i]);

		min=100000;
		for (t=1; t<=n; ++t)
		{
//			printf("t=%d\n",t);
			ans=0;
			for (j=1; j<=L; ++j) ans+=(p[j]=(dv[1][j]!=ot[t][j]));

//			printf("p:"); for (j=1; j<=L; ++j) printf("%d ",p[j]); printf("\n");

			na=0;
			for (i=1; i<=n; ++i)
			if (i!=t)
			{
				a[++na]=0;
				for (j=1; j<=L; ++j)
				if (ot[i][j]^p[j]) a[na]+=e[j-1];
//				printf("a %I64d\n",a[na]);
			}
			std::sort(a+1,a+na+1);
			flg=1;
			for (i=1; i<=na; ++i)
			if (a[i]!=b[i])
			{
				flg=0;
				break;
			}
			if (flg && ans<min) min=ans;
		}
		printf("Case #%d: ",cas);
		if (min==100000) printf("NOT POSSIBLE\n"); else printf("%d\n",min);
	}
	return 0;
}
