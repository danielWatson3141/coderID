//gskhirtladze

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool ans;

int i,j,p,l,n;
string s[250];
string z[250];
string z2[250];
int r;

bool check()
 {
  for (i=1;i<=n;i++)
   z2[i]=s[i];
  for (i=0;i<l;i++)
   if (((1<<i) & p))
    for (j=1;j<=n;j++)
     {
      if (z2[j][i] == '0') z2[j][i]='1'; else z2[j][i]='0';
     }
    sort(z2+1,z2+n+1);
    r=1;
   ans=true;
    for (i=1;i<=n;i++)
     {
      while (r <= n && z2[r] < z[i]) r++;
      if (r <= n && z2[r] == z[i]) continue;
      ans=false;
     }
    return ans;
 }

int t,t1;

main()
 {
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  scanf("%d",&t);
  for (t1=1;t1<=t;t1++)
   {
    scanf("%d%d",&n,&l);
    for (i=1;i<=n;i++)
     { cin>>s[i]; }
    for (i=1;i<=n;i++)
     { cin>>z[i]; }
    sort(z+1,z+n+1);
    cout<<"Case #"<<t1<<": ";
    for (p=0;p<(1<<l);p++)
     if (check())
      {
       cout<<__builtin_popcount(p)<<endl;
       break;
      }
    if (p == (1<<l))
     cout<<"NOT POSSIBLE"<<endl;
   }
 }
