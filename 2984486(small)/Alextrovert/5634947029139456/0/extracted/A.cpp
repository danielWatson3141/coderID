#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

#define Open(I,O)  ({if(I[0])freopen(I,"r",stdin);if(O[0])freopen(O,"w",stdout);})
#define Rep(i,N)   for(int i= 0 , _##i=(N); i<_##i; ++i)  /* 0 to N-1, inclusive */
#define For(i,L,H) for(int i=(L), _##i=(H); i<_##i; ++i)  /* L to H-1, inclusive */
#define Rev(i,N)   for(int i=(N); --i>= 0; )              /* N-1 to 0, inclusive */
#define Dwn(i,L,H) for(int i=(H), _##i=(L); --i>=_##i; )  /* H-1 to L, inclusive */
#define RepI(i,a)  for(typeof((a).begin()) i=(a).begin(), _##i=(a).end(); i!=_##i;++i)
#define DwnI(i,a)  for(typeof((a).rbegin())i=(a).rbegin(),_##i=(a).rend();i!=_##i;++i)
#define Mem(a,b)   memset((a),(b),sizeof(a))
#define Fill(a,b)  fill((a),(a)+sizeof(a)/sizeof((a)[0]),(b))
#define Fill2(a,b) fill(&(a)[0][0],&(a)[0][0]+sizeof(a)/sizeof((a)[0][0]),(b))
#define ToStr(i)   static_cast<ostringstream*>(&(ostringstream()<<(i)))->str()
#define ToInt(s)   ({int i; stringstream SS; SS<<(s); if(!(SS>>i)) i = 0; i;})
#define Min(a,b)   ({typeof(a) _a = (a); typeof(b) _b = (b); _a < _b ? _a : _b;})
#define Max(a,b)   ({typeof(a) _a = (a); typeof(b) _b = (b); _a > _b ? _a : _b;})
#define Defl(a,b)  ({typeof(b) _b = (b); a > _b ? a = _b : a;})
#define Infl(a,b)  ({typeof(b) _b = (b); a < _b ? a = _b : a;})
#define pb         push_back
#define mp         make_pair
#define x          first
#define y          second
#define INF        1000000007
#define Rd(x...) { RD , x; }
#define Ru(x...) { RU , x; } /* only reads whitespace-separated unsigned ints */
#define Pr(x...) { cout << "Debug[ "; DB, x; cout << "]" << endl; }
#define Db(x...) { cout << "Debug[ "; DB, #x, ":", x; cout << "]" << endl; }

#ifndef _WIN32
  #define getchar getchar_unlocked
#endif
template<class T> inline void GetU(T& a) { while ((a = getchar()-'0') < 0);
  for (char c; (c = getchar() - '0') >= 0; ) a = (a << 3) + (a << 1) + c; }

struct Reader { template<class T> Reader& operator ,
  (T& v) { cin >> v; return *this; } } RD;
struct ReaderU { template<class T> ReaderU& operator ,
  (T& v) { GetU(v); return *this; } } RU;
struct Debugger { template<class T> Debugger& operator ,
  (const T& v) { cout << v << " "; return *this; } } DB;
struct classcomp { template<class T> bool operator ()
  (const T& a, const T& b) const { return a > b; } };

typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;

/********************************** END OF TEMPLATE *********************************/

int T, N, L;
bitset<50> b[155], c[155];

void flip(int pos) {
  for (int i = 0; i < N; i++) {
    b[i][pos] = b[i][pos] ^ 1;
  }
}

set<string> S, S2;

int ans;

void rec(int n, int flipped) {
  if (n == L) {
    S.clear();
    for (int i = 0; i < N; i++) S.insert(b[i].to_string());
    if (S == S2) {
      ans = min(ans, flipped);
    }
    return;
  }
  if (flipped > ans) return;
  rec(n+1, flipped);

  flip(n);
  rec(n+1, flipped+1);
  flip(n);
}

int main() {
  freopen("A1.in", "r", stdin);
  freopen("A1.out", "w", stdout);
  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> N >> L;
    string str;
    for (int i = 0; i < N; i++) {
      cin >> b[i];
      //Db(b[i]);
    }
    for (int i = 0; i < N; i++) {
      cin >> c[i];
    }
    S.clear(); S2.clear();
    for (int i = 0; i < N; i++) S.insert(b[i].to_string());
    for (int i = 0; i < N; i++) S2.insert(c[i].to_string());
    cout << "Case #" << Case << ": ";
    if (S == S2) {
      cout << 0 << endl;
    } else {
      ans = INF;
      rec(0, 0);
      if (ans < INF) cout << ans << endl;
      else cout << "NOT POSSIBLE" << endl;
    } 
  }
  
  return 0;
}
