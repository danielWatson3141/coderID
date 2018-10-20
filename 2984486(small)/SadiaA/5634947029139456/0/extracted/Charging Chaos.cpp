#include<cstdio>
#include<algorithm>
using namespace std;
char DEV[12][12];
char OUT[12][12];
int dev[12];
int out[12];
int out1[12];
int main()
{
    int T,n,l,it,i,j,cnt,flip;
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("A_small.out","w",stdout);
    scanf("%d",&T);
    for(it=1; it<=T; it++)
    {
        scanf("%d%d",&n,&l);
        for(i=0; i<n; i++)  scanf("%s",OUT[i]);
        for(i=0; i<n; i++)  scanf("%s",DEV[i]);
        for(i=0; i<n; i++)  out[i]=dev[i]=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<l; j++)
            {
                if(OUT[i][j]=='1')  out[i]|=(1<<j);
                if(DEV[i][j]=='1')  dev[i]|=(1<<j);
            }
        }
        //for(i=0; i<n; i++)  printf("%d\n",dev[i]);
        //for(i=0; i<n; i++)  printf("%d\n",out[i]);
        sort(dev,dev+n);
        cnt=l+1;
        for(flip=0; flip<(1<<l); flip++)
        {
           for(i=0; i<n; i++)  out1[i]=out[i];
           //for(i=0; i<n; i++)  printf("%d\n",out1[i]);
           for(i=0; i<l; i++)
           {
               if(flip&(1<<i))
               {
                   for(j=0; j<n; j++) out1[j]^=(1<<i);
               }
           }
           //for(i=0; i<n; i++)  printf("%d\n",out1[i]);

           sort(out1,out1+n);
           bool f=true;
           for(i=0; i<n; i++)
           {
               if(dev[i]!=out1[i])
               {
                   f=false;break;
               }
           }
           //for(i=0; i<n; i++) printf("%d\n",dev[i]);
           //printf("f:%d\n",f);
           if(f)
           {
               int cc=0;
               for(i=0; i<l; i++){
                  if(flip&(1<<i))  cc++;
               }
               //printf("flip:%d cc:%d\n",flip,cc);
               cnt=min(cnt,cc);
           }
           //printf("cnt:%d\n",cnt);
        }
        printf("Case #%d: ",it);
        if(cnt==l+1)  printf("NOT POSSIBLE\n");
        else printf("%d\n",cnt);
        //printf("%d\n",cnt);
    }
    return 0;
}
