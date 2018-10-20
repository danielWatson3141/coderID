// by shik {{{
#include <bits/stdc++.h>
#include <unistd.h>
#define SZ(x) ((int)(x).size())
#define ALL(c) begin(c),end(c)
#define REP(i,n) for ( int i=0; i<(int)(n); i++ )
#define REP1(i,a,b) for ( int i=(int)(a); i<=(int)(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define MP make_pair
#define PB push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}

void WI( int x ) {
    printf("%d\n",x);
}

template<typename... Args>
void WI(int head, Args... tail) {
    printf("%d ",head);
    WI(tail...);
}
/// }}}

inline int bit( long x, int i ) { return (x>>i)&1; }
inline long two( int x ) { return 1L<<x; }

#define N 200
#define L 50

int n,l;
long x[N],y[N];

long read() {
    char s[L];
    scanf("%s",s);
    long x=0;
    REP(i,l) if ( s[i]=='1' ) x|=two(i);
    return x;
}

void input() {
    RI(n,l);
    REP(i,n) x[i]=read();
    REP(i,n) y[i]=read();
}

bool check( long z ) {
    vector<long> xx;
    REP(i,n) xx.PB(x[i]^z);
    sort(ALL(xx));
    return xx==vector<long>(y,y+n);
}

void solve() {
    sort(y,y+n);
    int ans=L;
    REP(i,n) REP(j,n) {
        long z=x[i]^y[j];
        int cnt=__builtin_popcount(z);
        if ( cnt<ans && check(z) ) ans=cnt;
    }
    if ( ans==L ) puts("NOT POSSIBLE");
    else printf("%d\n",ans);
}

int main( int argc, char *argv[] ) {
    int n_case;
    RI(n_case);
    //fprintf(stderr,"n_case = %d\n",n_case);
    REP1(i,1,n_case) {
        input();
        if ( argc==2 && atoi(argv[1])!=i ) continue;
        if ( argc==3 && (atoi(argv[1])<i || atoi(argv[2])>i) ) continue;
        if ( argc!=1 ) {
            fprintf(stderr,"Running #%d...\n",i);
            fflush(stderr);
        }
        printf("Case #%d: ",i);
        solve();
        fflush(stdout);
    }
    return 0;
}
