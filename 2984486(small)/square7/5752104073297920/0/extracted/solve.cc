#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<double> > tab;

void gen()
{
  for(int i = 0; i < 1000; ++i)
    {
      vector<double> temp(1000,0);
      temp[i]=1;
      for(int j = 0; j < 1000; ++j)
	{
	  vector<double> newTemp(1000,0);
	  for(int k = 0; k < 1000; ++k)
	    {
	      if(j==k)
		{
		  newTemp[j]=0.001;
		}
	      else
		{
		  newTemp[k]=.999*temp[k]+.001*temp[j];
		}
	    }
	  temp=newTemp;
	}
      tab.push_back(temp);
    }
  /*  for(int i = 0; i < tab.size(); ++i)
    {
      for(int j = 0; j < tab[0].size(); ++j)
	{cerr << tab[i][j] << " ";}
      cerr << endl;
      }*/
}

int main()
{
  int tot;
  cin >> tot;
  gen();
  for(int i = 0; i < tot; ++i)
    {
      int N;
      cin >> N;
      vector<int> vec(N);
      for(int j = 0; j < N; ++j)
	{cin >> vec[j];}
      double fac=1;
      for(int j = 0; j < N; ++j)
	{
	  fac*=1.0*tab[vec[j]][j]*N;
	}
      cout << "Case #" << i+1 << ": ";
      if(fac>1)
	{cout << "BAD" << endl;}
      else
	{cout << "GOOD" << endl;}
    }
}
