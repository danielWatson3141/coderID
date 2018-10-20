#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a[160];
string b[160];
string c[160];

void copy(int n){
  int i;
  for(i=1;i<=n;i++)
    c[i]=a[i];
}

int main(){
  int t,z,n,l,i,j,k,count,m,flag,f;
  cin >> t;
  for(z=1;z<=t;z++){
    cin >> n >> l;
    m=200;flag=0;
    for(i=1;i<=n;i++)
      cin >> a[i];
    for(i=1;i<=n;i++)
      cin >> b[i];
    sort(b+1,b+n+1);
    for(i=1;i<=n;i++){
      count=0;f=1;
      copy(n);
      for(j=0;j<l;j++){
        if(a[i][j]==b[1][j])
          continue;
        count++;
        for(k=1;k<=n;k++)
          if(c[k][j]=='1')
            c[k][j]='0';
          else
            c[k][j]='1';
      }
      sort(c+1,c+n+1);
      for(j=1;j<=n;j++){
        if(c[j]!=b[j]){
          f=0;
          break;
        }
      }
      //cout << f << endl;
      if(f==1){
        m=min(m,count);
        flag=1;
      }
    }
    if(flag==0)
      cout << "Case #" << z << ": " << "NOT POSSIBLE" << endl;
    else
      cout << "Case #" << z << ": " << m << endl;
  }
  return 0;
}