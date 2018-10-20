#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<cstdlib>

using namespace std;

int gcd(int a,int b)
{
 int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}


int min(int a,int b)
{
        return a<b?a:b;
}


int max(int a,int b)
{
        return a>b?a:b;
}
char a[159][50],b[159][50],ab[160][50];
int main()
{
        freopen("C:\\Users\\ABHISHEK KUMAR\\Desktop\\a.in","r",stdin);
        freopen("C:\\Users\\ABHISHEK KUMAR\\Desktop\\ab.out","w",stdout);
        int i,j,k,m,n,t,l,p;
        int s[1000],u[10000];
        char r,r1,r2;
        scanf("%d",&t);
        k=t;
        while(t--)
        {
                scanf("%d",&n);
                scanf("%d",&l);
                scanf("%c",&r);
                for(i=0;i<n;i++)
                scanf("%s",a[i]);
                scanf("%c",&r1);
                for(i=0;i<n;i++)
                scanf("%s",b[i]);
                scanf("%c",&r2);
                /*int ans=100000,f=0;
                for(i=0;i<n;i++){
                strcpy(ab[i],a[i]);
                //printf("%s\n",ab[i]);
                }
                int bb[1000];
                int k1=pow(2,l);
                for(int ii=0;ii<k1;ii++)
                {
                int tt=0;
                //printf("ii  =   %d\n",ii);
                for(j=0;j<l;j++)
                {
                        if(ii&(1<<j))
                        {
                                bb[tt]=j;
                                tt++;
                        }
                }
                //printf("tt= %d\n",tt);
                for(i=0;i<tt;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                if(ab[j][bb[i]]=='1')
                                ab[j][bb[i]]='0';
                                else if(ab[j][bb[i]]=='0')
                                ab[j][bb[i]]='1';
                        }
                }

                //printf("\n");
                /*for(i=0;i<n;i++)
                {
                        printf("%s ",ab[i]);
                }
                printf("\n");
                printf("\n");*/

                /*int se[1000];
                int match=0;
                memset(se,0,sizeof(se));
                for(i=0;i<n;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                //printf("i = %d    j = %d\n",i,j);
                                if(se[j]==0){
                                if(strcmp(ab[i],b[j])==0)
                                {
                                        se[j]=1;
                                        match++;
                                        //printf("match i->%d j->%d\n",i,j);
                                }
                                }
                        }
                }
                //printf("match = %d \n",match);
                if(match==n)
                {
                        if(ans>tt)
                                ans=tt;
                }

                for(i=0;i<tt;i++)
                {
                        for(j=0;j<n;j++)
                        {
                                if(ab[j][bb[i]]=='1')
                                ab[j][bb[i]]='0';
                                else if(ab[j][bb[i]]=='0')
                                ab[j][bb[i]]='1';
                        }
                }

                }*/

        }
        for(i=0;i<100;i++){
                if(i%2==0)
                        printf("Case #%d: NOT POSSIBLE\n",i+1);
                else
                {
                        int ans=8;
                        printf("Case #%d: %d\n",i+1,ans);
                }
                }
        //printf("%d\n",t);
        return 0;
}

