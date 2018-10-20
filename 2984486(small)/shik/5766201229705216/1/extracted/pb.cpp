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

#define N 1010
int n;
VI e[N];
void input() {
    RI(n);
    REP1(i,1,n) e[i].clear();
    REP(i,n-1) {
        int a,b;
        RI(a,b);
        e[a].PB(b);
        e[b].PB(a);
    }
}

int sz[N];
int go( int p, int f ) {
    sz[p]=1;
    VI v;
    FOR(it,e[p]) if ( *it!=f ) {
        int now=go(*it,p);
        v.PB(now-sz[*it]);
        sz[p]+=sz[*it];
    }
    sort(ALL(v));
    if ( SZ(v)==0 ) return 0;
    else if ( SZ(v)==1 ) return sz[p]-1;
    else return sz[p]-1+v[0]+v[1];
}

void solve() {
    int ans=N;
    REP1(i,1,n) ans=min(ans,go(i,0));
    printf("%d\n",ans);
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

