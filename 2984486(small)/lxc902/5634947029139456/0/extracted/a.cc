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

const int N = 11;

int n,l;
string a[N],b[N],c[N];

int main()
{
	int T; scanf("%d",&T);
	for(int ka=1;ka<=T;ka++) {
        scanf("%d%d\n",&n,&l);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(b,b+n);
        int ans=l+1;
        for(int i=0;i<(1<<l);i++) {
            int cnt=0;
            for(int j=0;j<l;j++) if(i&(1<<j)) cnt++;
            for(int k=0;k<n;k++) {
                c[k]=a[k];
                for(int j=0;j<l;j++) if(i&(1<<j)) c[k][j]=1-(c[k][j]-'0')+'0';
            }
            sort(c,c+n);
            int ok=1;
            for(int k=0;k<n;k++) if(c[k]!=b[k]) ok=0;
            if(ok) ans=min(ans,cnt);
        }
        printf("Case #%d: ",ka);
        if(ans==l+1) puts("not possible");
        else printf("%d\n",ans);
	}

    return 0;
}
