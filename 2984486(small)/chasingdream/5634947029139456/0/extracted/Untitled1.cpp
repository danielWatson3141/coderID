#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
long long a[50];
int b[160];   
long long a2[50];
int b2[160];   
int n,l;
struct node
{
   int x,y;
   long long value;
}c[150*150];
int flagx[150];
int flagy[150];
bool cmp(node a,node b)
{
  return a.value<b.value||a.value==b.value&&a.x<b.x;
}
int check(long long x)
{
  int ans=0;
  while(x>0)
  {
     ans+=x&1;
     x=x>>1;
  }
  return ans;
}
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A.out","w",stdout);
    int t;
    char tmp[100];
    cin>>t;
    int cas=1;
    while(t--)
    {
      cin>>n>>l;
      memset(a,0,sizeof(a));
      for(int i=0;i<n;i++)
      {
        scanf("%s",tmp);
        for(int j=0;j<l;j++)
           a[i]=(a[i]<<1)|(tmp[j]-'0');
        //cout<<a[i]<<endl;
      }
      memset(a2,0,sizeof(a2));
      for(int i=0;i<n;i++)
      {
        scanf("%s",tmp);
        for(int j=0;j<l;j++)
           a2[i]=(a2[i]<<1)|(tmp[j]-'0');
       // cout<<a2[i]<<endl;
      }
      for(int i=0;i<n;i++)
      {
       // cout<<"----";
        for(int j=0;j<n;j++)
        {
          c[i*n+j].x=i;
          c[i*n+j].y=j;
          c[i*n+j].value=a[i]^a2[j];
        //  cout<<(a[i]^a2[j])<<" ";
        }
       // cout<<endl;
      }
      sort(c,c+n*n,cmp);
      int flag=0;int count=0;
      int res=1000;
           // for(int i=0;i<n*n;i++) cout<<c[i].value<<' ';
            //cout<<endl;
      for(int i=0;i<n*n;i++)
      {
        if(i==0||c[i].value!=c[i-1].value)
        {
           count=0;
           memset(flagx,0,sizeof(flagx));
           memset(flagy,0,sizeof(flagy));
           flagx[c[i].x]++;
           flagy[c[i].y]++;
           count++;
           flag=1;
                    // cout<<c[i].value<<' '<<"count  "<<count<<endl;
           if(count==n)
           {   //cout<<"**"<<c[i].value<<' '<<count<<endl;
               res=min(res,check(c[i].value));}
        }
        else 
        {
           if(flagx[c[i].x]||flagy[c[i].y])
              continue;
           flagx[c[i].x]++;
           flagy[c[i].y]++;
           count++;
           //cout<<c[i].value<<' '<<"count  "<<count<<endl;
           if(count==n)
           {   //cout<<"**"<<c[i].value<<' '<<count<<endl;
               res=min(res,check(c[i].value));}
        }
      }
      if(res<200)
      printf("Case #%d: %d\n",cas++,res);
      else
      printf("Case #%d: NOT POSSIBLE\n",cas++);
   }
   return 0;
}
      
               
        
        
                
