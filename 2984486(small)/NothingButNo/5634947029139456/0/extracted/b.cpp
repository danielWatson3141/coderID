#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int ca=1;
int n,l;
int t;
int a[15],b[15],c[15];
int num;

int getone(int x)
{
    int total=0;
    while(x)
    {
        if(x&1)
        total++;
        x=x>>1;
    }
    return total;
}

int ex(int x)
{
    int ans=0;
    int i;
    for(i=0;x;i++)
    {
        if(x%10)
        ans+=1<<i;
        x=x/10;
    }
 return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    int cc;
    while(t--)
    {
        num=170;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d%d",&n,&l);
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&cc);//cout<<"sss"<<endl;
            a[i]=ex(cc);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&cc);
            b[i]=ex(cc);
        }

        sort(b,b+n);
        int maxn=1<<l;
        bool f=true;
        for(j=0;j<maxn;j++)
        {
            for(i=0;i<n;i++)
                c[i]=a[i]^j;
            sort(c,c+n);
            f=true;
            for(i=0;i<n;i++)
           {
               if(c[i]!=b[i])
             {
                f=false;
                break;
              }
           }
           if(f) num=min(num,getone(j));
        }
        if(num!=170)
        printf("Case #%d: %d\n",ca++,num);
        else
        printf("Case #%d: NOT POSSIBLE\n",ca++);
    }
    return 0;
}

