#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define gi(a) scanf("%d",&a)
#define gd(a) scanf("%llf",&a)
#define For(i,lb,ub) for(int i=lb;i<ub;i++)
int main()
{
  int T;
  gi(T);
  For(t,1,T+1)
  {
    int n;
    gi(n);
    vector< vector<int> > e(n+5);
    For(i,0,n-1)
    {
      int a,b;
      gi(a);
      gi(b);
      e[a].push_back(b);
      e[b].push_back(a);
    }
    int mini = 1500;
//     cout<<"CASE: "<<endl;
    For(i,1,n+1)
    {
      //root is i
//       cout<<"i:"<<i<<endl;
      vector<bool> done(n+5,false);
      queue<int> q;
      done[i]=true;
      q.push(i);
      int count=0;
      while(!q.empty())
      {
	int v = q.front();
// 	printf("%d %d\n",v,count);
	q.pop();
	count++;
	int c=0;
	vector<int> ins;
	For(j,0,e[v].size())
	{
	  if(!done[e[v][j]])
	  {
	    ins.push_back(e[v][j]);
	    c++;
	  }
	  if(c==2)
	    break;
	}
	if(ins.size() == 2)
	{
	  done[ins[0]]=done[ins[1]]=true;
	  q.push(ins[0]);
	  q.push(ins[1]);
	}
      }
      mini=min(mini,n-count);
//       cout<<endl;
    }
    printf("CASE #%d: %d\n",t,mini);
  }
}