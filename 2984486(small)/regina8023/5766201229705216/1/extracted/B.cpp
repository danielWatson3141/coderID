#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#define maxx 1010
using namespace std;
int need[maxx],q[maxx],father[maxx],sz[maxx];
int to[2*maxx],head[maxx],next[2*maxx];
struct N{
	int c,p;
	bool operator < (const N &now) const{
		return (c>now.c)||((c==now.c)&&(p<now.p));
	}
}val[maxx];
int countt=0;
void ST(){
	int n;
	int p[100][20],prt[100];
	memset(p,-1,sizeof(p));
	for (int i=1;i<=n;i++) p[i][0]=prt[i];
	int k;
	for (int i=1;i<=18;i++)
	 if (n>=(1<<i-1)&&n<(1<<i)) k=i-1;
	for (int j=1;j<=k;j++)
	 for (int i=1;i<=n;i++)
	  if (p[i][j-1]!=-1) p[i][j]=p[p[i][j-1]][j-1];
}
int lca(int a,int b){
	int d[100],p[100][20];
	if (d[a]<d[b]) {int t=a;a=b;b=t;}
	int k;
	for (int i=1;i<=18;i++)
	 if (d[a]>=(1<<i-1)&&d[a]<(1<<i)) k=i-1;
	for (int i=k;i>=0;i--)
	  if (d[a]-(1<<i)>=d[b]) a=p[a][i];
	if (a==b) return (a);
	for (int i=k;i>=0;i--)
	 if (p[a][i]!=-1&&p[a][i]!=p[b][i])
	   {  a=p[a][i];b=p[b][i];}
    return(p[a][0]);
}
void add(int u,int v){
	to[countt]=v;next[countt]=head[u];head[u]=countt++;
}
bool vis[maxx];
void dfs(int x){
	vis[x]=1;
	sz[x]=1;
	for (int i=head[x];i!=-1;i=next[i]){
		int v=to[i];
		if (vis[v]) continue;
		father[v]=x;
		dfs(v);
		sz[x]+=sz[v];
	}
}
void check(int x){
	for (int I=x;I>=0;I--){
		int now=q[I];
		need[now]=0;
		int num=0,sum=0;
		for (int j=head[now];j!=-1;j=next[j]){
			int v=to[j];
			if (v==father[now]) continue;
			val[num].p=need[v];
			val[num++].c=sz[v];
			sum+=sz[v];
		}
		if (num==0) continue;
		if (num==1){
			need[now]=val[0].c;
			continue;
		}
		if (num==2){
			need[now]=val[0].p+val[1].p;
			continue;
		}
		sort(val,val+num);
		need[now]=val[0].p+val[1].p;
		for (int i=2;i<num;i++)
			need[now]+=val[i].c;
	}
	return;
}

int main(){
	//freopen("B-large.in","r",stdin);
	//freopen("B-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		countt=0;
		memset(head,-1,sizeof(head));
		for (int i=0;i<n-1;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		int res=10000;
		for (int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			memset(father,0,sizeof(father));
			memset(sz,0,sizeof(sz));
			dfs(i);
			int t=0,w=0;
			q[t++]=i;
			while (t>w){
				int x=q[w];w++;
				for (int i=head[x];i!=-1;i=next[i]){
					int v=to[i];
					if (v==father[x]) continue;
					q[t++]=v;
				}
			}
			check(t-1);
			res=min(res,need[i]);
		}
		printf("Case #%d: %d\n",t,res);
	}
}

