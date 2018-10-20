#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>

using namespace std;

int bit2int(int L)
{
  vector<int> bi;
  int out = 0;
  for (int i = 0; i < L; i++)
    {
      char temp;
      cin>>temp;
      if (temp == '1')
	bi.push_back(1);
      else
	bi.push_back(0);
    }
  for (int i = 0; i < L; i++)
    {
      out = out * 2 + bi[i];
    }
  return out;
}

int numbit(int in)
{
  int out = 0;
  while (in)
    {
      int temp = in;
      temp = temp>>1;
      temp = temp<<1;
      out += in ^ temp;
      in = in>>1;
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

      int N,L;
      cin>>N>>L;
      vector<int> socket;
      vector<int> plug;
      int best = L+1;
      for (int i = 0; i < N; i++)
	{
	  socket.push_back(bit2int(L));
	}
      for (int i = 0; i < N; i++)
	{
	  plug.push_back(bit2int(L));
	}
      for (int i = 0; i < N; i++)
	{
	  int code = plug[i] ^ socket[0];
	  bool work = true;
	  for (int j = 1; j < N; j++)
	    {
	      bool none = false;
	      for (int k = 0; k < N; k++)
		{
		  if ((socket[j] ^ code) == plug[k])
		    break;
		  else if (k == N-1)
		    none = true;
		}
	      if (none)
		{
		  work = false;
		  break;
		}
	    }
	  if (work && numbit(code) < best)
	    best = numbit(code);
	}
      if (best == L+1)
	cout<<"NOT POSSIBLE"<<endl;
      else
	cout<<best<<endl;
    }
  return 0;
}
