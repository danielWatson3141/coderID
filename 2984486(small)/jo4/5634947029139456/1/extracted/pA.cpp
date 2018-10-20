#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int N,L;
char s[50];
ll num[2][160];
bool change[50];

int main()
{
	int T,casenum;
	scanf("%d",&T);
	for(casenum=1;casenum<=T;casenum++)
	{
		printf("Case #%d: ",casenum);
		scanf("%d%d",&N,&L);
		for(int i=0;i<=1;i++)
			for(int j=0;j<N;j++)
			{
				scanf("%s",s);
				ll t=0;
				for(int k=0;s[k];k++)
				{
					t<<=1;
					if(s[k]=='1')
						t++;
				}
				num[i][j]=t;
			}
		sort(num[1],num[1]+N);
		int ans=1000;
		for(int i=0;i<N;i++)
		{
			int use=0;
			bool yes=1;
			ll t1=num[0][0],t2=num[1][i];
			fill(change,change+L,0);
			for(int j=0;j<L;j++)
			{
				if((t1^t2)&1)
					change[j]=1,use++;
				t1>>=1,t2>>=1;
			}
			for(int j=1;j<N;j++)
			{
				ll c=1,t=0;
				for(int k=0;k<L;k++,c<<=1)
					if(change[k])
						t|=(num[0][j]&c)^c;
					else
						t|=(num[0][j]&c);
//printf("i=%d,j=%d,t=%lld\n",i,j,t);
//printf("%lld,%lld\n",num[1][0],num[1][1]);
				//if(!find(num[1],num[1]+N,t))
				if(t!=*lower_bound(num[1],num[1]+N,t))
				{
//puts("QQ");
					yes=0;
					break;
				}
			}
			if(yes)
				ans=min(ans,use);
		}
		if(ans==1000)
			puts("NOT POSSIBLE");
		else
			printf("%d\n",ans);
	}
	return 0;
}
