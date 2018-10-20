#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<iostream>
#include<sstream>
using namespace std;
#define ll long long
int T,cas=0,N,L,f[45];
string s[155],t[155];
map<string,int> mp;
bool ch()
{
    for(int i=0;i<N;i++)
    {
        string tp=s[i];
        for(int j=0;j<L;j++)
        if(f[j])
        {
            if(tp[j]=='0')tp[j]='1';
            else tp[j]='0';
        }
        if(mp.find(tp)==mp.end())return false;
    }
    return true;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        cin>>N>>L;
        mp.clear();
        for(int i=0;i<N;i++)cin>>s[i];
        for(int i=0;i<N;i++)
        {
            cin>>t[i];
            mp[t[i]]=1;
        }
        int ans=1000;
        for(int i=0;i<N;i++)
        {
            int cnt=0;
            for(int j=0;j<L;j++)
            {
                if(s[0][j]==t[i][j])f[j]=0;
                else
                {
                    f[j]=1;
                    cnt++;
                }
            }
            if(ch())ans=min(ans,cnt);
        }
        printf("Case #%d: ",++cas);
        if(ans==1000)puts("NOT POSSIBLE");
        else printf("%d\n",ans);
    }
}
