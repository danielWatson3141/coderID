#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin();it != (c).end(); it++)

const int INF = 1000000000;

vector<vector<int> > v;

struct Result
{
    int res, total;
};

Result dfs(int x, int parent)
{
    vector<int> profit;
    int T = 0;
    forall(y, v[x])
    if (*y != parent)
    {
        Result r = dfs(*y, x);
        T += r.total;
        profit.push_back(r.total - r.res);
    }
    Result ret;
    if (profit.size() < 2)
        ret.res = T;
    else
    {
        sort(profit.begin(), profit.end());
        ret.res = T - profit[profit.size() - 1] - profit[profit.size() - 2];
    }
    ret.total = T + 1;
    return ret;
}

int main()
{
    int TT; cin >> TT;
    forn(tt,TT)
    {
        int N; cin >> N;
        v = vector<vector<int> >(N);
        forn(i,N-1)
        {
            int x,y; cin >> x >> y;
            x--; y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int res = INF;
        forn(root, N) res = min(res, dfs(root, -1).res);
        cout << "Case #" << tt+1 << ": " << res << endl;
    }
    return 0;
}
