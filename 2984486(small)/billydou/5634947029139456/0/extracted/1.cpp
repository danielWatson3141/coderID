#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 155,oo = 0xfffffff;
struct node{
       char s[50];
       }a[maxn],b[maxn];
int cmp(const void *A,const void *B)
{
    return (strcmp((*(node *)A).s,(*(node *)B).s)<0)?-1:1;
}
int s1[maxn],s2[maxn],n,m,mins,flag;
void init()
{
     scanf("%d%d",&n,&m);
     int i,j;
     memset(s1,0,sizeof(s1));
     memset(s2,0,sizeof(s2));
     for(i=1;i<=n;i++){
                       scanf("%s",&a[i].s);
                       for(j=0;j<m;j++)if(a[i].s[j]=='0')++s1[j];
                       }
     for(i=1;i<=n;i++){
                       scanf("%s",&b[i].s);
                       for(j=0;j<m;j++)if(b[i].s[j]=='0')++s2[j];
                       }
     flag = 0;
     for(i=0;i<m;i++)
     if((s1[i]!=s2[i])&&(s1[i]!=n-s2[i]))flag=1;
}
void work(int x,int s)
{
     if(s>=mins)return ;
     if(x>=m){
             qsort(a+1,n,sizeof(a[0]),cmp);
             qsort(b+1,n,sizeof(b[0]),cmp);
             int i;
             for(i=1;i<=n;i++)if(strcmp(a[i].s,b[i].s)!=0)return ;
             if(s<mins)mins=s;
             return ;
             }
     if(x%5==2){
                int i,j;
                qsort(a+1,n,sizeof(a[0]),cmp);
                qsort(b+1,n,sizeof(b[0]),cmp);
                for(i=1;i<=n;i++)
                for(j=0;j<x;j++)
                if(a[i].s[j]!=b[i].s[j])return ;
                }
     if(s1[x]*2!=n){
                      int i;
                      if(s1[x]!=s2[x])
                      {
                      for(i=1;i<=n;i++){
                                        a[i].s[x]=97-a[i].s[x];
                                        }
                      work(x+1,s+1);
                      for(i=1;i<=n;i++){
                                        a[i].s[x]=97-a[i].s[x];
                                        }
                      }
                      else{work(x+1,s);}
                      }
     else{
          work(x+1,s);
          int i;
          for(i=1;i<=n;i++){
                                        a[i].s[x]=97-a[i].s[x];
                                        }
          work(x+1,s+1);
          for(i=1;i<=n;i++){
                                        a[i].s[x]=97-a[i].s[x];
                                        }
          }
}
int main(void)
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int tc,i;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++){
                       printf("Case #%d: ",i);
                       init();
                       if(flag){printf("NOT POSSIBLE\n");continue;}
                       mins = oo;
                       work(0,0);
                       if(mins!=oo)printf("%d\n",mins);else printf("NOT POSSIBLE\n");
                       }
    return 0;
}
