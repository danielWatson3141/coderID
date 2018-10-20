#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int N,L;
int comp(const void *a,const void *b)
	{
	return strcmp((char*)a,(char*)b);
	}
int che(char cr[160][50],char want[160][50])
	{
		int i,j;
	int f=1;
	for(i=0;i<N;i++)
		{
		for(j=0;j<L;j++)
			{
			if(cr[i][j]!=want[i][j])
				f=0;
			}
		}
	return f;
	}
int main()
{
freopen("ina.txt","r",stdin);
freopen("outa.txt","w",stdout);
int T,t;
scanf("%d",&T);
int i,j,k;
int dp[160];
char cur[160][50];
char want[160][50];
int mark[160];
for(t=1;t<=T;t++)
	{
	scanf("%d",&N);
	scanf("%d\n",&L);
	for(i=0;i<N;i++)
		{
		for(j=0;j<L;j++)
			{
			scanf("%c",&cur[i][j]);
			//printf("#%c#",cur[i][j]);
			}
		cur[i][j]=0;
		scanf("%*c");
		}
	for(i=0;i<N;i++)
		{
		for(j=0;j<L;j++)
			{
			scanf("%c",&want[i][j]);
			//printf("#%c#",cur[i][j]);
			}
		want[i][j]=0;
		scanf("%*c");
		}
		qsort(want,N,sizeof(char)*50,comp);
	int c1,c2;
	long long f=((long long) 1)<<L;
	char cr[160][50];
	int ans=1000000;
//	printf("f%d\n",f);
	for(i=0;i<f;i++)
		{
		j=i;
		int aa=0;
		for(k=0;k<L;k++)
			{
			if(j&1)
				{
				aa++;
				for(int p=0;p<N;p++)
					{
					cr[p][k]=(((cur[p][k]-'0')+1)%2)+'0';
					}
				}
			else
				{
				for(int p=0;p<N;p++)
					{
					cr[p][k]=cur[p][k];
					}
				}
			j=j>>1;
			}
		qsort(cr,N,sizeof(char)*50,comp);
//		for(k=0;k<N;k++)
			{
//			for(int p=0;p<L;p++)
				{
//				printf("->%c %c<-",(int)cr[k][p],want[k][p]);
				
				}
		//	printf("%s",cr[k]);
		//	printf("%s",cur[k]);
//			printf("\n");
			}
//			printf("aa%d\n",aa);
		
		if(che(cr,want)==1)
			{
			//	printf("aa%d\n",aa);
				if(aa<ans)
					ans=aa;
			}
		}
	if(ans==1000000)
	printf("Case #%d: %s\n",t,"NOT POSSIBLE");
	else
	printf("Case #%d: %d\n",t,ans);
	}
return 0;
}
