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

const int N = 1010;
int n, l;

int head[N];
int who[N+N], next[N+N], d[N];
int e;

bool flag = false;

int cnt(int node, int father) 
{
    int e = head[node], c = 0, t;
    while(e != 0){
        t = who[e];
        if (t != father) c += cnt(t, node);
        e = next[e];
    }
    return c + 1;
}

int dfs(int node, int delta, int father, int& sum) {
    //if (flag) cout<<node<<':'<<d[node]+delta<<' '<<father<<endl;
    if (d[node] + delta == 0) {sum=1;return 0;}
    if (d[node] + delta == 1) {sum=cnt(node, father); return sum-1;}
    int e = head[node];
    int min1 = INF, min2 = INF, t;
    sum = 0;
    while(e != 0){
        t = who[e];
        if (t != father) {
            int ct, st;
            ct = dfs(t, -1, node, st);
            //cout<<t<<":: "<<ct<<' '<<st<<endl;
            if (ct - st < min1) {
                min2 = min1;
                min1 = ct - st;   
            }
            else if (ct - st < min2) {
                min2 = ct - st;
            }
            sum += st;
        }
        e = next[e];
    }
    //if (flag) cout<<"min   "<<min1<<' '<<min2<<endl;
    ++sum;
    return sum - 1 + min1 + min2;
}

void ins(int s, int t){
    ++e;
    who[e] = t;
    next[e] = head[s];
    head[s] = e;
    ++e;
    who[e] = s;
    next[e] = head[t];
    head[t] = e;
}

int main() {
    //freopen("input.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int cas;
    scanf("%d", &cas);
    REP(T, cas) {
        cin>>n;
        CLR(who);
        CLR(head);
        CLR(d);
        e = 0;
        int s, t, ans = INF, sum = 0;
        REP(i, n-1) {
            cin>>s>>t;
            --s, --t;
            ins(s,t);
            ++d[s];
            ++d[t];
        }
        REP(i, n) {
            //if (i == 3) flag = true;
            //else flag= false;
            int tmp = dfs(i, 0 , -1, sum);
            //cout<<i<<' '<<tmp<<endl;
            ans = min(tmp, ans);
        }        
        printf("Case #%d: %d\n", T+1, ans);
    }
    //for(;;);
    return 0;
}
