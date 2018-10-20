/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int n,L,ans;
llint a[200],b[200],c[200];
char s[100];

void test(llint x)
{
	int i;
	for(i=0;i<n;i++) c[i]=a[i]^x;
	sort(c,c+n);
	for(i=0;i<n;i++) if (c[i]!=b[i]) break;
	if (i<n) return;
	ans=min(ans,__builtin_popcountll(x));
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d%d",&n,&L);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			a[i]=0;
			for(int j=0;j<L;j++) a[i]=(a[i]<<1)+(s[j]-48);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			b[i]=0;
			for(int j=0;j<L;j++) b[i]=(b[i]<<1)+(s[j]-48);
		}
		sort(b,b+n);
		ans=L+1;
		for(int i=0;i<n;i++)
			test(a[0]^b[i]);
		printf("Case #%d: ",tt);
		if (ans>L) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	
	return 0;
}
