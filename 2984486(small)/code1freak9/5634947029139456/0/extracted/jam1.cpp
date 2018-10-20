#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int recurse(string a[],string b[],int c,int n,int l)
{
//cout<<b[0]<<" "<<a[0]<<" "<<c<<endl;//<<1]<<b[2];
if(c==l+1)return 200;
string d[n];
bool done=true;
for(int i=0;i<n;i++)
{int j;
for(j=0;j<n;j++)
{
if(a[i]==b[j]){break;}
}
if(j==n){done=false;break;}
}
if(done==true) {return 0;}
else if(done==false)
{
for(int j=0;j<n;j++)
{
d[j]=b[j];
if(b[j][c]=='1')d[j][c]='0';
else d[j][c]='1';
//cout<<b[j]<<" "<<d[j]<<endl;
//cout<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
//cout<<c<<endl;
}
return min(recurse(a,d,c+1,n,l)+1,recurse(a,b,c+1,n,l));
}
}
int main()
{
std::ios_base::sync_with_stdio(false);
int t;
cin>>t;
for(int k=1;k<=t;k++)
{
int n,l;
cin>>n>>l;
string a[n],b[n];
for(int i=0;i<n;i++)
{
cin>>a[i];
}
for(int i=0;i<n;i++)
cin>>b[i];
int ans=recurse(a,b,0,n,l);
if(ans>l)cout<<"Case #"<<k<<": "<<"NOT POSSIBLE"<<endl;
else cout<<"Case #"<<k<<": "<<ans<<endl;
}
return 0;
}
