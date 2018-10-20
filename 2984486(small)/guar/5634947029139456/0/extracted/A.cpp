#include <cstdio>
#include <iostream>
#include <string>
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
string S[150];
string F[150];
char CS[40];
char CF[40];
bool count_all(int N, int L) {
  REP0(j, L) {
    CS[j] = 0;
    CF[j] = 0;
    REP0(i, N) {
      if (S[i][j] == '1')
        CS[j]++;
      if (F[i][j] == '1')
        CF[j]++;
    }
    if (CS[j] != CF[j] && CS[j]+CF[j] != N)
      return false;
  }
  return true;
}
void solve() {
  T++;
  printf("Case #%d: ", T);
  int N, L;
  cin >> N >> L;
  REP0(i,N) {
    cin >> S[i];
  }
  REP0(i,N) {
    cin >> F[i];
  }
  if (!count_all(N, L)) {
    printf("NOT POSSIBLE\n");
    return;
  }
  int A = 0;
  REP0(j,L) {
    if (CS[j] != CF[j]) {
        A++;
        REP0(i,N) {
            F[i][j] = F[i][j]=='1'?'0':'1';
        }
        CF[j] = N-CF[j];
    }
  }
  map<string,bool> ss;
  REP0(i,N) {
    ss[S[i]] = true;
  }

  REP0(i,N) {
    if (ss[F[i]] == false) {
        printf("NOT POSSIBLE\n");
        return;
    }
  }
  printf("%d\n", A);
}

int main() {
//  freopen("A.in", "r", stdin);
  int T;
  cin >> T;
  while (T-->0) solve();
  return 0;
}
