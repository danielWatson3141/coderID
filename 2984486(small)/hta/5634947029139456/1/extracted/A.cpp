#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <ctime>
#include <set>
#include <bitset>
#include <map>
#define x first
#define y second
#define mp make_pair
#define pb push_back
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-48;
    while(isdigit(ch=getchar()))v=v*10+ch-48;
    if(f==1)return -v;else return v;
}
const int maxn=10000;
typedef long long LL;
LL n,a[maxn],b[maxn],L,c[maxn],d[maxn];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int T=get();
    for(int t=1;t<=T;t++)
    {
		cerr<<t<<endl;
		n=get(),L=get();
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<L;j++)
			{
				char ch;scanf(" %c",&ch);
				if(ch=='1')a[i]|=1ll<<j;
			}
		}
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<L;j++)
			{
				char ch;scanf(" %c",&ch);
				if(ch=='1')b[i]|=1ll<<j;
			}
		}
		sort(b+1,b+1+n);
		int ans=L+1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				LL S=a[i]^b[j];
				for(int k=1;k<=n;k++)c[k]=a[k]^S;
				sort(c+1,c+1+n);
				bool ok=1;
				for(int k=1;k<=n;k++)
					if(c[k]!=b[k])ok=0;
				if(ok)
				{
					int res=0;
					for(LL k=S;k;k-=k&-k)res++;
					ans=min(ans,res);
				}
			}
		printf("Case #%d: ",t);
		if(ans<=L)printf("%d\n",ans);else puts("NOT POSSIBLE");
			
	}
    
    return 0;
}
