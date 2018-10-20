#include <iostream>
#include <algorithm>

#define K 260

using namespace std;

long long a[10000],i,j,k,l,m,n,t,tt;

int main()
{

cin >> t;

for(tt=1;tt<=t;tt++)
{
cin >> n;

for(i=0;i<n;i++) cin >> a[i];

k = 0;

for(i=0;i<500;i++) if(a[i] > i && a[i] <= i+490) k++;

if(k< K) cout << "Case #" << tt << ": GOOD\n";
  else   cout << "Case #" << tt << ": BAD\n";  
  
//  cout << k << "\n";
}



return 0;
}