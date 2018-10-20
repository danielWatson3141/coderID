#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>

using namespace std;
int N;
vector<int> l[1001];
vector<int> r[1001];
int fr[1001];
int cnt=0;
int t,T;
	int start=1;
void dfs(int cur,int par)
	{
	cnt++;
	int p=r[cur].size();
	for(int i=0;i<p;i++)
		{
		if(r[cur][i]!=par)
			{
			dfs(r[cur][i],cur);
			}
		}
	}
int main()
{
freopen("inb.txt","r",stdin);
freopen("outb2.txt","w",stdout);
int i,j,k;
scanf("%d",&T);
for(t=1;t<=T;t++)
	{
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		l[i].clear();
	for(k=1;k<N;k++)
		{
		scanf("%d %d",&i,&j);
		l[i].push_back(j);
		l[j].push_back(i);
		}
	int f=1<<N;
	int ans=N-1;
	int e=0;
	for(i=0;i<f;i++)
		{
		e=0;
		for(j=1;j<=N;j++)
			{
			fr[j]=0;
			r[j].clear();
			}
//		printf("i=%d\n",i);
		
		for(j=1;j<=N;j++)
			{
			if((i&(1<<(j-1)))==0)
				continue;
//			printf("j=%d\n",j);
			start=j;
			for(k=0;k<l[j].size();k++)
				{
//				printf("%d ",l[j][k]);
				if((i&(1<<(l[j][k]-1)))!=0)
					{
					fr[l[j][k]]++;
//					printf("take\n");
					e++;				
					}
//				else
//					printf("\n");
				}
			}
		int a[5]={0};
		for(j=1;j<=N;j++)
			{
			a[fr[j]]++;
//			printf("%d ",fr[j]);
			}
		e/=2;
		int c=0;
			j=i;
			while(j)
				{
				if((j&1))
					c++;
				j/=2;
				}
				
				
//		printf("\n-%d %d %d c%d\n",i,a[2],a[3],c);

		int leaf=(c+1)/2;
		if(c && a[2]==1 && c%2==1 && a[3]==c-leaf-1 && a[1]==leaf && e==c-1)
			{
	//			printf("ff-%d %d\n",c,i);
		//	printf("cnt%d\n",cnt);
				if(N-c<ans)
				ans=N-c;
			}
		}
	printf("Case #%d: %d\n",t,ans);
	
	}
return 0;
}
