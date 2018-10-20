#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) (int((a).size()))
#define all(a) (a).begin(), (a).end()

#define For(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

typedef complex<int> cI;
typedef complex<double> cD;

typedef pair<int,int> pI;
typedef pair<ll, ll> pL;


int vis[1010];
int total[1010];
int full[1010];
vector< int > E[1010];
void dfs(int u){
  vis[u] = 1;
  vector< int > arr;

  int chd = 0;
  total[u] = 1;
  for(int i=0;i<sz(E[u]);i++){
    int v = E[u][i];
    if(!vis[v]){
      chd++;
      dfs(v);
      total[u] += total[v];
      arr.pb(full[v] - total[v]);
    }
  }
  sort(all(arr));
  if(chd<=1){
    full[u] = total[u] - 1;
  }else{
    full[u] = total[u] + arr[0] + arr[1] - 1;
  }
  //printf("u %d: total %d full %d:", u, total[u], full[u]);
  //for(int i=0;i<sz(arr);i++)printf("%d ", arr[i]);
  //puts("");
}
int main()
{
  int T;
  int n;
  int ans;
  int i;
  int a,b;
  cin >> T;
  for(int z=1;z<=T;z++){
    cin >> n;
    ans = n-1;
    for(i=1;i<=n;i++) E[i].clear();
    for(i=0;i<n-1;i++){
      cin >> a >> b;
      E[a].pb(b);
      E[b].pb(a);
    }
    for(i=1;i<=n;i++){
      //printf("======== %d ========\n", i);
      memset(vis, 0, sizeof(vis));
      dfs(i);
      ans = min(ans, full[i]);
    }
    printf("Case #%d: %d\n", z, ans);
  }
  return 0;
}
