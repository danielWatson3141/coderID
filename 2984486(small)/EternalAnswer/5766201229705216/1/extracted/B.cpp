#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define int64 long long
#define Sort sort

using namespace std;

const int Maxn = 1010;
const int Maxm = 2010;

int pos[Maxn];
int data[Maxm],next[Maxm];
int son[Maxn];
int f[Maxn];
int N,tot;
bool visit[Maxn];

void Add(int x,int y)
{
	++tot;
	data[tot]=y;next[tot]=pos[x];pos[x]=tot;
}

int Calc(int x)
{
	int g[3];
	g[0]=0;g[1]=9999999;g[2]=99999999;
	son[x]=1;
	visit[x]=true;
	for (int k=pos[x];k;k=next[k])
		if (!visit[data[k]])
		{
			int nex=data[k];
			Calc(data[k]);
			son[x]+=son[nex];
			g[2] = min(g[2]+son[nex],g[1]+f[nex]);
			g[1] = min(g[1]+son[nex],g[0]+f[nex]);
			g[0] += son[nex];
		}
	return f[x]=min(g[2],g[0]);
}

int main()
{
	//freopen("input2.in","r",stdin);
	//freopen("output2.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	for (int ii=1;ii<=T;++ii)
	{
		printf("Case #%d: ",ii);
		scanf("%d",&N);
		memset(pos,0,sizeof(pos));
		tot=0;
		for (int i=1;i<N;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			Add(x,y);
			Add(y,x);
		}
		int res = 999999;
		for (int i=1;i<=N;++i)
		{
			for (int j=1;j<=N;++j) visit[j]=false;
			res = min(res,Calc(i));
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}