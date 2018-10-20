#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
const int oo=1073741819;
using namespace std;
int ans,n,L;
long long a[2000],b[2000],c[2000];
char ch[20000];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	cin>>T;
	for (int Case=1;T;T--,Case++) {
		printf("Case #%d: ",Case);
		scanf("%d%d",&n,&L);
		for (int i=1;i<=n;i++) {
			scanf("%s",ch+1);
			a[i]=0;
			for (int j=L;j>=1;j--) a[i]|=((ch[j]-'0')<<j);
		}
		for (int i=1;i<=n;i++) {
			scanf("%s",ch+1);
			b[i]=0;
			for (int j=L;j>=1;j--) b[i]|=((ch[j]-'0')<<j);
		}
		sort(b+1,b+n+1);
		ans=oo;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++) {
				long long d=(a[i]^b[j]);
				for (int k=1;k<=n;k++) c[k]=(a[k]^d);
				sort(c+1,c+n+1);
				bool flag=1;
				for (int k=1;k<=n;k++)
					if (c[k]!=b[k]) {
						flag=0;
						break;
					}
				if (flag) {
					int sum=0;
					for (;d;d>>=1) sum+=(d&1);
					ans=min(ans,sum);
				}
			}
		if (ans<oo) printf("%d\n",ans);
		else printf("NOT POSSIBLE\n");
	}
	return 0;
}
