#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <sstream>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
const int inf=1e9+7;
const long long linf=1e18;
const double pi=acos(-1.0);
typedef long double lf;
typedef vector <int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
const double eps = 1e-10;
vi a[1111];
inline bool maxx(int& a,int& b){
	if (a<b) {
		swap(a,b);return true;
	}
	return false;
}
pii dfs(int now,int from){
	int m1=-1e9,m2=-1e9;
	int s=1;
	for (int i=0;i<a[now].size();i++){
		if (a[now][i]==from) continue;
		pii temp=dfs(a[now][i],now);
		s+=temp.second;
		if (maxx(m2,temp.first))
			maxx(m1,m2);
	}
	pii cnt;
	if (m2>0) cnt=make_pair(m1+m2+1,s);
	else cnt=mp(1,s);
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;cin>>t;
	for (int tt=1;tt<=t;tt++){
		int n;cin>>n;
		for (int i=1;i<=n;i++) a[i].clear();
		for (int i=1;i<n;i++){
			int x,y;cin>>x>>y;a[x].push_back(y);
			a[y].push_back(x);
		}
		int ans=1e9;
		for (int i=1;i<=n;i++){
			pii temp=dfs(i,0);
			ans=min(ans,temp.second-temp.first);
		}
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;
}