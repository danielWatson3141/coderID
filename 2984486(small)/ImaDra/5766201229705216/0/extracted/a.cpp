#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<ctime>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include <cstdio>
//#define F first
//#define S second
//#define mp make_pair
#define inf 1000*1000*1000
#define mod 1000000007
double delta=0.0000001;
using namespace std;
int n, a[10009], te, m, d[10009], x, y, ind;
int ans = inf;
vector<int> g[1009];
bool check(int en)
{
    //cout<<en<<" ";
    //cout<<"NEW:"<<endl;
    int u[10009], dd[10009];
    memset(u, 0, sizeof(u));
    for(int i=1;i<=n;i++)
        dd[i]=d[i];//, cout<<dd[i]<<" ";
    //cout<<endl;
    for(int i=1;i<=en;i++)
    {
        //cout<<a[i]<<" ";
        u[a[i]]=1;
        for(int j=0;j<g[a[i]].size();j++)
        {
            int x = g[a[i]][j];
            dd[x]--;
        }
    }
    //cout<<endl;
    if(n==1 && u[1]==0)
    {
        //cout<<0<<" "<<1<<endl;
        return 1;
    }
    bool p = 1;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        //cout<<dd[i]<<" ";
        if(u[i])
            continue;
        if(dd[i]<1 || dd[i]>3)
        {
            p=0;
            break;
        }
        if(dd[i]==2)
            sum++;
    }
    //cout<<sum<<" "<<p<<" ";
    if(sum == 1 && p)
    {
        //cout<<1<<endl;
        return 1;
    }
    //cout<<0<<endl;
    return 0;
}
void go(int v)
{
    for(int i=a[v-1]+1;i<=n;i++)
    {
        a[v] = i;
        if(check(v))
        {
            ans = min(ans, v);
        }
        go(v+1);
    }
}
int main()
{
    ifstream cin("B-small-attemptt1.in");
    ofstream cout("B-small-attemptt1.out");
    cin>>te;
    while(te--)
    {
        memset(a, 0, sizeof(a));
        memset(d, 0, sizeof(d));
        ans = inf;
        ind++;
        cin>>n;
        m = n - 1;
        for(int i=1;i<=m;i++)
        {
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
            d[x]++;
            d[y]++;
        }
        if(check(0))
        {
            ans = 0;
        }
        go(1);
        //cout<<endl;
        cout<<"Case #"<<ind<<": ";
        if(ans==inf)
            cout<<m<<endl;
        else
            cout<<ans<<endl;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
    }
}
