#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define gi(a) scanf("%d",&a)
#define gd(a) scanf("%llf",&a)
#define For(i,lb,ub) for(int i=lb;i<ub;i++)
int n,l;
void print(vector< vector<char> > o)
{
  For(i,0,n)
  {
    For(j,0,l)
      cout<<o[i][j];
    cout<<" ";
  }
  cout<<endl;
}
bool matches(vector< vector<char> > o,vector< vector<char> > g,int p)
{
  bool x=true;
  For(i,0,n)
    x = (x && (o[i][p]==g[i][p]));
  return x;
}
void flip(vector< vector<char> > o, int p)
{
   
}
int main()
{
  int T;
  gi(T);
  For(t,0,T)
  {
    
    gi(n);
    gi(l);
//     cout<<"CASE"<<t<<endl;
    vector< vector<char> > outlet(n, vector<char> (l+1));
    For(i,0,n)
    {
      For(j,0,l)
      {
	cin>>outlet[i][j];//scanf("%c",&outlet[i][j]);
// 	printf("%c",outlet[i][j]);
      }
      char c;
      scanf("%c",&c);
//       printf("\n");
    }
    vector< vector<char> > gadget(n, vector<char> (l+1));
    For(i,0,n)
    {
      For(j,0,l)
	cin>>gadget[i][j];
      char c;
      scanf("%c",&c);
    }
    sort(gadget.begin(),gadget.end());
    sort(outlet.begin(),outlet.end());
    int count=0;
    bool pos=true;
    For(j,0,l)
    {
      if(matches(outlet,gadget,j))
	continue;
      For(i,0,n)
      {
	if(outlet[i][j]=='0')
	  outlet[i][j]='1';
	else
	  outlet[i][j]='0';
      }
      count++;
      sort(outlet.begin(),outlet.end());
      if(matches(outlet,gadget,j))
	continue;
      else
      {
	pos=false;
	break;
      }
    }
    printf("CASE #%d: ",(t+1));
    if(pos)
      printf("%d\n",count);
    else
      printf("NOT POSSIBLE\n");
  }
}