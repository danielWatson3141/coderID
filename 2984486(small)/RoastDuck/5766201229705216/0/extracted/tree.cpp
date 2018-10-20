#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=20;

int N, ans, X[maxn], Y[maxn], dgr[maxn], tank[5], father[maxn];
bool flag[maxn];

int get(int x)
{
	return x==father[x]?x:(father[x]=get(father[x]));
}

bool Check()
{
	memset(dgr,0,sizeof dgr);
	memset(tank,0,sizeof tank);
	for (int i=1;i<=N;i++) father[i]=i;
	for (int i=1;i<N;i++) if (!flag[X[i]] && !flag[Y[i]])
	{
		dgr[X[i]]++, dgr[Y[i]]++;
		if (get(X[i])!=get(Y[i]))
			father[get(X[i])]=get(Y[i]);
	}
	int pos(0);
	for (int i=1;i<=N;i++) if (!flag[i])
	{
		if (!pos) pos=get(i);
		if (get(i)!=pos) return false;
		if (dgr[i]>3) return false;
		tank[dgr[i]]++;
	}
	if (tank[0])
	{
		if (tank[0]==1 && !tank[1] && !tank[2] && !tank[3]) return true;
		return false;
	}
	return tank[2]==1;
}

void Dfs(int x, int t)
{
	if (t>=ans) return;
	if (x>N)
	{
		if (Check()) ans=t;
		return;
	}
	Dfs(x+1,t);
	flag[x]=true, Dfs(x+1,t+1), flag[x]=false;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;TT++)
	{
		scanf("%d",&N);
		for (int i=1;i<N;i++) scanf("%d%d",&X[i],&Y[i]);
		ans=N;
		Dfs(1,0);
		printf("Case #%d: %d\n",TT,ans);
	}
	return 0;
}

