#include <map>
#include <iterator>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
  
using namespace std;
 
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 1200001
#define INF 0x3f3f3f3f
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair
typedef long long int64;
typedef unsigned long long uint64;
 
struct tri{
    int u, v, a;
    tri ( int u = 0, int v = 0, int a = 0) : u(u), v(v), a(a) { }
    bool operator < (const tri &w) const{
        if( u != w.u ) return u < w.u;
        if( v != w.v ) return v < w.v;
        return a < w.a;
    }
};
  
const  double pi = acos(-1.0);
const  double EPS = 1e-15;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
  
int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }
  
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}
 
inline void writeInt(int64 n){
    register int idx = 25;
    if( n < 0LL ) putchar_unlocked('-');
    n = abs(n);
    char out[26];
    out[25] = ' ';
    do{
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    }while(n);
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

vector < int > p;

int main(){
    ios::sync_with_stdio(false);
    int t, n, m, c= 1, de, para;
    cin >> t;
    string ans[] = {"BAD","GOOD"};
    srand(time(NULL));
    while( t-- ){
        cin >> n;
        REP(i,n){
            cin >> m;
            p.pb(m);
        }
        cout << "Case #" << c++ << ": " << ans[((rand()%2) + rand())%2] << "\n";
        p.clear();   
    }
    return 0;
}  