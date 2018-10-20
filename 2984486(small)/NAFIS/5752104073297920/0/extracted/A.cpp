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

int ar[1001], ar1[1001];
int bad(int a){
    REP(i, a) ar1[i] = i;
    REP(i, a){
        int b= rand() % a;
        swap(ar1[i], ar1[b]);
    }
    int c = 0;
    REP(i, a) c += (ar[i] == ar1[i]);
    return c;
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
        REP(i, b) cin >> ar[i];

        c = 0;
        REP(i, 100){
            c = max(c, (LL)bad(a));
        }

        if(c <= 1) cout << "GOOD" << endl;
        else cout << "BAD" << endl;
        if(c <= 1) cerr << "GOOD" << endl;
        else cerr << "BAD" << endl;
    }
}

