#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long ini[200];
long long target[200];
long long tt[200];
int n,l;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    int cas=1;
    while(T--)
    {
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;i++)
        {
            char s[100];
            scanf("%s",s);
            long long temp=1;
            long long res=0;
            for(int j=0;j<l;j++)
            {
                if(s[j]=='1')res+=temp;
                temp*=2;
            }
            ini[i]=res;
        }
        for(int i=0;i<n;i++)
        {
            char s[100];
            scanf("%s",s);
            long long temp=1;
            long long res=0;
            for(int j=0;j<l;j++)
            {
                if(s[j]=='1')res+=temp;
                temp*=2;
            }
            target[i]=res;
        }
        sort(ini,ini+n);
        sort(target,target+n);
        int ans=60;
        for(int i=0;i<n;i++)
        {
            long long cc=ini[i]^target[0];
            for(int j=0;j<n;j++)
            {
                tt[j]=ini[j]^cc;
            }
            sort(tt,tt+n);
            int flag=1;
            for(int j=0;j<n;j++)
                if(target[j]!=tt[j])
            {
                flag=0;break;
            }
            int cres=0;
            if(flag)
            {
                while(cc)
                {
                    if(cc%2)cres++;
                    cc/=2;
                }
                ans=min(ans,cres);
            }
        }
        if(ans==60)printf("Case #%d: NOT POSSIBLE\n",cas++);
        else printf("Case #%d: %d\n",cas++,ans);
    }
}
