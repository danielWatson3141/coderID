#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 1100

struct edge
{
	int v;
	edge *link;
}Mo[MAXN*2],*Mo_head,*G[MAXN];

void add_edge_t(int i,int j)
{
	edge *p = Mo_head ++;
	p->v = j;
	p->link = G[i];
	G[i] = p;
}

void add_edge(int i,int j)
{
	add_edge_t(i,j);
	add_edge_t(j,i);
}

int F[MAXN];
int T,N;

bool Vis[MAXN];

const int inf = -1314520;

int dp(int i)
{
	Vis[i] = 1;
	edge *p;
	int min0,min1,sum;
	min0 = min1 = N+1;
	sum = 0;
	for (p=G[i];p;p=p->link)
	{
		if (!Vis[p->v])
		{
			int size;
			size = dp(p->v);
			int payoff = -size + F[p->v];
			if (payoff < min0)
			{
				min1 = min0;
				min0 = payoff;
			}
			else if (payoff < min1)
			{
				min1 = payoff;
			}
			sum += size;
		}
	}
	if (min0 == N+1)
	{
		F[i] = 0;
	}
	else if (min1 == N+1)
	{
		F[i] = sum;
	}
	else
	{
		F[i] = sum + min0 + min1;
	}
	return sum + 1;
}

int Ans;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		memset(G,0,sizeof G);
		Mo_head = Mo;
		scanf("%d",&N);
		for (k=1;k<N;k++)
		{
			scanf("%d%d",&i,&j);
			add_edge(i,j);
		}
		Ans = N+1;
		for (i=1;i<=N;i++)
		{
			memset(Vis,0,sizeof Vis);
			dp(i);
			Ans = min(F[i],Ans);
		}
		printf("Case #%d: %d\n",cases,Ans);
	}
	return 0;
}
