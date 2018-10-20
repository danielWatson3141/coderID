#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#define nn 200
using namespace std;
int n,l;
string s[nn];
string ans[nn];
string b[nn];
map<string,int>ma;
int main()
{
    freopen("Ain.txt","r",stdin);
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
        int p[nn],num=0;
        int re=-1;
        for(i=1;i<=n;i++)
        {
            num=0;
            for(j=0;j<l;j++)
            {
                if(ans[i][j]!=s[1][j])
                {
                    p[num++]=j;
                }
            }
            for(j=2;j<=n;j++)
            {
                b[j]=s[j];
                for(g=0;g<num;g++)
                {
                    if(b[j][p[g]]=='0')
                        b[j][p[g]]='1';
                    else
                        b[j][p[g]]='0';
                }
                if(ma.count(b[j]))
                    continue;
                else
                    break;
            }
            if(j>n)
            {
                if(re==-1)
                    re=num;
                else
                    re=min(re,num);
            }
        }
        printf("Case #%d: ",cas++);
        if(re==-1)
            puts("NOT POSSIBLE");
        else
            printf("%d\n",re);
    }
    return 0;
}
