#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct st
{
    int x;
    int y;
    st()
    {
        x=0;
        y=0;
    }
    st(int X, int Y)
    {
        x=X;
        y=Y;
    }
    st(const st &s)
    {
        x=s.x;
        y=s.y;
    }
};
bool operator < (st a, st b)
{
    return (a.y-a.x>b.y-b.x);
}
pair<int, int> dfs (int x, vector<vector<int> > &v, vector<bool> &b, int n)
{
    b[x]=0;
    int z=n, y=n, s=0;
    vector<st> r;
    for (int i=0;i<v[x].size();++i)
    {
        if (b[v[x][i]])
        {
            pair<int, int> p=dfs(v[x][i], v, b, n);
            s+=p.second;
            st S(p.first, p.second);
            r.push_back(S);
        }
    }
    sort(r.begin(), r.end());
    if (s==0)
    {
        return make_pair(0, 1);
    }
    if (r.size()==1)
    {
        return make_pair(s, s+1);
    }
    return make_pair(s-(r[0].y-r[0].x+r[1].y-r[1].x), s+1);
}
int main()
{
    ifstream cin("inputL.in");
    ofstream fout("output.txt");
    int t, z;
    cin>>t;
    for (z=0;z<t;++z)
    {
        cout<<z<<endl;
        int n, i, j, k;
        cin>>n;
        vector<vector<int> > v(n+1);
        for (i=0;i<n-1;++i)
        {
            cin>>j>>k;
            v[j].push_back(k);
            v[k].push_back(j);
        }
        int res=n, r;
        for (i=1;i<=n;++i)
        {
            vector<bool> b(n+1, 1);
            r=dfs(i, v, b, n).first;
            res=min(res, r);
        }
        fout<<"Case #"<<z+1<<": "<<res<<"\n";
    }
    return 0;
}
