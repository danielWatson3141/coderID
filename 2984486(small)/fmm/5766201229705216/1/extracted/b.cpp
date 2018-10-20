#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <complex>
#include <limits>
#include <functional>
#include <numeric>

#define rep(x,n) for(int x = 0; x < n; ++x)
#define print(x) cout << x << endl
#define dbg(x) cerr << #x << " == " << x << endl
#define _ << " , " <<
#define mp make_pair
#define x first
#define y second

using namespace std;

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1000+47;
vector<int> adj[maxn];
int n;

void read() {
  cin>>n;
  for(int i=1;i<=n;i++) adj[i].clear();
  rep(i,n-1) {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

int f[maxn][maxn];

int go(int at, int dad) {
  int &res = f[at][dad];
  if(res >= 0) return res;
  int a=-1,b=-1;
  for(int to : adj[at]) if(to != dad) {
    int c = go(to, at);
    if(c>=a) { b=a; a=c; }
    else if(c>b) { b=c; }
  }
  if(a>0 and b>0) res = 1+a+b;
  else res=1;
  return res;
}

void process(int testcase) {
  int ans = 0;
  memset(f,-1,sizeof f);
  for(int i=1;i<=n;i++) {
    ans=max(ans,go(i,i));
  }
  printf("Case #%d: %d\n",testcase,n-ans);
}

int main() {
  int T;
  cin >> T;
  for(int testcase=1;testcase<=T;testcase++) {
    read();
    process(testcase);
  }
  return 0;
}

