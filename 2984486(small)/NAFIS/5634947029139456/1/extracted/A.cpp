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

string s1[200], s2[200], s3[200];
LL ar[200][200], dis[200][200];
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
        cin >> b >> c;
        REP(i, b) cin >> s1[i];
        REP(i, b) cin >> s2[i];
        vector < LL > vc;
        map < LL, int > m, m1;
        set0(dis);
        set0(ar);
        REP(i, b){
            REP(j, b){
                REP(k, c){
                    if(s1[i][k] != s2[j][k]){
                        dis[i][j]++;
                        ar[i][j] |= 1ll<<k;
                    }
                }
                if(m[ar[i][j]] == 0){
                    vc.pb(ar[i][j]);
                    m[ar[i][j]] = 1;
                    m1[ar[i][j]] = dis[i][j];
                }
            }
        }
        e = 500;
        sort(s2, s2 + b);
        REP(i, vc.size()){
            REP(j, b){
                s3[j] = s1[j];
                REP(k, c){
                    if(vc[i] & 1ll<<k){
                        if(s3[j][k] == '1') s3[j][k] = '0';
                        else s3[j][k] = '1';
                    }
                }
            }
            sort(s3, s3 + b);
            d = 0;
            REP(j, b) if(s2[j] != s3[j]) d = 1;
            if(d == 0) e = min((int)e, m1[vc[i]]);
        }
        if(e <= c) cout << e << endl;
        else cout << "NOT POSSIBLE" << endl;
        if(e <= c) cerr << e << endl;
        else cerr << "NOT POSSIBLE" << endl;
    }
}

