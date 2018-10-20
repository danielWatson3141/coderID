#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0); //3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1}; //4 direction

#define PB push_back
#define MP make_pair
#define SZ size()
#define V vector
#define A first
#define B second
#define FOR(i, s, e) for(int i=(s);i<=(int)(e);++i)
#define FORD(i, s, e) for(int i=(s);i>=(int)(e);--i)
#define REP(i, n) for(int i=0;i<(int)(n);++i)
#define REPD(i, n) for(int i=(n)-1;i>=0;--i)
#define FIT(it,x) for(typeof((x).begin()) it = (x).begin();it != (x).end();it++)
#define FITD(it,x) for(typeof((x).rbegin()) it = (x).rbegin();it != (x).rend();it++)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x), 0, sizeof(x))
#define MEM(a,b) memset((a), b,sizeof(a));
#define EXIST(a,b) (find(all(a),b)!=a.end())
#define DEBUG(x) cerr << #x << ":" << x << '@' << endl
#define PRV(v) REP(vi,v.size()) cout << v[vi] << ' ';cout << endl

inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
inline string tolower(string s){ REP(i,s.SZ) s[i] = tolower(s[i]); return s; }
inline string toupper(string s){ REP(i,s.SZ) s[i] = toupper(s[i]); return s; }
template<class T> inline T sqr(const T& x) { return x * x; }
template<class T> inline int toint(const T& x){ stringstream ss; ss << x; int r; ss >> r; return r; } 
template<class T> inline int todouble(const T& x){ stringstream ss; ss << x; double r; ss >> r; return r; } 
template<class T> inline string tostr(const T& x) { ostringstream os(""); os << x; return os.str(); }
template<class T> void stov(string s,vector<T> &vi){vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));}//NOTES:stov(
template<class T> void vtos(vector<T> vi,string &s){ostringstream sout;for (int i=0;i<vi.size();i++){if(i>0)sout<<' ';sout<<vi[i];}s=sout.str();}

typedef long long LL;
typedef double DB;
typedef stringstream SS;
typedef set< int > SI;
typedef pair< int, int > PII;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< string > VS;
typedef map< string, int > MSI;
typedef map< int, int > MII;

const int MAXN = 155;
const int MAXL = 44;

int n, l;
int cntA[MAXN], cntB[MAXN];
int flip[MAXN];
int A[MAXN][MAXL];
int B[MAXN][MAXL];
int C[MAXN][MAXL];



vector<int> get_v(int a[][MAXL], int n, int l) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; j++) {
            v[i] = (v[i] << 1) + a[i][j];
        }
    }
    sort(v.begin(), v.end());
    return v;
}

map<long long, int> cnt[MAXL];
map<long long, int> tmp[MAXL];

bool check(long long state, int l) {
    tmp[l] = cnt[l];
    for (int i = 0; i < n; i++) {
        long long bit = 0;
        for (int len = 0; len <= l; len++) {
            bit = bit + (B[i][len] << len);//(bit << 1) + B[i][len];
            //cnt[len][bit]++;
        }
        // cout << state << ' ' << bit << ' ' << l << ' ' << (state ^ bit) << endl;
        tmp[l][bit ^ state]--;
        if (tmp[l][bit ^ state] < 0) {
            return false;
        }
    }
    // cout << "haha" << endl;
    return true;
}

int bfs() {
    int ans = INF;
    queue<pair<int, long long> > q;
    if (flip[0] == 1) {
        q.push(make_pair(0, 1LL));
    } else if (flip[0] == 0) {
        q.push(make_pair(0, 0LL));
    } else if (flip[0] == 2) {
        q.push(make_pair(0, 0LL));
        q.push(make_pair(0, 1LL));
    }
    while (!q.empty()) {
        pair<int, long long> pii = q.front();
        q.pop();
        int len = pii.first;
        long long state = pii.second;
        // cout << len << ' ' << state << '#' << flip[len + 1] << endl;
        if (len == l - 1) {
            ans = min(ans, __builtin_popcount(state));
            continue;
        }
        if (flip[len + 1] == 1) {
            if (check(state | (1LL << (len + 1)), len + 1)) {
                q.push(make_pair(len + 1, state | (1LL << (len + 1))));
            }
        } else if (flip[len + 1] == 0) {
            if (check(state, len + 1)) {
                q.push(make_pair(len + 1, state));
            }
        } else if (flip[len + 1] == 2) {
            if (check(state, len + 1)) {
                q.push(make_pair(len + 1, state));
            }

            if (check(state | (1LL << (len + 1)), len + 1)) {
                q.push(make_pair(len + 1, state | (1LL << (len + 1))));
            }
        }
    }
    return ans;
}

int main() {
    int cases;
    scanf("%d", &cases);
    REP(T, cases) {
        scanf("%d %d", &n, &l);
        getchar();
        CLR(cntA), CLR(cntB);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                char c = getchar();
                A[i][j] = c - '0';
                cntA[j] += A[i][j];
            }
            getchar();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < l; j++) {
                char c = getchar();
                B[i][j] = c - '0';
                cntB[j] += B[i][j];
            }
            getchar();
        }

        printf("Case #%d: ", T + 1);
        bool bad = false;
        for (int i = 0; i < l; i++) {
            //flip[i] = cntA[i] != cntB[i];
            if (cntA[i] != cntB[i]) {
                if (cntA[i] != n - cntB[i]) {
                    bad = true;
                    break;
                } else {
                    flip[i] = 1;
                }
            } else {
                if (n % 2 == 0) {
                    if (cntA[i] != n / 2) {
                        flip[i] = 0;
                    } else {
                        flip[i] = 2;
                    }
                } else {
                    flip[i] = 0;
                }
            }
        }
        if (bad) {
            puts("NOT POSSIBLE");
            continue;
        }
        for (int i = 0; i < l; i++) cnt[i].clear();
        for (int i = 0; i < n; i++) {
            long long bit = 0;
            for (int len = 0; len < l; len++) {
                bit = bit + (A[i][len] << len);
                cnt[len][bit]++;
                // cout << "@@" << len << ' ' << bit << endl;
            }
        }
        /*if (n % 2) {
            for (int i = 0; i < l; i++) {
                if ()
            }
        } else {

        }*/



        int ans = bfs();//INF;
        // vector<int> res = get_v(A, n, l);
        // for (int state = 0; state < 1 << l; state++) {
        //     for (int j = 0; j < l; j++) {
        //         if (state & (1 << j)) {
        //             for (int i = 0; i < n; i++) {
        //                 C[i][j] = 1 - B[i][j];
        //             }
        //         } else {
        //             for (int i = 0; i < n; i++) {
        //                 C[i][j] = B[i][j];
        //             }
        //         }
        //     }
        //     vector<int> tmp = get_v(C, n, l);
        //     bool same = true;
        //     for (int i = 0; i < n; i++) {
        //         if (tmp[i] != res[i]) {
        //             same = false;
        //             break;
        //         }
        //     }
        //     if (same) {
        //         ans = min(ans, __builtin_popcount(state));
        //     }
        // }
        if (ans == INF) {
            puts("NOT POSSIBLE");
        } else {
            printf("%d\n", ans);
        }
    }
}