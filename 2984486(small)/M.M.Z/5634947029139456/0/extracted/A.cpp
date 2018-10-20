#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;

int n,l;
vector<string> sw;
vector <string> device;
int minimum = 1000;

void ax(int i,int j)
{
  if(sw[j][i]=='1')
    sw[j][i]='0';
  else
    sw[j][i]='1';
}

bool tasavi()
{
  for(int i=0;i<n;i++)
    if(sw[i]!=device[i])
      return 0;
  return 1;
}


void check(int p)
{
  int x=p;
  int tedad=0;
  for(int i=0;i<l;i++)
    {
      if(x%2)
	{
	  tedad++;
	  for(int j=0;j<n;j++)
	    ax(i,j);
	}
      x/=2;
    }
  sort(sw.begin(),sw.end());
  if(tasavi() && minimum >tedad)
    minimum =tedad;
  x=p;
  for(int i=0;i<l;i++)
    {
      if(x%2)
	{
	  tedad++;
	  for(int j=0;j<n;j++)
	    ax(i,j);
	}
      x/=2;
    }
}


int main()
{
  int t;
  ios::sync_with_stdio(false);
  cin>>t;
  for(int I=1;I<=t;I++)
    {
      sw.clear();
      device.clear();
      minimum =1000;
      cin>>n>>l;
      for(int i=0;i<n;i++)
	{
	  string x;
	  cin>>x;
	  sw.push_back(x);
	}
      for(int i=0;i<n;i++)
	{
	  string x;
	  cin>>x;
	  device.push_back(x);
	}
      sort(device.begin(),device.end());
      for(int i=0;i<(1<<l);i++)
	{
	  check(i);
	}
      if (minimum<1000)
	cout<<"Case #"<<I<<": "<<minimum<<endl;
      else
	cout<<"Case #"<<I<<": NOT POSSIBLE"<<endl;
    }
  return 0;
}
