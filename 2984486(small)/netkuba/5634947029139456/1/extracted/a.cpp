#include<algorithm>
#include<bitset>
#include<cassert>
#include<complex>
#include<cstring>
#include<cstdio>
#include<iomanip>
#include<unordered_map>
#include<iostream>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<vector>

#define FOR(i,a,b) for(int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for(int i=(a); i>=(b); --i)
#define REP(i,n) for(int i=0; i<(n); ++i)
#define VAR(v,i) __typeof(i) v = (i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define debug(x) { cerr << #x <<" = " << (x) << endl; }
#define debugv(x) { cerr << #x << " = "; FORE(it, x) cerr << *it << ", "; cerr << endl;  }
#define dprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef pair<int, int> PII;;
typedef vector<int> VI;
typedef long long LL;
typedef long double LD;
template<class C> void mini(C&a4, C b4) { a4 = min(a4,b4); }
template<class C> void maxi(C&a4, C b4) { a4 = max(a4,b4); }

template<class T1, class T2> ostream& operator<<(ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", "<< pair.Y << ")"; };

typedef bitset<41> T;

int n, l;

T read() {
    T result;
    char c;
    REP(j, l) {
        scanf(" %c", &c);
        if (c == '1') {
            result[j] = 1;
        }
    }
    return result;
}

void doit() {
    scanf("%d %d", &n, &l);
    vector<T> devs;
    vector<T> outs;
    set<T> curr;

    REP(i, n) {
        devs.PB(read());
    }
    REP(i, n) {
        outs.PB(read());
    }

    int best = 64;

    REP(i, n) {
        unordered_map<T, int> mmap;

        T diff = devs[0] ^ outs[i];
        REP(j, n) mmap[outs[j]]++;
        REP(j, n) mmap[devs[j] ^ diff]--;
        
        bool ok = true;
        FORE(it, mmap) {
            if (it->second != 0) ok = false;
        }

        if (ok) {
            mini(best, (int)diff.count()); 
        }
    }

    if (best == 64) {
        printf("NOT POSSIBLE\n");
    } else {
        printf("%d\n", best);
    }
}

int main() {
    ios_base::sync_with_stdio();
    cout << fixed << setprecision(10);
    
    int ttt; scanf("%d", &ttt);
    REP(tttt, ttt) {
        printf("Case #%d: ", tttt+1);
        doit();
    }
    
    return 0;
}
