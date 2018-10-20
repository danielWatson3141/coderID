#include <bits/stdc++.h>
using namespace std;
int cnt[1005],ord[1005],ans[1005],a,n,t;
bool cmp(int b, int c){return cnt[b]<cnt[c];}
int main(){
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&t);
	for(int x=0;x<t;x++){
		scanf("%d",&n);
		for(int y=1;y<=n;y++){
			scanf("%d",&a);
			if(y<n){
				if(a<y) cnt[x]+=a+2;
				else if(a>y) cnt[x]+=a-y;
			}
		}
		ord[x]=x;
	}
	sort(ord,ord+n,cmp);
	memset(ans,0,sizeof(ans));
	for(int x=0;x<t/2;x++) ans[ord[x]]=1;
	for(int x=0;x<t;x++){
		if(ans[x]) printf("Case #%d: BAD\n",x+1);
		else printf("Case #%d: GOOD\n",x+1);
	}
	return 0;
}
