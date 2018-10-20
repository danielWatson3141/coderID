#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<sstream>

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

using namespace std;

vector<vector<int> > children;
int n;

int dfs(int node, int parent)
{
    if(parent == -1)
    {
        if(children[node].size()==1)
            return 1;
        if(children[node].size()==2)
            return dfs(children[node][0],node)+dfs(children[node][1],node)+1;
        vector<int> res;
        forn(i,children[node].size())
            res.push_back(dfs(children[node][i],node));
        sort(all(res));
        reverse(all(res));
        return res[0]+res[1]+1;
    }
    if(children[node].size()==1)
        return 1;
    if(children[node].size()==2)
        return 1;
    vector<int> res;
    forn(i,children[node].size())
    if(children[node][i]!=parent)
        res.push_back(dfs(children[node][i],node));
    sort(all(res));
    reverse(all(res));
    return res[0]+res[1]+1;
}

int main()
{
    freopen("B-small.in","r",stdin);
    freopen("B.out","w",stdout);
    int casos;
    cin >> casos;
    for(int casito = 1; casito <= casos; casito++)
    {
        cin >> n;
        children.resize(n);
        forn(i,n)
            children[i].clear();
        forn(i,n-1)
        {
            int a,b;
            cin >> a >> b;
            a--;
            b--;
            children[a].push_back(b);
            children[b].push_back(a);
        }
        int res = n;
        forn(i,n)
            res = min(res,n-dfs(i,-1));
        cout << "Case #" <<casito <<": " << res << endl;
    }
}
