#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<map>
using namespace std;
long long a[160],b[160],d[160];
int n,m;
vector<long long>c;
char s[50];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    int ca=1;
    scanf("%d",&t);
    while(t--)
    {
        map<long long,int>p;
        scanf("%d%d",&n,&m);
        c.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            a[i]=0;
            for(int j=0;j<m;j++)a[i]=a[i]*2+(s[j]-'0');
            p[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            b[i]=0;
            for(int j=0;j<m;j++)b[i]=b[i]*2+(s[j]-'0');
            c.push_back(b[i]^a[0]);
        }
        int ans=50;
        for(int i=0;i<n;i++)
        {
            //cout<<c[i]<<endl;
            map<long long,int>pp;
            for(int j=0;j<n;j++)
            {
                d[j]=c[i]^b[j];
                pp[d[j]]++;
            }
            bool ff=0;
            for(int j=0;j<n;j++)
            {
                //cout<<p[a[j]]<<" "<<pp[a[j]]<<endl;
                if(p[a[j]]!=pp[a[j]])
                {
                    ff=1;
                    break;
                }
            }
            if(ff==0)
            {
                int cnt=0;
                long long r=c[i];
                while(r)
                {
                    if(r%2)cnt++;
                    r/=2;
                }
                ans=min(ans,cnt);
            }
        }
        cout<<"Case #"<<ca++<<": ";
        if(ans==50)cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
