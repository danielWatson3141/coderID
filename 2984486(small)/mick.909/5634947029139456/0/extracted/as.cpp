#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <memory>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>

using namespace std;

#define rep(i,b,e) for(int i=b;i<e;++i)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

static const ll Zp = 1000000009;
static const double EPS = 1e-9;

int T;
int N,L;
vector<int> os;
vector<int> ds;

vector<int> flip(int fm)
{
    vector<int> r = os;
    rep(i,0,N) {
        r[i] = r[i] ^ fm;
    }

    sort(all(r));
    return r;
}

int solve(){
    int min=9999;
    sort(os.begin(), os.end());

    if (ds == os) return 0;

    int I = (1<<L);

    rep(i,0,I) {
        vector<int> f = flip(i);

        if (ds == f) {
            int c = 0;
            rep(j,0,L) {
                if (i & (1<<j)) ++c;
            }
            if (c < min) min = c;
        }
    }
    if (min == 9999) return -1;
    return min;
}

int main(int argc, char *argv[]) {
    cin>>T;
    for(int t=1;t<=T;++t) {
        os.clear();
        ds.clear();

        cin >> N >> L;

        rep(i,0,N) {
            string s;
            cin >> s;
            int v = 0;
            rep(j,0,L) {
                v = (v*2) + ((s[j]=='1') ? 1 : 0);
            }
            os.push_back(v);
        }
        rep(i,0,N) {
            string s;
            cin >> s;
            int v = 0;
            rep(j,0,L) {
                v = (v*2) + ((s[j]=='1') ? 1 : 0);
            }
            ds.push_back(v);
        }
        sort(ds.begin(), ds.end());

        int ans = solve();
        if (ans >= 0) {
            cout<<"Case #"<<t<<": "<<solve()<<endl;
        } else {
            cout<<"Case #"<<t<<": NOT POSSIBLE"<<endl;
        }
    }
	return 0;
}
