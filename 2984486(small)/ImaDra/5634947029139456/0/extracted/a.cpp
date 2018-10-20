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
int n, l, a[1009], te, ind;
string s[1009], t[1009];
int ans = inf;
bool check(int en)
{
    //cout<<"NEW:"<<endl;
    string ss[1009], tt[1009];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<l;j++)
            ss[i][j]=s[i][j], tt[i][j]=t[i][j];
    }
    /*for(int i = 1; i <= n; i++)
    {
        for(int j=0;j<l;j++)
        {
            cout<<ss[i][j];
        }
        cout<<endl;
    }*/
    for(int i=1;i<=en;i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(ss[j][a[i]-1]=='0')
                ss[j][a[i]-1]='1';
            else
                ss[j][a[i]-1]='0';
        }
        //cout<<a[i]<<" ";
    }
    //cout<<endl;
    //sort(ss+1, ss+n+1);
    //sort(tt+1, tt+n+1);
    /*for(int i=1;i<=n;i++)
    {
        for(int j=0;j<l;j++)
            cout<<ss[i][j];
        cout<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<l;j++)
            cout<<tt[i][j];
        cout<<endl;
    }*/
    int u[1009];
    memset(u, 0, sizeof(u));
    bool p3 = 1;
    for(int i = 1; i <= n; i++)
    {
        bool p2=0;
        for(int j=1;j<=n;j++)
        {
            if(u[j])
                continue;
            bool p = 1;
            for(int jj=0;jj<l;jj++)
            {
                if(ss[i][jj]!=tt[j][jj])
                {
                    p=0;
                    break;
                }
            }
            if(p)
            {
                u[j] = 1;
                p2 = 1;
            }
        }
        if(!p2)
        {
            p3 = 0;
            break;
        }
    }
    //cout<<p3<<endl;
    return p3;
}
void go(int v)
{
    for(int i=a[v-1]+1;i<=l;i++)
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
    ifstream cin("A-small-attemptt2.in");
    ofstream cout("A-small-attemptt2.out");
    cin>>te;
    while(te--)
    {
        ind++;
        cin>>n>>l;
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=1;i<=n;i++)
            cin>>t[i];
        if(check(0))
            ans = 0;
        go(1);
        cout<<"Case #"<<ind<<": ";
        if(ans != inf)
            cout<<ans<<endl;
        else
            cout<<"NOT POSSIBLE"<<endl;
        ans = inf;
    }
}
