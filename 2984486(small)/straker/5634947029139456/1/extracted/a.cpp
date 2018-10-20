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

int T,n,m;
char str[200];
long long a[200];
long long b[200];
long long d[200];

int main(){
	//freopen("A-large.in","r",stdin);
	//freopen("A-large.out","w",stdout);
	scanf("%d",&T);
	fr(cas,T){
		scanf("%d%d",&n,&m);
		fr(i,n){
			scanf("%s",str);
			a[i]=0;
			fo(j,m)
				if(str[j]-'0')
					a[i]|=1LL<<j;
		}
		fr(i,n){
			scanf("%s",str);
			b[i]=0;
			fo(j,m)
				if(str[j]-'0')
					b[i]|=1LL<<j;
		}
		int ans=m+1;
		sort(b+1,b+n+1);
		fr(i,n){
			int res=0;
			long long x=a[i]^b[1];
			fo(i,m) if(x>>i&1) res++;
			fr(j,n) d[j]=a[j]^x;
			sort(d+1,d+n+1);
			bool flag=true;
			fr(j,n)
				if(d[j]!=b[j])
					flag=false;
			if(flag) ans=min(ans,res);
		}
		printf("Case #%d: ",cas);
		if(ans>m) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}

