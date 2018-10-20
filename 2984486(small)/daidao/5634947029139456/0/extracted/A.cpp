#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;
int n,l;
string s[20];
string ans[20];
string b[20];
map<string,int>ma;
int main()
{
    freopen("Aout.txt","w",stdout);
    int t,i,j,g;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        scanf("%d%d",&n,&l);
        ma.clear();
        for(i=1;i<=n;i++)
        {
            cin>>s[i];
        }
        for(i=1;i<=n;i++)
        {
            cin>>ans[i];
            ma[ans[i]]=1;
        }
        int ix;
        int re=-1;
        for(i=0;i<(1<<l);i++)
        {
            for(j=1;j<=n;j++)
                b[j]=s[j];
            ix=0;
            for(j=0;j<l;j++)
            {
                if((1<<j)&i)
                {
                    ix++;
                    for(g=1;g<=n;g++)
                    {
                        if(b[g][j]=='0')
                            b[g][j]='1';
                        else
                            b[g][j]='0';
                    }
                }
            }
            for(g=1;g<=n;g++)
            {
                if(ma.count(b[g]))
                {
                    continue;
                }
                break;
            }
            if(g>n)
            {
                if(re==-1)
                    re=ix;
                else
                    re=min(re,ix);
            }
        }
        printf("Case #%d: ",cas++);
        if(re==-1)
        {
            puts("NOT POSSIBLE");
        }
        else
            printf("%d\n",re);
    }
    return 0;
}
