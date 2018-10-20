
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <assert.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define repf(i,a,b) for (int i=(a); i<=(b); i++)
#define repb(i,a,b) for(int i=(a); i>=(b); i--)

#define ABS(X) ( ((X)>0) ? (X) : -(X) )
#define pb push_back
//print vector
#define pvec(v) pColl(v.begin(),v.end())

typedef long long int LL;

using namespace std;

//Print Collection
template <typename FIter>
void pColl(FIter beg, FIter end) {
    cout << "(";
    for (FIter x = beg; x != end; ++x) {
        if (x!=beg) cout << ", ";
        cout << *x;
    }
    cout << ")" << endl;
}

vector<string> outl, dev;
int N,L;

int countOnes(vector<string> vs, int pos) {
    int ans = 0;
    for (string &s : vs) {
        if (s[pos]=='1') ans++;
    }
    return ans;
}

void pmat(vector<vector<bool>> &v) {
    rep(i,v.size()) {
        rep(j,v[i].size()) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool veq(vector<string> &v1, vector<string> &v2) {
    rep(i,v1.size()) if(v1[i]!=v2[i]) return false;
    return true;
}

int solve() {
    int best=100;
    for (int i=0; i<(1<<L); i++) {
        vector<string> t1 = outl;
        vector<string> t2 = dev;
        int nbits=0;
        for (int j=0; j<L; j++) {
            if (i & (1<<j)) {
                rep(k,N) t2[k][j] = (t2[k][j]=='1') ? '0' : '1';
                nbits++;
            }
        }
        sort(t1.begin(),t1.end()); sort(t2.begin(),t2.end());
        if (veq(t1,t2)) best = min(best,nbits);
    }
    if (best==100) return -1;
    return best;
}

int main(int argc, char **argv) {
    int T;
    cin >> T;
    repf(tc,1,T) {        
        cin >> N >> L;
        outl.resize(N); dev.resize(N);
        rep(i,N) cin >> outl[i];
        rep(i,N) cin >> dev[i];
        //pvec(outl); pvec(dev);
        int ans = solve();
        cout << "Case #" << tc << ": ";
        if (ans == -1)
            cout << "NOT POSSIBLE\n";
        else
            cout << ans << endl;
        outl.clear(); dev.clear();
    }
}

