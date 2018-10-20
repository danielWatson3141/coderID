#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<29)
#define i64 long long
#define MX 1002

typedef pair<int,int> pii;

vector<int> g[MX];
int vi[MX][MX],dp[MX][MX],cnt[MX][MX];

int dfs(int u,int p){
    int &ret=dp[u][p],i,mx1=0,mx2=0,sz=g[u].size(),v,x;
    int &cc=cnt[u][p];
    if(vi[u][p])return ret;
    vi[u][p]=1;
    cc=1;
    for(i=0;i<sz;i++){
        v=g[u][i];
        if(v!=p){
            x=dfs(v,u);
            x=cnt[v][u]-x;
            cc+=cnt[v][u];
            if(x>mx1){
				mx2=mx1;
                mx1=x;
            }
            else if(x==mx1){
                mx2=mx1;
				mx1=x;
            }
            else if(x>mx2){
                mx2=x;
            }
        }
    }
	if(u!=p)sz--;
    if(sz>=2)ret=cc-mx1-mx2-1;
	else if(sz==1)ret=cc-1;
	else ret=0;
	return ret;
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
	//freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,n,cs,t=1,x,y,res,tmp;
	cin>>cs;
	while(cs--){
	    cin>>n;
	    for(i=1;i<=n;i++)g[i].clear();
	    for(i=1;i<n;i++){
	        cin>>x>>y;
	        g[x].pb(y);
	        g[y].pb(x);
	    }
	    CLR(vi);
	    res=n;
	    for(i=1;i<=n;i++){
	        tmp=dfs(i,i);
	        res=min(res,tmp);
	    }
	    printf("Case #%d: %d\n",t++,res);
	}
	return 0;
}


