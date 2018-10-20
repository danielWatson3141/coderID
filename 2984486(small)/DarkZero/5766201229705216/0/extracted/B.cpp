#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;

struct etype
{
	int num;
	int next;
};
etype node[4000];
int p_node=0;

int edge[3000];

int size[3000];

const int INF = 1<<29;

int n,t;

int count_size(int now, int from)
{
	int e = edge[now];
	int sum=1;
	for(e;e!=0; e=node[e].next)
	{
		if(node[e].num==from)
			continue;
		sum+=count_size(node[e].num, now);
	}
	size[now] = sum;
	return sum;
}

int srch(int now, int from)
{
	int e = edge[now];
	int child=0;
	
	int fix_cost[2000]={0};
	int cut_cost[2000]={0};
	int dp[2000][3];
	memset(dp,0,sizeof(dp));
	
	for(e;  e!=0; e=node[e].next)
	{
		if(node[e].num == from)
			continue;
		child++;
		int child_cost = srch(node[e].num, now);
	    fix_cost[child] = child_cost;
	    cut_cost[child] = size[node[e].num];
	}
	
	if(child == 0)
		return 0;
	else if(child == 1)
	{
		return cut_cost[1];
	}
	else
	{
		dp[0][0] = 0;
		dp[0][2] = 0;
		dp[0][1] = INF;
		int i;
		for(i=1;i<=child;i++)
		{
			dp[i][0] = min(dp[i-1][0] + cut_cost[i], dp[i-1][1] + fix_cost[i]);
			dp[i][1] = min(dp[i-1][1] + cut_cost[i], dp[i-1][2] + fix_cost[i]);
			dp[i][2] = dp[i-1][2] + cut_cost[i];
		}
		return min(dp[child][0], dp[child][2]);
	}
}

void new_edge(int k1, int k2)
{
	p_node++;
	node[p_node].num = k2;
	node[p_node].next = edge[k1];
	edge[k1] = p_node;
	return ;
}

void init()
{
	memset(node,0,sizeof(node));
	p_node = 0;
	memset(edge, 0, sizeof(edge));
	memset(size, 0, sizeof(size));
	return;
}

int main()
{
	freopen("B.in", "r", stdin);
	freopen("B1.txt", "w", stdout);
	scanf("%d", &t);
	int files;
	for(files=1; files<=t; files++)
	{
		init();
		scanf("%d", &n);
		int i;
		for(i=1;i<=n-1;i++)
		{
			int k1,k2;
			scanf("%d %d", &k1, &k2);
			new_edge(k1,k2);
			new_edge(k2,k1);
		}
		
		int best = n+1;
		for(i=1;i<=n;i++)
		{
			memset(size, 0, sizeof(size));
			count_size(i,0);
			int now = srch(i,0);
			best = min(best, now);
		}
		
		printf("Case #%d: %d\n", files, best);
	}
	//system("pause");
	return 0;
}













