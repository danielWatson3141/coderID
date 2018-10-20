//shjj-a

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int N=150,M=40;
int a[N+3][M+3],b[N+3][M+3],n,m,ans;
long long A[N+3],B[N+3],It[M+3][N+3],Need[M+3][N+3];
char s[N+3][M+3],S[M+3];bool G[M+3];

bool check()
{
for (int i=1;i<=n;i++) if (A[i]!=B[i]) return 0;
return 1;
}

int main()
{
int Test,tt=0;scanf("%d",&Test);
for (;Test--;)
  {
  scanf("%d%d",&n,&m);
  memset(B,0,sizeof(B));
  ans=0;
  for (int i=1;i<=n;i++)
    {
	scanf("%s",s[i]+1);
	for (int j=1;j<=m;j++) a[i][j]=s[i][j]-'0';
	}
  for (int i=1;i<=n;i++)
    {
	scanf("%s",s[i]+1);
	for (int j=1;j<=m;j++)
	  {
	  b[i][j]=s[i][j]-'0';
	  B[i]=B[i]*2+b[i][j];
	  }
	}
  sort(B+1,B+n+1);
  ans=2e9;
  for (int i=1;i<=n;i++)
    {
	int sl=0;
	memset(G,0,sizeof(G));
	for (int j=1;j<=m;j++)
	  if (a[1][j]!=b[i][j]) G[j]=1,sl++;
	if (sl>=ans) continue;
	for (int j=1;j<=m;j++)
	  if (G[j]) for (int k=1;k<=n;k++) a[k][j]^=1;
	memset(A,0,sizeof(A));
	for (int j=1;j<=n;j++)
	  for (int k=1;k<=m;k++) A[j]=A[j]*2+a[j][k];
	sort(A+1,A+n+1);
	if (check()) ans=sl;
	for (int j=1;j<=m;j++)
	  if (G[j]) for (int k=1;k<=n;k++) a[k][j]^=1;
	}
  if (ans==2e9) printf("Case #%d: NOT POSSIBLE\n",++tt);
    else printf("Case #%d: %d\n",++tt,ans);
  }
}