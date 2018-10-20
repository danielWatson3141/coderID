#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int degree[1500];
vector<int> v[1500];
int tt = 1;
int que[1500];
int tque[1500];
int qn;
int tqn;
int value[1500];
int visit[1500];
int DFS(int now,int pre)
{
	int i,j;
	if(value[now]!=0)
		return value[now];
	int mmax = 0;
	for(i=0;i<v[now].size();i++)
	{
		int k = v[now][i];
		if(pre!=k)
		{
			int va = DFS(k,now);
			for(j=0;j<v[now].size();j++)
			{
				int k1 = v[now][j];
				if(k1!=pre&&k1!=k)
				{

					int vb = DFS(k1,now);

					if(va+vb>mmax)
						mmax = va+vb;
				}
			}
		}
	}

	value[now] = mmax+1;

	return value[now];
}
int main(void)
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
	int T;
	int N;
	int a,b;
	int i,j;
	int r1,r2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<=N;i++)
			v[i].clear();
		memset(degree,0,sizeof(degree));
		for(i=0;i<N-1;i++)
		{
			scanf("%d %d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
			degree[a]++;
			degree[b]++;
		}
		r1 = -1;
		r2 = -1;
		qn = 0;
		for(i=1;i<=N;i++)
		if(degree[i]==1)
		{
			que[qn++] = i;
		}
		int nn = N;
		while(nn>2)
		{
			tqn = 0;
			for(i=0;i<qn;i++)
			{
				nn--;
				int f = que[i];
				for(j=0;j<v[f].size();j++)
				{
					degree[v[f][j]]--;
					if(degree[v[f][j]]==1)
						tque[tqn++] = v[f][j];
				}
			}
			for(i=0;i<tqn;i++)
				que[i] = tque[i];
			qn = tqn;
		}

		r1 = que[0];

		if(qn>=2)
			r2 = que[1];

		int ans = 0;
		for(i=1;i<=N;i++)
		{
			memset(value,0,sizeof(value));
			memset(visit,0,sizeof(visit));
			DFS(i,-1);
			if(value[i]>ans)
				ans = value[i];
		}
		/*DFS(r1,-1);

		if(value[r1]>ans)
			ans = value[r1];*/
		/*if(r2!=-1)
		{
			memset(value,0,sizeof(value));
			memset(visit,0,sizeof(visit));
			DFS(r2,-1);
			if(value[r2]>ans)
			ans = value[r2];
		}*/
		printf("Case #%d: %d\n",tt++,N-ans);
	}

	return 0;
}
