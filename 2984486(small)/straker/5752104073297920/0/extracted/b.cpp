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

int T,n,a[1010];

int main(){
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&T);
	fr(cas,T){
		bool flag=true;
		scanf("%d",&n);
		fr(i,n)
			scanf("%d",&a[i]);
		int tot=0;
		fr(i,n)
			tot+=abs(a[i]-i);
		if(tot>n) flag=false;
		printf("Case #%d: ",cas);
		if(!flag) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}

