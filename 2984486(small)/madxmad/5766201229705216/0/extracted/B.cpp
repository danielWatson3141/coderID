#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

const int MAXN = 1005;
int child[MAXN];
int cnt[MAXN][MAXN];
int dp[MAXN][MAXN];
int G[MAXN][MAXN];

int mycount(int n){
  rep(i,1,n+1){
    queue<pii> Q;
    Q.push(mp(i,1));

    vi mark(n+1,0);
    mark[i] = 1;

    while(!Q.empty()){
      int cur = Q.front().first;
      int c = Q.front().second;
      Q.pop();

      rep(j,1,n+1) if(mark[j] == 0){
        cnt[j][cur] = c;
        mark[j] = 1;
        Q.push(mp(j,c+1));
      }
    }
  }
}

int f(int n, int node, int parent){
  int ch = child[node];
  if(parent) ch--;

  if(ch <= 1) return 1;
  if(dp[node][parent]) return dp[node][parent];

  //D(node); D(parent);

  int a = 0, b = 0;
  rep(c,1,n+1) if(c != parent and G[node][c]){
    int t = f(n,c,node);
    a = max(a,t);
    if(a > b) swap(a,b);
  }

  //cout << node << ": " << a << ", " << b << endl;

  dp[node][parent] = a + b + 1;
  return dp[node][parent];
}



int main(){ IO;
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);

  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";
    
    memset(child, 0, sizeof child);
    memset(cnt, 0, sizeof cnt);
    memset(dp, 0, sizeof dp);
    memset(G, 0, sizeof G);
    
    int n;
    cin >> n;

    REP(i,n-1){
      int x, y;
      cin >> x >> y;
      G[x][y] = G[y][x] = 1;
      child[x]++; child[y]++;
    }

    //D("count");
    mycount(n);
    
    // rep(i,1,n+1){
    //   rep(j,1,n+1) cout << G[i][j] << " ";
    //   cout << endl;
    // }

    //D("solve");
    int ans = n - 1;
    rep(i,1,n+1){
      int t = n - f(n,i,0);
      ans = min(ans, t);
      //cout << i << " = " << f(n,i,0) << endl;
    }
    cout << ans << endl;
  }

  return 0;
}
