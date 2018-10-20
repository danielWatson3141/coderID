#include <iostream>
#include <algorithm>
using namespace std;


    int n,l;
    string a[20],b[20];
    int mi=99999;
    
void dfs(string s,int lv)
{
  if (lv==l)
  {
    //cout<<s<<' '<<lv<<endl;
    string c[20];
    for (int i=0;i<n;i++)
    c[i]=a[i];
    int q=0;
    for (int i=0;i<l;i++)
    if (s[i]=='1')
    {
    q++;
      for (int j=0;j<n;j++)
      if (c[j][i]=='0')
      c[j][i]='1';
      else c[j][i]='0';
    }
    

    sort(c,c+n);
    
    bool z=1;
    for (int i=0;i<n;i++)
    if (c[i]!=b[i])
    z=0;
    
    if (z)
    if (q<mi)
    {
      //cout<<s<<' '<<q<<endl;
    mi=q;
  }
    
    return;
  }
  dfs(s+"0",lv+1);
  dfs(s+"1",lv+1);
}

int main()
{
  int z;
  cin>>z;
  for (int i=1;i<=z;i++)
  {
    cout<<"Case #"<<i<<": ";
    cin>>n>>l;
    mi=99999;
    for (int j=0;j<n;j++)
    cin>>a[j];
    for (int j=0;j<n;j++)
    cin>>b[j];
    
    sort(b,b+n);
    dfs("",0);
    
    if (mi==99999)
    cout<<"NOT POSSIBLE\n";
    else
    cout<<mi<<endl;
    
  }
  return 0;
}
