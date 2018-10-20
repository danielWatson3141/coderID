#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

const int INF = 0X3F3F3F3F;
const double PI = acos(-1.0); //3.1415926535897932384626433832795;
const double EPS = 1e-11;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1}; //4 direction

#define FOR(i,s,e) for(int i=(s);i<=(int)(e);++i)
#define FORD(i,s,e) for(int i=(s);i>=(int)(e);--i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REPD(i,n) for(int i=(n)-1;i>=0;--i)
#define CLR(x) memset((x),0,sizeof(x));
#define MEM(a,b) memset((a),b,sizeof(a));
#define PRV(v) REP(vi,v.size()) cout << v[vi] << ' ';cout << endl

inline int sgn(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }
//inline string tolower(string s){ REP(i,s.SZ) s[i] = tolower(s[i]); return s; }
//inline string toupper(string s){ REP(i,s.SZ) s[i] = toupper(s[i]); return s; }

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

const int MAXN = 200;
int f[50], n, l, ans2;

int cnt[2][50];

string a[160], b[160];
bool na;

void dfs(int d, int step) {
    if (d == l) {
        sort(b, b + n);
        //REP(i,n) cout<<b[i]<<' ';cout<<endl;
        //REP(i,n) cout<<a[i]<<' ';cout<<endl;
        REP(i, n) {            
            if (a[i] == b[i]) continue;
            else return;
        }
        if (ans2 == -1) ans2 = step;
        else ans2 = min(ans2, step);
        return;
    }
    if (f[d] != 3) return dfs(d+1, step);
    dfs(d+1, step);
    REP(i, n) b[i][d] = 1 - (b[i][d]-'0') + '0';
    dfs(d+1, step+1);
    REP(i, n) b[i][d] = 1 - (b[i][d]-'0') + '0';
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int cas;
    scanf("%d", &cas);
    REP(T, cas) {
        memset(cnt, 0, sizeof(cnt));
        cin>>n>>l;
        REP(i, n) {
            cin>>a[i];
            REP(j, l) 
                if (a[i][j]=='0') 
                    ++cnt[0][j];              
        }
        REP(i, n) {
            cin>>b[i];
            REP(j, l) 
                if (b[i][j]=='0') 
                    ++cnt[1][j];                    
        }
        sort(a, a + n);
        CLR(f);
        na = false;
        int ans = 0;
        REP(i, l) {
            if (cnt[0][i] == cnt[1][i]) f[i] += 1;
            if (cnt[0][i] == n - cnt[1][i]) f[i] += 2;
            //cout<<i<<' '<<f[i]<<endl;
            if (f[i] == 0) {
                na = true;
                break;   
            }        
            if (f[i] == 2) {
                ++ans;
                REP(j, n) b[j][i] = 1 - (b[j][i]-'0') + '0';
            }
        }        
        if (na) {
            printf("Case #%d: NOT POSSIBLE\n", T+1);
            continue;
        }
        //cout<<"check"<<endl;
        ans2 = -1;
        dfs(0, 0);
        if (ans2 == -1) {
            printf("Case #%d: NOT POSSIBLE\n", T+1);
            continue;
        }
        printf("Case #%d: %d\n", T+1, ans + ans2);
    }
    //for(;;);
    return 0;
}
