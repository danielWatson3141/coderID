#include <iostream>
#define INF 1000000000
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector <int> v[1002];
bool mark[1002];
int child[1002];

int dfs(int curr, int prev)
{
    vector < pair<int,int> > vv;
    child[curr] = 0;
    for ( int i = 0; i < (int)(v[curr].size()); i++ ) {
        if ( v[curr][i] == prev ) continue;
        int temp = dfs(v[curr][i],curr);
        child[curr] += child[v[curr][i]]+1;
        vv.push_back(make_pair(temp,v[curr][i]));
    }
    //cout<<curr<<" "<<child[curr]<<"\n";
    if ( vv.size() == 0 ) return 0;
    if ( vv.size() == 1 ) return child[curr];
    if ( vv.size() == 2 ) {
       return vv[0].first+vv[1].first;
    }
    int ans = INF,val;
    for ( int i = 0; i < vv.size(); i++ ) {
        for ( int j = i+1; j < vv.size(); j++ ) {
            val = vv[i].first+vv[j].first+child[curr]-child[vv[i].second]-child[vv[j].second]-2;
            ans = min(ans, val);
        }
    }
    ans = min(ans, child[curr]);
    return ans;
}

int main()
{
    int t,n,x,y;
   freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    for ( int l = 1; l <= t; l++ ) {
        cin >> n;
        for ( int i = 0; i < n; i++ ) v[i].clear();
        for ( int i = 0; i < n-1; i++ ) {
            cin >> x >> y;
            x--; y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        int ans = INF;
        for ( int i = 0; i < n; i++ ) {
            ans = min(ans, dfs(i,-1));
        }        
        //for ( int i = 0; i < n; i++ ) cout << i << " " << child[i] << endl;
        cout << "Case #" << l << ": ";
        cout << ans << endl;
    }
    return 0;
}
