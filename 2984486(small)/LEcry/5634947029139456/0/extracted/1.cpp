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
#define N 350
#define INF 1000000001
#define LL __int64
using namespace std;
struct node
{
	char s[12];
}s[1010],a[101],b[101];
bool bo[15];
int n,m,L;
bool cmp(node a,node b)
{
	return strcmp(a.s,b.s)<0;
}
int ans;
void gao(int now,int cnt)
{
	if(now==L)
	{
		for(int i=0;i<n;i++)
		{
			b[i]=s[i];
			for(int j=0;j<L;j++)
			{
				if(bo[j])
				{
					b[i].s[j]='1'+'0'-b[i].s[j];
				}
			}
		}
		sort(b,b+n,cmp);
		int flag=1;
		for(int i=0;i<n;i++)
		{
			if(strcmp(b[i].s,a[i].s)!=0)
			{
				flag=0;
				break;
			}
		}
		if(flag&&(cnt<ans||ans==-1))
		{
			ans=cnt;
		}
		return;
	}
	gao(now+1,cnt);
	bo[now]=true;
	gao(now+1,cnt+1);
	bo[now]=false;
}
int main() {
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int i,j,tt,ri=0;
	scanf("%d",&tt);
	while(tt--)
	{
		ans=-1;
		ri++;
		scanf("%d%d",&n,&L);
		for(i=0;i<n;i++)
			scanf(" %s",s[i].s);
		for(i=0;i<n;i++)
			scanf(" %s",a[i].s);
		sort(a,a+n,cmp);
		memset(bo,0,sizeof(bo));
		gao(0,0);
		if(ans!=-1)printf("Case #%d: %d\n",ri,ans);
		else printf("Case #%d: NOT POSSIBLE\n",ri);
	}
}
