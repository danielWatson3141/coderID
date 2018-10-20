#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;


const int MAXn=1000+17;
vector <int> tree[MAXn];
int n;
int cost[MAXn];
bool mark[MAXn];
int tedad[MAXn];


void clr2()
{
  for(int i=0;i<MAXn;i++)
    {
      cost [i] =0;
      mark[i]= 0;
      tedad[i]= 0;
    }
}

void clr()
{
  for(int i=0;i<MAXn;i++)
    {
      cost[i]=0;
      tree[i].clear();
    }
}

void DFS(int u)
{
  int max1=-1;
  int max2=-1;
  mark[u]=1;
  for(int i=0;i<tree[u].size();i++)
    {
      if(mark[tree[u][i]]==0)
	{
	  DFS(tree[u][i]);
	  tedad[u]+=tedad[tree[u][i]];
	  cost[u]+=tedad[tree[u][i]];
	  if(tedad[tree[u][i]]-cost[tree[u][i]]>max1)
	    {
	      max2=max1;
	      max1=tedad[tree[u][i]]-cost[tree[u][i]];
	    }
	  else
	    {
	      if(tedad[tree[u][i]]-cost[tree[u][i]]>max2)
		{
		  max2=tedad[tree[u][i]]-cost[tree[u][i]];
		}
	    }
	}
    }
  if(max2!=-1)
    cost[u]-=max1+max2;
  tedad[u]++;
}



int main()
{
  ios::sync_with_stdio(false);
  int t;
  cin>>t;
  for(int I=1;I<=t;I++)
    {
      clr();
      cin>>n;
      for(int i=0;i<n-1;i++)
	{
	  int u,v;
	  cin>>u>>v;
	  u--;
	  v--;
	  tree[u].push_back(v);
	  tree[v].push_back(u);
	}
      int minimum =MAXn;
      for(int i=0;i<n;i++)
	{
	  clr2();
	  DFS(i);/*
	  for(int j=0;j<n;j++)
	    {
	      cerr<<"tedad ["<<j<<"] = "<<tedad[j]<<endl;
	      cerr<<"cost ["<<j<<"] = "<<cost[j]<<endl;
	    }
	    cerr<<"for "<<i<<" is "<<minimum<<endl;*/
	  if(cost[i]<minimum)
	    minimum=cost[i];
	}
      cout<<"Case #"<<I<<": "<<minimum<<endl;
    }
  return 0;
}
