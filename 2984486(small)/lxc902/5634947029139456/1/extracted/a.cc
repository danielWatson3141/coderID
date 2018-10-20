#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;

const int N = 199;

int n,l;
string a[N],b[N],c[N];
int gao(string x,string y) {
    int ret=0;
    for(int j=0;j<l;j++) if(x[j]!=y[j]) ret++;
    for(int i=0;i<n;i++) {
        c[i]=a[i];
        for(int j=0;j<l;j++) if(x[j]!=y[j]) c[i][j]=1-(c[i][j]-'0') + '0';
    }
    sort(c,c+n);
    for(int i=0;i<n;i++) if(c[i]!=b[i]) return -1;
    return ret;
}

int main()
{
	int T; scanf("%d",&T);
	for(int ka=1;ka<=T;ka++) {
        scanf("%d%d\n",&n,&l);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(b,b+n);
        int ans=l+1;
        for(int i=0;i<n;i++) {
            int tmp=gao(a[0],b[i]);
            if(tmp>=0) ans=min(ans,tmp);
        }
        printf("Case #%d: ",ka);
        if(ans==l+1) puts("not possible");
        else printf("%d\n",ans);
	}

    return 0;
}
