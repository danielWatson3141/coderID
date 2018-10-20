#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1100
#include<set>

set<int> s[N],s1[N];
int p[N];

bool vis[N];

void dfs(int k)
{
    if(vis[k]) return;
    vis[k]=1;

    set<int>::iterator it;
    for( it=s1[k].begin();it!=s1[k].end();it++)
     {
        int x=*it;
        dfs(x);
     }
}

int main()
{

    freopen("b2.in","r",stdin);
    freopen("b2.out","w",stdout);

    int T;
    scanf("%d",&T);
    for( int ca=1;ca<=T;ca++)
    {
       int n;
       scanf("%d",&n);
       for(int i=0;i<=n;i++) s[i].clear();
       for(int i=0;i<n-1;i++)
       {
           int x,y;
           scanf("%d%d",&x,&y);
           x--;y--;
           s[x].insert(y);
           s[y].insert(x);
       }

       int k=1;
       for(int i=0;i<n;i++) k*=2;
       int ans=n-1;

       for(int i=0;i<k;i++)
       {
           for(int j=0;j<n;j++) p[j]=s[j].size(),vis[j]=0,s1[j]=s[j];

           int cnt=0;
           for(int j=0;j<n;j++)
           {
               int tem= 1<<j;
               if(  !(tem & i) ) continue;
               vis[j]=1;
               cnt++;
               set<int>::iterator it;
               for( it=s1[j].begin();it!=s1[j].end();it++)
               {
                   int x=*it;
                   p[x]--;
                   s1[x].erase(x);
               }
               p[j]=-1;
               s1[j].clear();
           }
          if(cnt>= ans) continue;

         // printf("%d kkk  %d  %d\n",i,cnt,ans);

          int a=0,b=0,c=0;
          bool f=true;
          for(int j=0;j<n;j++)
          {
              if(p[j]==2) a++;
              if(p[j]>3) b++;
              if(p[j]==0) c++;
          }
         for(int j=0;j<n;j++)
            if(vis[j]==0)
         {
             dfs(j);
             break;
         }

         for(int j=0;j<n;j++) if(vis[j] ==0 ) f=false;

          if(f && a==1 && b==0 && c==0) ans=cnt;
       }



        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
