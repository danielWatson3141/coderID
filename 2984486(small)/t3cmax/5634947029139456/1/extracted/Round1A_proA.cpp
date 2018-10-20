#include<fstream>
#include<string.h>
#include<cmath>
#include<stdio.h>
using namespace std;

ifstream fin("A-large.in");
ofstream fout("ans.out");

int n,l,t;
char g[151][41];
char h[151][41];

int ans,temp_ans;
bool u[41];
bool flag[151];
int p;
void get_u(int now)
{
     int i,j;
     for(i=1;i<=l;i++)
     {
         if(h[1][i]!=g[now][i])
         {
             u[i]=1;
             temp_ans++;
         }
     }
     
     
     return ;
}

bool march(int now_g,int now_h)
{
    int i,j;
    for(i=1;i<=l;i++)
    {
         if(u[i]==0)
         {
             if(g[now_g][i]!=h[now_h][i])
             {
                 return false;
             }
         }
         else
         {
             if(g[now_g][i]==h[now_h][i])
             {
                 return false;
             }
         }
    }
    
    
    return true;
}


int main()
{
    int i,j,k,times;
    fin>>t;
    for(times=1;times<=t;times++)
    {
         ans=999999;
         fin>>n>>l;
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=l;j++)
             {
                fin>>g[i][j];
             }
         }
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=l;j++)
             {
                 fin>>h[i][j];
             }
         }
         
         for(i=1;i<=n;i++)
         {
              memset(u,0,sizeof(u));
              temp_ans=0;
              get_u(i);
              
              p=1;
              memset(flag,0,sizeof(flag));
              flag[i]=1;
              for(j=2;j<=n;j++)
              {
                   for(k=1;k<=n;k++)
                   {
                       if(flag[k]==0)
                       {
                            if(march(k,j)==true)
                            {
                                 flag[k]=1;
                                 p++;
                            }
                       }
                   }
              }
              
              if(p==n)
              {
                   ans=min(ans,temp_ans);
              }
         }
         
         fout<<"Case #"<<times<<": ";
         if(ans==999999)
         {
             fout<<"NOT POSSIBLE"<<endl;
         }
         else
         {
             fout<<ans<<endl;
         }
    }
    
    system("pause");
    return 0;
}
