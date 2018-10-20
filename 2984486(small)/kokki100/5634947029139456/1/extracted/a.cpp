#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int t,n,el;
string s;
int hp[155][45],lis[155][45],valid[155],lisa[155][45];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    scanf("%d",&t);
    for (int ll=1;ll<=t;ll++)
    {
        scanf("%d %d",&n,&el);

        for (int i=1;i<=n;i++)
        {
            cin >> s;
            for (int j=0;j<el;j++)
                lisa[i][j]=((int)s[j])-48;
        }

        for (int i=1;i<=n;i++)
        {
            cin >> s;
            for (int j=0;j<el;j++)
                hp[i][j]=((int)s[j])-48;
        }

        int ans=1000,temp;
        int bisa;
        for (int j=1;j<=n;j++)
        {
            for (int i=1;i<=n;i++)
                for (int k=0;k<el;k++)
                    lis[i][k]=lisa[i][k];

            bisa=1;
            temp=0;
            memset(valid,0,sizeof(valid));
            for (int k=0;k<el;k++)
            {
                if (hp[1][k]!=lis[j][k]){
                    for (int l=1;l<=n;l++) lis[l][k]= 1 - lis[l][k];
                    temp++;
                }
            }
            valid[j]=1;

            int benar;
            for (int i=2;i<=n;i++)
            {
                benar=0;
                for (int k=1;k<=n;k++)
                {
                    if (valid[k]==0){
                        benar=1;
                        for (int l=0;l<el;l++)
                        {
                            //printf("%d %d\n",hp[i][l],lis[k][l]);
                            if (hp[i][l]!=lis[k][l]) benar=0;
                            //printf("%d %d tes\n",k,benar);
                        }
                    }
                    if (benar == 1){
                        valid[k]=1;
                        break;
                    }
                }
                if (benar==0){
                    bisa=0;
                    break;
                }
                //printf("i =%d\n",i);
            }

            if (bisa==1) ans=min(ans,temp);

            //printf("%d %d %d\n",ans,temp,bisa);
        }

        printf("Case #%d: ",ll);
        if (ans == 1000){
            printf("NOT POSSIBLE\n");
        }
        else printf("%d\n",ans);
    }

    return 0;
}
