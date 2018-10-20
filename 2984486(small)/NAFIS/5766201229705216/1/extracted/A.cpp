/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

vector < int > vc[1001];
//pair < int, int > dfs(int c, int p){
//    int sum = 0, sum2 = 0, ms = 0;
//    vector < int > vt;
//    for(int i = 0; i < vc[c].size(); i++){
//        if(vc[c][i] == p) continue;
//        pair < int, int > t = dfs(vc[c][i], c);
//        sum += t.xx;
//        sum2 += t.yy;
//        ms += min(t.xx, t.yy);
//        vt.pb(t.xx - t.yy);
//    }
//    if(vt.size() <= 1) return mp(sum2, 1 + ms);
//    if(vt.size() == 2){
//        return mp(min(sum2, sum), 1 + ms);
//    }
//    pair < int, int > ret;
//    vsort(vt);
//    ret.xx = min(sum2, vt[0] + vt[1] + sum2 - 2);
//    ret.yy = 1 + ms;
//    return ret;
//
//}

int ar[1001];
int dfs(int c, int p){
    int ret = 0;
    ar[c] = 1;
    vector < int > vt;
    for(int i = 0; i < vc[c].size(); i++){
        if(vc[c][i] == p) continue;
        int t = dfs(vc[c][i], c);
        ret += t;
        ar[c] += ar[ vc[c][i] ];
        vt.pb(t - ar[vc[c][i]]);
    }
    if(vt.size() <= 1) return ar[c] - 1;
    if(vt.size() == 2){
        return min(ar[c] - 1, ret);
    }
    vsort(vt);
    ret = vt[0] + vt[1] + ar[c] - 1;
    return min(ret, ar[c] - 1);
}
main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
//    freopen("a1.out", "w", stdout);
//    freopen("b.in", "r", stdin);
//    freopen("b1.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(ts, 1, a + 1){
        cout << "Case #" << ts << ": ";
        cerr << "Case #" << ts << ": ";
        cin >> b;
        FOR(i, 1, 1001) vc[i].clear();
        REP(i, b - 1){
            cin >> c >> d;
            vc[c].pb(d);
            vc[d].pb(c);
        }
        e = 20000;
        for(int i = 1; i <= b; i++){
//            pair < int, int > p = dfs(i, 0);
//            e = min(e, (LL)min(p.xx, p.yy));
            set0(ar);
            e = min(e, (LL)dfs(i, 0));
        }
        cout << e << endl;
        cerr << e << endl;
    }
}

