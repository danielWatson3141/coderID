#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#define mp make_pair
#define pb push_back
#define SCAN(n) scanf("%d",&n)
#define SCAN2(a,b) scanf("%d%d",&a,&b)
#define SCANS(a) scanf("%s",a)
#define PRINT(n) printf("%d\n",n)
#define sqr(a) ((a)*(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N=1200010;
const int M=3000010;
const int INF=1e9;
const int MOD=1e9+7;
const double eps=1e-6;

int first[1010],next[2010],to[2010];
int d[1010];

void add(int x,int y,int cnt){
	next[cnt]=first[x];
	first[x]=cnt;
	to[cnt]=y;
}

int dfs(int u,int fa){
	int cnt=0;
	int m1=-1,m2=-1;
	for(int e=first[u];e!=-1;e=next[e]){
		int v=to[e];
		if(v==fa) continue;
		cnt++;
		int tmp=dfs(v,u);
		d[u]+=d[v];
		if(d[v]-tmp+1>m1){
			m2=m1;
			m1=d[v]-tmp+1;
		}
		else if(d[v]-tmp+1>m2){
			m2=d[v]-tmp+1;
		}
	}
	d[u]+=cnt;
	if(cnt<2){
		return d[u];
	}
	else{
		return d[u]-m1-m2;
	}
}

void solve(){
	int t;
	cin>>t;
	for(int cs=1;cs<=t;cs++){
		int n,x,y;
		cin>>n;
		CLR(first,-1);
		int cnt=0;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			add(x,y,cnt++);
			add(y,x,cnt++);
		}
		int ans=n-1;
		for(int i=1;i<=n;i++){
			CLR(d,0);
			int tmp=dfs(i,0);
			ans=ans<tmp?ans:tmp;
		}
		cout<<"Case #"<<cs<<": "<<ans<<endl;
	}
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    //ios :: sync_with_stdio(false);
    solve();
    return 0;
}
