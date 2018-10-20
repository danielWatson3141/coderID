#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#define MAXN 1010
using namespace std;
int need[MAXN],q[MAXN],father[MAXN],sz[MAXN];
int to[2*MAXN],head[MAXN],next[2*MAXN];
struct N{
	int c,p;
	bool operator < (const N &now) const{
		return (c>now.c)||((c==now.c)&&(p<now.p));
	}
}val[MAXN];
int cnt=0;
void add(int u,int v){
	to[cnt]=v;next[cnt]=head[u];head[u]=cnt++;
}
bool vis[MAXN];
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
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++){
		int n;
		scanf("%d",&n);
		cnt=0;
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
