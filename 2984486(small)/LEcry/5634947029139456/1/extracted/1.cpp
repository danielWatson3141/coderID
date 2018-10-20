//============================================================================
// Name        : a1.cpp
// Author      : L_Ecry
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<set>
#include<vector>
#define N 1050
#define INF 1000000001
#define LL __int64
using namespace std;
struct node
{
	char s[50];
}s[160],a[160],b[160];
bool bo[160];
bool cmp(node a,node b)
{
	return strcmp(a.s,b.s)<0;
}
int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int tt,ri=0,i,j,k,n,L;
	scanf("%d",&tt);
	while(tt--)
	{
		ri++;
		scanf("%d%d",&n,&L);
		for(i=0;i<n;i++)
			scanf(" %s",s[i].s);
		for(i=0;i<n;i++)
			scanf(" %s",a[i].s);
		sort(s,s+n,cmp);
		int ans=-1;
		for(i=0;i<n;i++)
		{
			int cnt=0;
			for(j=0;j<L;j++)
			{
				if(s[0].s[j]!=a[i].s[j])
				{
					cnt++;
					bo[j]=true;
				}
				else
					bo[j]=false;
			}
			for(j=0;j<n;j++)
			{
				b[j]=a[j];
				for(k=0;k<L;k++)
				{
					if(bo[k])
						b[j].s[k]='1'+'0'-b[j].s[k];
				}
			}
			sort(b,b+n,cmp);
			int flag=1;
			for(j=0;j<n;j++)
			{
				if(strcmp(s[j].s,b[j].s)!=0)
				{
					flag=0;
					break;
				}
			}
			if(flag&&(cnt<ans||ans==-1))
			{
				ans=cnt;
			}
		}
		if(ans==-1)printf("Case #%d: NOT POSSIBLE\n",ri);
		else
			printf("Case #%d: %d\n",ri,ans);
	}
}
