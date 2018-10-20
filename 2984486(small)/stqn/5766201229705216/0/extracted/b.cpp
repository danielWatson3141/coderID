#include <bits/stdc++.h>

using namespace std;

#define long int64_t

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=a;i<(b);++i)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define eb emplace_back

const int N = 1024;

int n;
vector<vector<int> > G;

void input()
{
    cin >> n;
    G.assign(n, vector<int>());
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y, --x, --y;
        G[x].pb(y);
        G[y].pb(x);
    }
}

int ved[N];

int recur(int v)
{
    ved[v] = true;

    vector<int> a;
    rep(i, int(G[v].size())) {
        if (!ved[G[v][i]]) {
            a.pb(recur(G[v][i]));
        }
    }
    sort(all(a), greater<int>());

    if (a.size() <= 1) return 1;
    return a[0] + a[1] + 1;
}

int solve()
{
    int ans = 1;
    rep(i, n) {
        memset(ved, 0, sizeof(ved));

        ans = max(ans, recur(i));
    }
    return n - ans;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    rep(i, T) {
        input();
        cout << "Case #"
             << i + 1
             << ": "
             << solve()
             << endl;
    }

    return 0;
}
