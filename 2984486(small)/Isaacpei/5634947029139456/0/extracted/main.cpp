#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;
typedef long long ll;
//const int mod=1e9+7;
//const int M = 100005;
int t,n,l;
int a[200];
int b[200];
int vis[200];

void trans(int x) {
	for(int i=0;i<l;i++) {
		if(x&(1<<i)) {
			for(int j=0;j<n;j++) b[j]^=(1<<i);
		}
	}
}

bool ok(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) {
		bool jud=0;
		for(int j=0;j<n;j++){
			if(!vis[j] && b[j]==a[i]) {
				vis[j]=1;
				jud=1;
			}
		}
		if(!jud) return 0;
	}
	return 1;
}

int get(int x){
	int cnt=0;
	while(x) {
		cnt+=x%2;
		x/=2;
	}
	return cnt;
}

int getans() {
	int res=1000;
	for(int i=0;i<(1<<l);i++) {
		trans(i);
		if(ok()) res=min(res,get(i));
		trans(i);
	}
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
    	cin>>n>>l;
    	for(int i=0;i<n;i++) {
    		int tmp=0,val=0;
    		for(int j=0;j<l;j++){
    			scanf("%1d",&tmp);
    			val=val*2+tmp;
    		}
    		b[i]=val;
    	}
    	for(int i=0;i<n;i++) {
    		int tmp=0,val=0;
    		for(int j=0;j<l;j++){
    			scanf("%1d",&tmp);
    			val=val*2+tmp;
    		}
    		a[i]=val;
    	}
    	//trans(1);
    	//for(int i=0;i<3;i++) cout<<b[i]<<endl;
    	int res=getans();
    	printf("Case #%d: ",cas);
    	if(res>100) puts("NOT POSSIBLE");
    	else printf("%d\n",res);
    }
    return 0;
}


