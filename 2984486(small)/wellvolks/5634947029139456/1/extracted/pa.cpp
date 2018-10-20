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
#include <tr1/unordered_map>
  
using namespace std;
using namespace tr1;
 
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 1200001
#define INF 0x3f3f3f
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

vector < string > v1, v2;
int opa[10000], vis = 1;

int solve( int x, int y ){
	vector < string > a1, a2;
	a1 = v1;
	a2 = v2;
	int ans = 0;
	REP(j,v1[x].size()){
		if( v1[x][j] != v2[y][j] ){
			ans++;
			REP(i,v1.size()){
				if( a1[i][j] == '1' ) a1[i][j] = '0';
				else a1[i][j] = '1'; 
			}
		}
	}
	sort(ALL(a1));
	if( a1 == v2 ) return ans;
	return INF;
}

int main(){
    ios::sync_with_stdio(false);
    int t, n, m, c= 1;
    cin >> t;
    string str;
    while( t-- ){
 		cin >> n >> m;       
    	REP(i,n){
    		cin >> str;
    		v1.pb(str);
    	}
    	REP(i,n){
    		cin >> str;
    		v2.pb(str);
    	}
    	int ans = INF;
    	sort(ALL(v1));
    	sort(ALL(v2));
    	if( v1 == v2 ) cout << "Case #" << c++ << ": 0\n";
    	else{
	    	REP(i,n){
	    		REP(j,n){
	    			if( v1[i] == v2[j] ) continue;
	    			ans = min(ans,solve(i,j));
	    		}
	    	}
	    	if( ans < INF ) cout << "Case #" << c++ << ": " << ans << "\n";
	    	else cout << "Case #" << c++ << ": NOT POSSIBLE\n";
    	}
    	v1.clear();
    	v2.clear();
    }
    return 0;
}    