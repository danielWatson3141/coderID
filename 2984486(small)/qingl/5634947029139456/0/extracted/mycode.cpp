#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int INF = 1000000005;
const int N = 1000;
typedef __int64 ll;
string s1[N],s2[N];
ll b1[N],b2[N],x[N],xx[N];
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		int N,L,i,j;
		scanf("%d%d",&N,&L);
		for(i=0;i<N;i++)
		{
			cin >> s1[i];
			b1[i]=0;
			for(j=0;j<L;j++)
			{
				if(s1[i][j]=='0')b1[i]*=2;
				else b1[i]=b1[i]*2+1;
			}
		}
		for(i=0;i<N;i++)
		{
			cin >> s2[i];
			b2[i]=0;
			for(j=0;j<L;j++)
			{
				if(s2[i][j]=='0')b2[i]*=2;
				else b2[i]=b2[i]*2+1;
			}
		}
		int ret=-1;
		int h;
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				ll xd=(b1[i]^b2[j]);
				for(h=0;h<N;h++)
				{
					x[h]=(b1[h]^xd);
					xx[h]=b2[h];
				}
				sort(x,x+N);
				sort(xx,xx+N);
				for(h=0;h<N;h++)
				{
					//printf("xd:%I64d h:%d xh:%I64 xxh:%I64d \n",xd,h,x[h],xx[h]);
					if(x[h]!=xx[h])break;
				}
				if(h==N)
				{
					int tmp=0;
					while(xd>0)
					{
						if(xd%2)tmp++;
						xd/=2;
					}
					if(ret==-1||ret>tmp)ret=tmp;
				}
			}
		}
		printf("Case #%d: ",ca++);
		if(ret==-1)puts("NOT POSSIBLE");
		else printf("%d\n",ret);
	}
    return 0;
}
