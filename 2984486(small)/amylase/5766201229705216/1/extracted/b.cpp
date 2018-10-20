#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <complex>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long       li;
typedef vector<li>      vi;
typedef complex<double> pt;
typedef pair<pt, pt>    line;
typedef pair<li, li>    pi;
typedef vector<string>  vs;

#define rep(i,to)       for(li i=0;i<((li)to);++i)
#define foreach(it,set) for(__typeof((set).begin()) it=(set).begin();it!=(set).end();it++)
#define all(v)          v.begin(), v.end()

template <class T> inline void minu(T& x, T y) { x = min(x, y); }
template <class T> inline void maxu(T& x, T y) { x = max(x, y); }

inline li bit(li n){ return 1LL<<n; }
template <class T> ostream& operator<<(ostream& os, vector<T> x){
    foreach(it, x) os << *it << ' ';
    return os;
}

li dx[8] = {1, -1, 0,  0, -1, 1,  1, -1};
li dy[8] = {0,  0, 1, -1, -1, 1, -1,  1};

int n;
vector<vector<int> > g;

struct res {
    int cost, weight;
};

res rec(int pos, int parent) {
    vector<pair<int, int> > gain;
    vector<res> recres;
    foreach(nxt, g[pos]) if (*nxt != parent) {
        res tres = rec(*nxt, pos);
        recres.push_back(tres);
        gain.push_back(make_pair(tres.weight - tres.cost, gain.size()));
    }
    if (recres.size() < 2) {
        // remove all children
        res ans = {0, 1};
        foreach(tres, recres) {
            ans.weight += tres->weight;
            ans.cost += tres->weight;
        }
        return ans;
    } else {
        // choose 2 largest gain.
        sort(all(gain));
        res ans = {0, 1};
        rep(i, gain.size()) {
            int gi = gain.size() - 1 - i;
            ans.weight += recres[gain[gi].second].weight;
            if (i < 2) {
                ans.cost += recres[gain[gi].second].cost;
            } else {
                ans.cost += recres[gain[gi].second].weight;
            }
        }
        return ans;
    }
}

void solve(int caseNum) {
    cin >> n;
    g = vector<vector<int> >(n);
    rep(i, n-1) {
        int fr, to;
        cin >> fr >> to; fr--; to--;
        g[fr].push_back(to);
        g[to].push_back(fr);
    }
    int ans = n;
    rep(i, n) minu(ans, rec(i, -1).cost);
    cout << "Case #" << caseNum << ": " << ans << endl;
    return;
}

int main() {
    int n;
    cin >> n;
    rep(i, n) solve(i + 1);
    return 0;
}
