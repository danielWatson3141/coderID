#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


string  a[200], c[200], b[200];
char  bb[200][50];

long long i,j,k,l,m,n,t,tt;


long long test(long long ind)
{
long long ii, jj, vv=0;

for(jj = 0; jj < l; jj++) if(a[0][jj] != c[ind][jj]) vv++;

for(ii=0;ii<n;ii++)
  for(jj=0;jj<l;jj++)
    if(a[0][jj] == c[ind][jj]) bb[ii][jj] = a[ii][jj];
                      else     bb[ii][jj] = 1-(a[ii][jj]-'0')+'0'; 

for(ii=0;ii<n;ii++) {bb[ii][l] = 0; b[ii] = string(bb[ii]);}

sort(b, b+n);

//for(ii=0;ii<n;ii++) cout << b[ii] << " " << ind << "..\n";

for(ii=0;ii<n;ii++) if(c[ii] != b[ii]) return l+1;

return vv;
}


int main()
{

scanf("%lld",&t);

for(tt=1;tt<=t;tt++)
{

scanf("%lld %lld", &n, &l);

for(i=0;i<n;i++) cin >> a[i];
for(i=0;i<n;i++) cin >> c[i];

sort(c,c+n);

//cout << c[0] << "\n";

m = l+1;

for(i=0;i<n;i++)
  {
  k = test(i);
  if(k<m) m = k;  
  }

if(m == l+1)   printf("Case #%lld: NOT POSSIBLE\n", tt);
    else       printf("Case #%lld: %lld\n", tt, m);
}

return 0;
}