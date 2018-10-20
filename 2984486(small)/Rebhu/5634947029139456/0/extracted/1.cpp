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
pair<bool,int> recur(vector< vector<char> > o,vector< vector<char> > g,int p,int c)
{
//   printf("Pos: %d\n",p);
//   print(o);
  if(p==l-1)
  {
    sort(o.begin(),o.end());
    //without flip
    bool x=true;
    For(i,0,n)
    {
      For(j,0,l)
	x = (x && (o[i][j]==g[i][j]));
    }
    if(x)
      return make_pair(x,c);
    //with flip
    For(i,0,n)
    {
      if(o[i][p]=='0')
	o[i][p]='1';
      else
	o[i][p]='0';
    }
    sort(o.begin(),o.end());
//     print(o);
    x=true;
    For(i,0,n)
    {
      For(j,0,l)
	x = (x && (o[i][j]==g[i][j]));
    }
    For(i,0,n)
    {
      if(o[i][p]=='0')
	o[i][p]='1';
      else
	o[i][p]='0';
    }
    return make_pair(x,c+1);
  }
  pair<bool,int> r = recur(o,g,p+1,c);
  if(r.first)//without flip
    return r;
  else //with flip
  {
    For(i,0,n)
    {
      if(o[i][p]=='0')
	o[i][p]='1';
      else
	o[i][p]='0';
    }
    r = recur(o,g,p+1,c+1);
    //back to original
    For(i,0,n)
    {
      if(o[i][p]=='0')
	o[i][p]='1';
      else
	o[i][p]='0';
    }
    return r;
  }
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
	scanf("%c",&gadget[i][j]);
      char c;
      scanf("%c",&c);
    }
    sort(gadget.begin(),gadget.end());
    pair<bool,int> r = recur(outlet,gadget,0,0);
    printf("CASE #%d: ",(t+1));
    if(r.first)
      printf("%d\n",r.second);
    else
      printf("NOT POSSIBLE\n");
  }
}