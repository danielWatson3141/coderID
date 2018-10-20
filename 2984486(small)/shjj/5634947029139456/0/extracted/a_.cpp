#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


const int N=150,M=40;
int g[M+2][2],need[M+2][2],a[N+3][M+3],n,m,ans;
long long A[N+3],B[N+3],It[M+3][N+3],Need[M+3][N+3];
char s[N+3][M+3],S[M+3];bool G[M+3];

bool Check()
{
memset(A,0,sizeof(A));
for (int i=1;i<=n;i++)
  for (int j=1;j<=m;j++) A[i]=A[i]*2+a[i][j];
sort(A+1,A+n+1);
for (int i=1;i<=n;i++)
  if (A[i]!=B[i]) return 0;
return 1;
}

void dfs(int w,int dep)
{
if (dep>=ans) return;
if (w>m)
  {
  if (Check()) ans=dep;
  //if (ans==5&&dep==5) {for (int i=1;i<=m;i++) if (G[i]) printf("%d ",i);puts("");}
  return;
  }
dfs(w+1,dep);
for (int i=1;i<=n;i++) a[i][w]^=1;
G[w]=1;dfs(w+1,dep+1);G[w]=0;
for (int i=1;i<=n;i++) a[i][w]^=1;
}

int main()
{
freopen("a_.in","r",stdin);
freopen("a_.out","w",stdout);
int Test,tt=0;scanf("%d",&Test);
for (;Test--;)
  {
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;i++)
    {
	scanf("%s",s[i]+1);
	for (int j=1;j<=m;j++) a[i][j]=s[i][j]-'0',g[j][s[i][j]-'0']++;
	}
  for (int i=1;i<=n;i++)
    {
	scanf("%s",S+1);
	for (int j=1;j<=m;j++)
	  {
	  need[j][S[j]-'0']++;
	  Need[j][i]=Need[j-1][i]*2+S[j]-'0';
	  }
	}
  for (int i=1;i<=n;i++) B[i]=Need[m][i];
  sort(B+1,B+n+1);
  ans=2e9;
  dfs(1,0);
  if (ans==2e9) printf("Case #%d: NOT POSSIBLE\n",++tt);
    else printf("Case #%d: %d\n",++tt,ans);
  }
}