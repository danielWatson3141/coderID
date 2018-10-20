#include<iostream>
#include<set>
using namespace std;
int main()
{
int t;
cin>>t;
for(int k=1;k<=t;k++)
{
int n;
cin>>n;
set<double> a,b,c,d;
for(int i=0;i<n;i++)
{
double temp;
cin>>temp;
a.insert(temp);
c.insert(temp);
}
for(int i=0;i<n;i++)
{
double temp;
cin>>temp;
b.insert(temp);
d.insert(temp);
}
int count=0;
set<double>::iterator it;
it=a.begin();
while(!a.empty())
{
it=a.begin();
if(*(b.begin())<=*it)
{
b.erase(b.begin());
a.erase(it);
count++;
}
else
{
b.erase(--b.end());
a.erase(it);
}
}
int count1=0;
while(!c.empty())
{
it=c.begin();
if(d.upper_bound(*it)!=d.end())
d.erase(d.upper_bound(*it));
else 
{d.erase(d.begin());count1++;}
c.erase(it);
}
cout<<"Case #"<<k<<": "<<count<<" "<<count1<<endl;
}
return 0;
}
