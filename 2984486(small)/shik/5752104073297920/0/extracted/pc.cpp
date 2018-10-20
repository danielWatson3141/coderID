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

#define N 1000
#define M 100

int randint( int a, int b ) {
    return rand()%(b-a+1)+a;
}

int per[N];
void gen( int n ) {
    REP(i,n) per[i]=i;
    REP(i,n) swap(per[i],per[randint(0,n-1)]);
}

double cnt[N][N];;
void predo() {
    const int T=100000;
    REP(t,T) {
        gen(M);
        REP(i,M) cnt[i][per[i]]++;
    }
    REP(i,M) REP(j,M) cnt[i][j]/=(T/M);
}

int n,p[N];
void input() {
    RI(n);
    REP(i,n) RI(p[i]);
}

void solve() {
    double s=1;
    REP(i,n) {
        int j=i/(n/M);
        int pj=p[i]/(n/M);
        s*=cnt[j][pj];
    }
    puts(s<1?"GOOD":"BAD");
}

int main( int argc, char *argv[] ) {
    predo();
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

