#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int solve(vector<string> init, vector<string> vec, int pos, int f)
{
  sort(init.begin(), init.end());
  sort(vec.begin(), vec.end());
  for(int i = 0; i < init.size(); ++i)
    {
      for(int j = 0; j < pos; ++j)
	{
	  if(vec[i][j]!=init[i][j])
	    {return -1;}
	}
    }
  if(pos==init[0].size())
    {return f;}
  int c1=0, c2=0;
  for(int i = 0; i < init.size(); ++i)
    {
      if(init[i][pos]=='1') {++c1;}
      if(vec[i][pos]=='1') {++c2;}
    }
  int ans=-1;
  if(c1==c2)
    {
      int trail=solve(init, vec, pos+1, f);
      if(trail!=-1 && (ans==-1 || ans>trail))
	{ans=trail;}
    }
  if(c1==init.size()-c2)
    {
      for(int i = 0; i < init.size(); ++i)
	{
	  if(init[i][pos]=='1')
	    {init[i][pos]='0';}
	  else
	    {init[i][pos]='1';}
	}
      int trail=solve(init, vec, pos+1, f+1);
      if(trail!=-1 && (ans==-1 || ans>trail))
	{ans=trail;}
    }
  return ans;
}

int main()
{
  int tot;
  cin >> tot;
  for(int i = 0; i < tot; ++i)
    {
      int N, L;
      cin >> N >> L;
      vector<string> init;
      vector<string> vec;
      for(int j = 0; j < N; ++j)
	{
	  string str;
	  cin >> str;
	  init.push_back(str);
	}
      for(int j = 0; j < N; ++j)
	{
	  string str;
	  cin >> str;
	  vec.push_back(str);
	}
      /*      vector<int> iniCnt(L,0), cnt(L,0);
      for(int j = 0; j < L; ++j)
	{
	  for(int k = 0; k < N; ++k)
	    {
	      if(vec[k][j]=='1')
		{cnt[j]++;}
	      if(init[k][j]=='1')
		{iniCnt[j]++;}
	    }
	    }*/
      int flip=solve(init, vec, 0, 0);
      cout << "Case #" << i+1 << ": ";
      if(flip==-1)
	{cout << "NOT POSSIBLE" << endl;}
      else
	{
	  cout << flip << endl;
	}
    }
}
