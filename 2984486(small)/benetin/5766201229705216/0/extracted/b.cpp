#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

int N;
int r[1001][1001];
int cnt[1001];
int ret;

int play(int a, int p) {
  int kids=cnt[a];
  if(p>=0) kids--;
  if(kids<2) return 1;
  int m1=0, m2=0;
  REP(i, cnt[a]) {
    if (r[a][i]==p) continue;
    int tt=play(r[a][i], a);
    // cout<<a+1<<" "<<r[a][i]+1<<" "<<tt<<endl;
    if(tt>=m1) {
      m2=m1; m1=tt;
    } else if(tt>=m2) {
      m2=tt;
    }
  }
  return 1+m1+m2;
}

int main() {
  int Ts;
  cin>>Ts;
  FOR(cs, 1, Ts) {
    cin>>N;
    memset(cnt, 0, sizeof(cnt));
    REP(i, N-1) {
      int x, y;
      cin>>x>>y;
      x--; y--;
      r[x][cnt[x]] = y;
      cnt[x]++;
      r[y][cnt[y]] = x;
      cnt[y]++;
    }
    ret=0;
    REP(i, N) {
      int t=play(i, -1);
      // cout<<i+1<<" ** "<<t<<endl;
      if (t>ret) ret=t;
    }
    cout << "Case #" << cs << ": " << N-ret << endl;
  }
  return 0;
}
