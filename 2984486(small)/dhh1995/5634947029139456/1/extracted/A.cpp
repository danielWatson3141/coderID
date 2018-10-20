#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
typedef long long LL;
const int N=150;
int T,Case,n,m,ans; bool b[N]; string s[N],t[N];
bool check(int L)
{
	rep(i,n) b[i]=0; if (!L) return 1;
	rep(i,n){
		bool flag=1;
		rep(j,n) if (!b[j] && s[i].substr(0,L)==t[j].substr(0,L)){flag=0,b[j]=1; break;}
		if (flag) return 0;
	}
	return 1;
}
void dfs(int j,int step)
{
	if (!check(j) || step>=ans) return;
	if (j==m){ans=min(ans,step); return;}
	int c=0,d=0;
	rep(i,n) c+=s[i][j]=='0',d+=t[i][j]=='0';
	if (c==d) dfs(j+1,step);
	if (c+d==n){
		rep(i,n) s[i][j]=char(s[i][j]^1);
		dfs(j+1,step+1);
		rep(i,n) s[i][j]=char(s[i][j]^1);
	}
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m),ans=m+1;
		rep(i,n) cin>>s[i];
		rep(i,n) cin>>t[i];
		dfs(0,0);
		printf("Case #%d: ",++Case);
		if (ans>m) printf("NOT POSSIBLE\n"); else printf("%d\n",ans);
	}
	return 0;
}

