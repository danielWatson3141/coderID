/*
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
    	int res=getans();
    	printf("Case #%d: ",cas);
    	if(res>100) puts("NOT POSSIBLE");
    	else printf("%d\n",res);
    }
    return 0;
}
*/
/*
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
int t,n,l,a,b,res,vis;
vector<int> v[1010];
int son[1010];
int cut[1010];

void dfs(int loc,int prev) {
	int cnt=0;
	for(int i=0;i<v[loc].size();i++) {
		if(v[loc][i]!=prev) cnt++;
	}
	if(cnt==0 || cnt==1) res=min(res,n-vis);
	else {
		int tmpvis=vis,mavis=vis;
		for(int i=0;i<v[loc].size();i++) {
			for(int j=i+1;j<v[loc].size();j++) {
				if(v[loc][i]!=prev && v[loc][j]!=prev) {
					vis=tmpvis;
					vis+=2;
					dfs(v[loc][i],loc);
					dfs(v[loc][j],loc);
					mavis=max(mavis,vis);
				}
			}
		}
		vis=mavis;
		res=min(res,n-vis);
	}
}

int main()
{
	// freopen("in.txt","r",stdin);
	// freopen("out.txt","w",stdout);
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
    	for(int i=0;i<1010;i++) v[i].clear();
    	cin>>n;
    	res=n-1;
    	for(int i=1;i<n;i++) {
    		cin>>a>>b;
    		v[a].push_back(b);
    		v[b].push_back(a);
    	}
    	for(int i=1;i<=n;i++) {
    		vis=1;
    		dfs(i,-1);
    	}
    	printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}
*/
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
int t,n,l,a,b,res,vis;
vector<int> v[1010];
int son[1010];
int cut[1010];

void dfs(int loc,int prev) {
	int cnt=0;
	son[loc]=1;
	for(int i=0;i<v[loc].size();i++) {
		if(v[loc][i]!=prev) {
			cnt++;
			dfs(v[loc][i],loc);
			son[loc]+=son[v[loc][i]];
		}
	}
	if(cnt==0) {
		cut[loc]=0;
	}
	else if(cnt==1){
		cut[loc]=son[loc]-1;
	}
	else {
		int a=0,b=0;
		for(int i=0;i<v[loc].size();i++) {
			if(v[loc][i]!=prev) {
				int x=son[v[loc][i]]-cut[v[loc][i]];
				if(x>a) {
					b=a;
					a=x;
				}
				else if(x>=b) b=x;
			}
		}
		cut[loc]=son[loc]-1-a-b;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
    	for(int i=0;i<1010;i++) v[i].clear();
    	cin>>n;
    	res=n-1;
    	for(int i=1;i<n;i++) {
    		cin>>a>>b;
    		v[a].push_back(b);
    		v[b].push_back(a);
    	}
    	for(int i=1;i<=n;i++) {
    		dfs(i,-1);
    		res=min(res,cut[i]);
    	}
    	printf("Case #%d: %d\n",cas,res);
    }
    return 0;
}