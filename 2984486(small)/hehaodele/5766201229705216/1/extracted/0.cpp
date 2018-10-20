#include "cstdio"
#include "iostream"
#include "vector"
#include "algorithm"
#include "cstring"
#include "set"
#include "map"
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define rep(i, n) for(int i=0; i<n; i++)
#define repp(i, a, b) for(int i=a; i<a+b; i++)
using namespace std;
inline int getint(){
  char c = getchar();
  for(;c<'0'||c>'9';) c = getchar();
  int x = 0;
  for(;c>='0' && c<='9'; c = getchar()) x*=10, x+=c-'0';
  return x;
}
const int maxn = 1010;
int n,m,k,x,y;
int s[maxn], w[maxn];
std::vector<int> e[maxn];
void dfs(int u, int F){
	s[u] = 1;
	vector<int> a;
	a.clear();
	rep(i, e[u].size()) if(e[u][i]!=F){
		int v = e[u][i];
		dfs(e[u][i], u);
		s[u] += s[v];
		a.push_back(w[v] - s[v]);
	}
	sort(a.begin(), a.end());
	w[u] = s[u] - 1;
	if(a.size()>1) w[u] = s[u] - 1 + a[0] + a[1];
	//printf("%d %d %d\n", u, s[u], w[u]);
}

int main(int argc, char const *argv[])
{
	int cass = getint();
	repp(cas,1,cass){
		n = getint();
		repp(i,1,n) e[i].clear();
		rep(i,n-1){
			x = getint(), y = getint();
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int ans = n;
		repp(i,1,n){

			dfs(i,0);
			ans = min(ans, w[i]);
			//printf("=========\n");
		}
		printf("Case #%d: %d\n",cas,ans);
	cerr<<cas<<endl;
		
	}
	return 0;
}