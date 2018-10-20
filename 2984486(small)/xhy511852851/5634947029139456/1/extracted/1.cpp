#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Ans;
int m1[200],m2[200];
bool tran[50];
double s1[200],s2[200];
char sh1[160][50],sh2[160][50];
int cmp(const void *a ,const void *b)
{
    return *(double *)a - *(double *)b;
}
bool slove(int  n,int l)
{

    int k,ans;
    Ans=1000;
    for(int i=0;i<n;i++)
    {
        s2[i]=0;
        for(int j=0;j<l;j++) s2[i]=s2[i]*2+sh2[i][j]-'0';
    }
    qsort(s2,n,sizeof(double),cmp);
    for(int k=0;k<n;k++)
    {
        ans=0;
        for(int i=0;i<l;i++) tran[i]=0;
    for(int i=0;i<l;i++)
    {
        if(sh1[0][i]!=sh2[k][i])
        {
            ans++;
            tran[i]=1;
        }
    }

    //for(int i=0;i<l;i++) printf("t[%d]=%d ",i,tran[i]);printf("\n");
    for(int i=0;i<n;i++)
    {
        s1[i]=0;
        for(int j=0;j<l;j++)
        {
            if(!tran[j]) s1[i]=s1[i]*2+sh1[i][j]-'0';
            else s1[i]=s1[i]*2+1-(sh1[i][j]-'0');
        }
    }
    qsort(s1,n,sizeof(double),cmp);
    //for(int i=0;i<n;i++) printf("s1[%d]=%.0lf\n",i,s1[i]);
   // for(int i=0;i<n;i++) printf("s2[%d]=%.0lf\n",i,s2[i]);
    bool cb=1;
    for(int i=0;i<n;i++) if(abs(s1[i]-s2[i])>0.5){cb=0;break;}
    if(cb==1)
    {
        if(ans<Ans) Ans=ans;
    }
    }
    if(Ans!=1000) return 1;
    return 0;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.txt","w",stdout);
    int T,N,L,t=1,cb;
    char ch[50];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&L);
        for(int i=0;i<200;i++) m1[i]=0;
        for(int i=0;i<200;i++) m2[i]=0;
        for(int i=0;i<N;i++)
        {
            scanf("%s",sh1[i]);//printf("1:%s\n",ch);
        }
        for(int i=0;i<N;i++)
        {
            scanf("%s",sh2[i]);//printf("2:%s\n",ch);
            // printf("s2[%d]=%.0lf\n",i,s2[i]);
        }
        //for(int i=0;i<N;i++) printf("m1[%d]=%d,m2[%d]=%d\n",i,m1[i],i,m2[i]);
       cb=slove(N,L);
       //cb=1;
        if(cb) printf("Case #%d: %d\n",t++,Ans);
        else printf("Case #%d: NOT POSSIBLE\n",t++);
    }
    return 0;
}
