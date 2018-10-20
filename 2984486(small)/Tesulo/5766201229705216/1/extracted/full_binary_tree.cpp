#include <stdio.h>
#include <vector>

using namespace std;

vector<long long> sus[2000];
long long ot[2000];
long long t,tt,i,j,k,l,m,n;


long long zisti(long long root)
{
   long long m1, m2, ii, kk;
   
   m1 = 0; 
   m2 = 0;
 
   for(ii=0;ii<sus[root].size();ii++)
     if(sus[root][ii] != ot[root])
       {
          kk = zisti(sus[root][ii]);
       
          if(kk >= m1)
             {
             m2 = m1;
             m1 = kk;
             }
          else 
            if(kk >= m2) m2 = kk;   
       }

if(m2 == 0) return 1;

return 1 + m1 + m2;
}


void postav(long long root)
{
  long long ii;
  
  for(ii=0;ii<sus[root].size();ii++)
    if(sus[root][ii] != ot[root])
      {
        ot[sus[root][ii]] = root;
        postav(sus[root][ii]); 
      }

return;
}


long long koren(long long root)
{
long long ii;

ot[root] = 0;
postav(root);

//for(ii=1;ii<=n;ii++) printf("%lld: %lld -> %lld\n",root,ii,ot[ii]);

return n-zisti(root);
}


int main()
{

scanf("%lld",&t);

for(tt=1;tt<=t;tt++)
{

scanf("%lld",&n);

for(i=0;i<=n;i++) sus[i].clear();

for(i=1;i<n;i++)
 {
 scanf("%lld %lld",&j,&k);
 
 sus[j].push_back(k);
 sus[k].push_back(j); 
 }

m = n+1;

for(i=1;i<=n;i++)
  {
   k = koren(i);
   if(k<m) m = k;
   
//   printf("%lld -> %lld\n", i, k);
  }

printf("Case #%lld: %lld\n",tt,m);
}


return 0;
}