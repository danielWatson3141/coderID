#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

struct node {int to,cost; };

typedef vector< vector<node> > G;

void add_edge(G& g,int from,int to,int cost=1){
	node in; in.to=to; in.cost=cost;
	g[from].pb(in);
}

void add_both_edge(G& g,int from,int to,int cost=1){	
	add_edge(g,from,to,cost);
	add_edge(g,to,from,cost);
}


int visited[20];

int dfs(G& g,int i,int d=0){
	//dump(i)
	visited[i]=d;
	int res=0;
	int cur=0;
	int n=g[i].size();
	rep(j,n){
		int to=g[i][j].to;
		//dump(to)
		if(visited[to]==-1){
			res+=dfs(g,to,d+1);
			cur++;
		}
	}
	if(cur>=3)
		res+=cur-2;
	else if(cur==1)
		res++;
	//dump(res)
	return res;
}

int main(void){
	int t;
	cin >> t;
	rep(loop,t){
		int n;
		cin >> n;
		G graph(n+1);
		rep(i,n-1){
			int a,b;
			cin >> a >> b;
			add_both_edge(graph,a,b);
		}
		int ans=inf;
		rep(i,n){
			 rep(j,n) visited[j+1]=-1;
			 ans=min(ans,dfs(graph,i+1));
			// dump(i+1) dump(ans)
		}
		cout << "Case #" << loop+1 << ": " ;
		cout << ans << endl;
	}
	return 0;
}