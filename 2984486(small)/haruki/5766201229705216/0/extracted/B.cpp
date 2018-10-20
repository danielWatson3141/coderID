
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using lli = long long int ;
template <class T> T get() { T x ; cin >> x ; return x ; }
template <class T> lli size(T const& c) { return c.size() ; }
#define rep0(i,n) for (lli i = 0; i < lli(n); ++i)
#define rep1(i,n) for (lli i = 1; i <= lli(n); ++i)
#define rep(i,n) rep0(i,n)
#define fromto(i,a,b) for (lli i = a; i <= lli(b); ++i)
#define show(x) #x " = " << x
#define all(c) (c).begin(), (c).end()
#define print(e) cout << e << endl ;

template <class T> void setmin(T& x, T y) { x = min(x, y); }
template <class T> void setmax(T& x, T y) { x = max(x, y); }

int T,N,X,Y;

pair<int, int> dfs(int i, vector<vector<int> > const& G,
    vector<int>& visited) {
    visited[i] = 1;
    vector<pair<int, int> > ps;
    for (int v : G[i]) {
        if (visited[v]) continue;
        ps.push_back(dfs(v, G, visited));
    }
    int n = ps.size();
    if (n == 0) {
        return { 0, 1 };
    } else if (n == 1) {
        return { ps[0].second, ps[0].second + 1 };
    } else if (n == 2) {
        return { ps[0].first + ps[1].first,
                ps[0].second + ps[1].second + 1 };
    } else {
        int num = 0;
        priority_queue<int> pq;
        for (auto p : ps) {
            num += p.second;
            pq.push(p.second - p.first);
        }
        int top[2];
        top[0] = pq.top(); pq.pop(); top[1] = pq.top();
        return { num - top[0] - top[1], num + 1 };
    }    
}


int main() {
    cin >> T;
    rep (t,T) {
        cout << "Case #" << t+1 << ": ";
        cin >> N;
        vector<vector<int> > G;
        rep (i,N) G.push_back({});
        rep (i,N-1) {
            cin >> X >> Y; X--, Y--;
            G[X].push_back(Y);
            G[Y].push_back(X);
        }
        int m = N;
        rep (i,N) {
            vector<int> visited; rep (i,N) visited.push_back(0);
            setmin(m, dfs(i, G, visited).first);
        }
        cout << m << endl;
    }
}
