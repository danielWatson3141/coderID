#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<string>
#include<ctime>
#include<cmath>
#include<utility>
#include<set>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
#define INF 1111111111
#define N 155
#define M 44
#define eps 1e-9
using namespace std;
typedef long long LL;
int getint()
{
	char ch;
	do
	{
		ch=getchar();
	}while (ch!='-'&&(ch<'0'||ch>'9'));
	int ans=0,f=0;
	if (ch=='-') f=1; else ans=ch-'0';
	while (isdigit(ch=getchar())) ans=ans*10+ch-'0';
	if (f) ans*=-1;
	return ans;
}
string S[N],T[N],SS[N],TT[N];
bool tmp[N];
void solve(int id)
{
	int n=getint(),l=getint(),ans=INF;
	for (int i=1;i<=n;i++) cin>>S[i];
	for (int i=1;i<=n;i++) cin>>T[i];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	{
		for (int k=0;k<l;k++) tmp[k]=S[i][k]!=T[j][k];
		for (int k=1;k<=n;k++) SS[k]=S[k],TT[k]=T[k];
		for (int k=1;k<=n;k++)
		for (int kk=0;kk<l;kk++)
		if (tmp[kk])
		{
			if (SS[k][kk]=='0') SS[k][kk]='1'; else SS[k][kk]='0';
		}
		bool f=true;
		int tot=0;
		sort(&SS[1],&SS[n+1]);
		sort(&TT[1],&TT[n+1]);
		for (int k=1;k<=n;k++) if (SS[k]!=TT[k]) f=false;
		if (f)
		{
			for (int k=0;k<l;k++) tot+=tmp[k];
			ans=min(ans,tot);
		}
	}
	if (ans==INF) printf("Case #%d: NOT POSSIBLE\n",id);
	else printf("Case #%d: %d\n",id,ans);
	return ;
}
int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int test=getint();
	for (int i=1;i<=test;i++) solve(i);
	return 0;
}
