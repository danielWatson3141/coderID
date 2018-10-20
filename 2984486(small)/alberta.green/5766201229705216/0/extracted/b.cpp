#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;


bool edge[1000][1000];
int trim;

int mktree(int node, int parent, int N)
{
  //cout<<"depth"<<endl;
  int out = 1;
  int children = 0;
  int buffer1 = 0;
  int buffer2 = 0;
  vector<int> chi;
  for (int i = 0; i < N; i++)
    {
      if (edge[node][i] && parent != i)
	{
	  chi.push_back(i);
	  children++;
	  //cout<<"children"<<i<<" ";
	}
    }
  if (children == 0)
    return 1;
  else if (children == 1)
    {
      trim += mktree(chi[0], node, N);
      return 1;
      //cout<<"mark "<< mktree(chi[0], node, N);
    }
  else 
    for (int i = 0; i < chi.size(); i++)
      {
	int temp = mktree(chi[i], node, N);
	out += temp;
	if (temp < buffer1)
	  {
	    trim += temp;
	    out -= temp;
	    //cout<<"mark"<<temp;
	  }
	else if (temp < buffer2)
	  {
	    out -= buffer1;
	    trim += buffer1;
	    buffer1 = temp;
	    //cout<<"mark"<<buffer1;
	  }
	else
	  {
	    out -= buffer1;
	    trim += buffer1;
	    buffer1 = buffer2;
	    buffer2 = temp;
	    //cout<<"mark"<<buffer1;
	  }
      }
  return out;
}

int main()
{
  int T;
  int x = 0;
  cin>>T;
  while(++x&&(T-x+1))
    {
      cout<<"CASE #"<<x<<": ";
      int N;
      cin>>N;
      for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	  edge[i][j] = false;

      for (int i = 0; i < N-1; i++)
	{
	  int a, b;
	  cin>>a>>b;
	  edge[a-1][b-1] = true;
	  edge[b-1][a-1] = true;
	}

      int best = N;
      for (int i = 0; i < N; i++)
	{
	  trim = 0;
	  mktree(i, -1, N);
	  if (trim < best)
	    best = trim;
	  //cout<<"mark"<<trim<<endl;
	}
      cout<<best<<endl;
    }
  return 0;
}
