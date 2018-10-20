#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int MAXN = 1011;
const int MAXM = 2000001;
const int MAXK = 50;
const int INF = 10005;

struct Edge
{
	int to;
	Edge* next;
}e[MAXM], *hd[MAXN];

int idx;

void addEdge(int from,int to,Edge* hd[MAXN])
{
	e[idx].to=to;
	e[idx].next=hd[from];
	hd[from]=&e[idx++];
}

int dp[MAXN];
int a[MAXN];
int n;

int search(int pos,int father)
{
	int k;
	Edge* p;
	k=0;
	for(p=hd[pos];p!=0;p=p->next)
		if(p->to!=father)
			search(p->to,pos);
	for(p=hd[pos];p!=0;p=p->next)
		if(p->to!=father)
		a[k++]=dp[p->to];
	if(k==0||k==1)
		dp[pos]=1;
	else
	{
		sort(a,a+k);
		dp[pos]=a[k-1]+a[k-2]+1;
	}
	return dp[pos];
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int T,cas,i,u,v,root,ans;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			hd[i]=0;
		idx=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			addEdge(u,v,hd);
			addEdge(v,u,hd);
		}
		ans=0;
		for(root=1;root<=n;root++)
		{
				for(i=1;i<=n;i++)
					dp[i]=-1;
				ans=max(ans,search(root,-1));
		}
		ans=n-ans;
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}