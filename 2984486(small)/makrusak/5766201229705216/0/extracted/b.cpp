#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define ALL(x) x.begin(), x.end()
#define F first
#define S second
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,-1,sizeof(x))
#define pw(x) (1ull<<(x))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

vector<int> g[1010];
int te, n;

int ma(int st, int from) {
  vector<int> ch;
  for (int i=0;i<g[st].size();i++) {
    if (g[st][i] == from) continue;
    ch.pb(ma(g[st][i], st));
  }
  sort(ch.rbegin(), ch.rend());
  if (ch.size()<=1) return 1;
  return 1+ch[0]+ch[1];
}

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> te;
  for (int tee=0;tee<te;tee++) {
    cout << "Case #" << tee+1 << ": ";
    int ans = INF;
    cin >> n;
    for (int i=0;i<n;i++) g[i].clear();
    for (int i=0;i<n-1;i++) {
      int a,b;
      cin >> a >> b; a--, b--;
      g[a].pb(b);
      g[b].pb(a);
    }
    for (int st=0;st<n;st++) {
      ans = min(ans, n-ma(st, -1));
    }
    cout << ans << "\n";
  }
  return 0;
}
