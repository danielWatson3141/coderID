#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


char str11[222][44],str22[222][44],str33[222][44];
string str1[222],str2[222],str3[222];

long long st1[222][44],st2[222][44],st3[222][44];

int main()
{
    freopen("a1.in","r",stdin);
    freopen("a1.out","w",stdout);


    int cas;
    scanf("%d",&cas);
    int tt=0;
    int n,m;
    while(cas--)
    {
        tt++;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%s",str11[i]);
        for(int i=1;i<=n;i++)
            str1[i]=str11[i];


        for(int i=1;i<=n;i++)
            scanf("%s",str22[i]);
        for(int i=1;i<=n;i++)
            str2[i]=str22[i];


        for(int i=1;i<=n;i++)
            str3[i].resize(m);


        sort(str2+1,str2+n+1);

        int ans=1000000000;
        for(int i=1;i<=n;i++)
        {

            int num=0;
            for(int j=0;j<m;j++)
            if(str1[1][j]!=str2[i][j])
            {
                for(int k=1;k<=n;k++)
                    str3[k][j]=(1-(str1[k][j]-'0'))+'0';
                num++;
            }
            else
            {
                for(int k=1;k<=n;k++)
                    str3[k][j]=str1[k][j];

            }

            sort(str3+1,str3+n+1);


            bool ok=true;
            for(int i=1;i<=n;i++)
            if(str2[i]!=str3[i])
            {
                ok=false;
                break;
            }

            if(ok)
            {
                if(num<ans)
                    ans=num;
            }

        }

        printf("Case #%d: ",tt);
        if(ans!=1000000000)
            printf("%d\n",ans);
        else
            printf("NOT POSSIBLE\n");

    }
    return 0;
}
