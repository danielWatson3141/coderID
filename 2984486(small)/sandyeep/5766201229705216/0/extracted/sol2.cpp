#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <ctime>
#include <cassert>
#include <climits>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii > vii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
 
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MEM(a,b) memset(a,(b),sizeof(a))
#define pr(a) cout<<#a<<" = "<<(a)<<endl
#define cin(n) int (n); scanf("%d", &(n))
#define cin2(n,m) int (n),(m); scanf("%d%d",&(n),&(m))
#define sz(a) int((a).size())
#define all(a) a.begin(),a.end()
#define loop(x,a,b) for(int (x) = (a);(x)<(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define prc(a) tr(a, it) cout<<*(it)<<" "; cout<<endl
#define pra(a,n) for(int i=0; i<(n); i++) printf("%d ",((a)[i])); printf("\n") 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) scanf("%d",&((a)[i])) 
#define vin(a,n) vector<int> (a); (a).resize((n)); for(int i=0; i<(n); i++) scanf("%d",&((a)[i])) 
#define MOD 1000000007

vvi tree;
vvi itree;
bool seen[1001];
int size[1001];
int n;

void dfs(int s)
{
	rep(i, itree[s].size())
		if(!seen[itree[s][i]])
		{	seen[itree[s][i]] = 1;
			tree[s].pb(itree[s][i]);
			dfs(itree[s][i]);
		}
}

int sizec(int root)
{
	if(size[root]!=-1)
		return size[root];
	if(sz(tree[root]) == 0)
	{	size[root] = 0;
		return 0;
	}
	else
	{
		int ans = 0;
		rep(i,sz(tree[root]))
			ans+= sizec(tree[root][i]) + 1;
		size[root] = ans;
		return ans;
	}
}

int calculate(int s)
{
	if(sz(tree[s]) == 0)
		return 0;
	if(sz(tree[s]) == 1)
		return size[s];
	int ans = 0;
	vii a;
	rep(i, sz(tree[s]))
		a.pb(mp(size[tree[s][i]], tree[s][i]));
	sort(all(a));
	//pr(s);
	rep(i,sz(a)-2)
		ans+= a[i].X;
	ans += calculate(a[sz(a)-2].Y) + calculate(a[sz(a) - 1].Y);
	return ans;
}

void solve(int t)
{
	cin>>n;
	itree.clear(); itree.resize(n);
	int x, y;
	rep(i,n-1)
	{	scanf("%d%d",&x,&y);
		itree[x-1].pb(y-1);
		itree[y-1].pb(x-1);
	}
	int fans = 2000, mini;

	rep(i,n)	{
		tree.clear(); tree.resize(n); MEM(seen,0); MEM(size, -1);
		seen[i] = 1;
		
		dfs(i);
		rep(j,n)
		sizec(i);
		int ans = calculate(i);
		if(ans<fans)
			fans = ans, mini = i;
	}
	printf("Case #%d: %d\n",t,fans);
	//pr(mini);
}

int main()
{
	freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	rep(i,t)
		solve(i+1);
}