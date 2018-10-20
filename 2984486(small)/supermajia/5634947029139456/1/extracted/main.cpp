#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
string outlet[155];
string device[155];
int mat[155];
int used[155];
int n,l;
int differnt;
long long currentedge;
long long computelength(string a,string b)
{
    long long ret = 0;
    differnt = 0;
    for(int i=0;i<l;++i)
    {
        ret*=2;
        if(a[i]!=b[i])
        {
            differnt++;
            ret++;
        }
    }
    return ret;
}

bool crosspath(int k)
{
    for (int i=1;i<=n;i++)
    {
        long long j = computelength(device[k],outlet[i]);
        if (j==currentedge&&!used[i])
        {
            used[i]=true;
            if (mat[i]==-1 || crosspath(mat[i]))
            {
                mat[i]=k;
                return true;
            }
        }
    }
    return false;
}
int hungary()
{
    int ret = 0;
    for (int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if (crosspath(i))
            ret++;
    }
    return ret;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out3.txt","w",stdout);
    int cas = 1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>l;
        //8memset(mat,-1,sizeof(mat));
        for(int i=1;i<=n;++i)
            cin>>outlet[i];
        for(int i=1;i<=n;++i)
            cin>>device[i];
        bool f = 0;
        int ans = 9999;
        int dif;
        for(int i=1;i<=n;++i)
        {
            currentedge = computelength(device[1],outlet[i]);
            dif = differnt;
            memset(mat,-1,sizeof(mat));
            if(hungary()==n)
            {
//                cout<<dif<<endl;
//                cout<<"fuck "<<i<<endl;
//                for(int j=1;j<=n;++j)
//                {
//                    cout<<j<<" "<<mat[j]<<endl;
//                }
//                cout<<currentedge<<endl;
                f = 1;
                ans = min(ans,dif);
            //    cout<<ans<<endl;
            }
        }
        cout<<"Case #"<<cas++<<": ";
        if(f)
        {
            cout<<ans<<endl;
        }
        else
            cout<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}
