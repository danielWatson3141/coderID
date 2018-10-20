#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i,a,b) for(int i(a); i <= b; ++i)
#define FORD(i,a,b) for(int i(a); i >= b; --i)
#define REP0(i,n) FOR(i,0,n-1)
#define REP1(i,n) FOR(i,1,n)
#define PU push_back
#define PO pop_back
#define MP make_pair
#define A first
#define B second
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define SZ(s) (int)((s).size())
#define CL(a) memset((a),0,sizeof(a))
#define MAX(X,Y) X = max((X),(Y))
#define MIN(X,Y) X = min((X),(Y))
#define FORIT(X,Y) for(typeof((Y).begin()) X=(Y).begin(); X!=(Y).end(); ++X)
#define VI vector <int>
#define ll long long
#define PII pair<int,int>
#define PDD pair<double,double>
#define INF 1000000000

using namespace std;
int T;
int del[1001][1001];
int ch[1001][1001];
int check(int x, int y, vector<int> l[],
          map<int,map<int,int> > &m) {
  if (m[x][y])
    return del[x][y];
  int A = 0;
  int B = 0;
  int C = 0;
  int i = 0;
  FORIT(it, l[y]) {
    if (*it == x)
        continue;
    i++;
    check(y,*it,l,m);
    int n = ch[y][*it]-del[y][*it];
    if (n > A) {
        B = A;
        A = n;
    } else if (n > B) {
        B = n;
    }
    C += ch[y][*it];
  }
  m[x][y] = true;
  ch[x][y] = C+i;
  if (i==0)
    del[x][y] = 0;
  else if (i == 1)
    del[x][y] = C+1;
  else if (i == 2)
    del[x][y] = C-A-B;
  else
    del[x][y] = C+i-2-A-B;
  return del[x][y];

}
void solve() {
  T++;
  printf("Case #%d: ", T);
  int N;
  vector<int> l[1001];
  map<int,map<int,int> > m;
  cin >> N;
  int x, y;
  REP0(i,N-1) {
    cin >> x >> y;
    l[x].PU(y);
    l[y].PU(x);
  }
  int A = N;
  REP1(i, N) {
    int n = check(0, i, l, m);
    if (n < A)
      A = n;
  }
  printf("%d\n", A);
}

int main() {
//  freopen("B.in", "r", stdin);
  int T;
  cin >> T;
  while (T-->0) solve();
  return 0;
}
