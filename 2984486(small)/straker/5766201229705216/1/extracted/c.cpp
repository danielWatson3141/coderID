#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define X first
#define Y second
#define pb push_back
#define fr(i,n) for(int i=1;i<=n;i++)
#define fo(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

const int mod=(int)1e9+7;
const int N=2010;

int T,n;
int f[N],head[N*2],next[N*2],key[N*2],cnt;

void add(int x,int y){
	next[++cnt]=head[x];
	key[cnt]=y;
	head[x]=cnt;
}
inline bool cmp(const int &x,const int &y){
	return f[x]>f[y];
}
void dp(int x,int fa){
	int m=0,mx1=0,mx2=0;
	for(int i=head[x];~i;i=next[i])
		if(key[i]!=fa){
			dp(key[i],x);
			m++;
			if(f[key[i]]>mx1){
				mx2=mx1;
				mx1=f[key[i]];
			}
			else if(f[key[i]]>mx2)
				mx2=f[key[i]];
			
		}
	if(m<2) f[x]=1;
	else f[x]=mx1+mx2+1;
	return;
}

int main(){
//	freopen("B-large.in","r",stdin);
//	freopen("B-large1.out","w",stdout);
	scanf("%d",&T);
	fr(cas,T){
		scanf("%d",&n);
		cnt=0;
		memset(head,-1,sizeof head);
		fr(i,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y),add(y,x);
		}
		int ans=n;
		dp(1,0);
		fr(i,n){
			dp(i,0);
			ans=min(ans,n-f[i]);
		}
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}

