#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
#include <math.h>
#include <vector>


using namespace std;


int getbit(long long num)
{
	int count=0;
	while (num)
	{
		num=num&(num-1);
		count++;
	}
	return count;
}

int main()
{
	int n,v,t,a;
	long long bbb;
	char c;
    int m,N,L;
	//long double c,f,x,t,sum,oldt,oldsum,mmm;
	int mm;
	vector <pair<int, int> > ss;
    //bool flag;
	ifstream fin("e:\\C-small-attempt0.in");
	ofstream fout("e:\\C-small-attempt0.out");


	fin>>n;

	for (int ca=0;ca<n;ca++)
	{
      fin>>m;
      int score=0;
	  for (int j=0;j<m;j++)
	  {
        fin>>a;
        score+=abs(a-j);
	  }

	  ss.push_back(pair<int,int>(score,ca));

	  std::sort(ss.begin(),ss.end());

	  /*
		  if (mm==100)
    	    fout<<"Case #"<<ca+1<<": "<<"BAD"<<endl;
          else
    	    fout<<"Case #"<<ca+1<<": "<<"GOOD"<<endl;*/
/*
	 // mmm=cal(c,f,x);
	  cout<<mmm<<endl;
	  //fout.setf(std::out.showpoint);
	  fout.precision(9);
	  fout.setf(ios::fixed);
	  fout<<"Case #"<<ca+1<<": "<<oldsum<<endl;
*/
	}
	  set<int> sss;
	  for (int j=0;j<60;j++)
		  sss.insert(ss[j].second);
		for (int ca=0;ca<n;ca++)
		{

			if (sss.find(ca)!=sss.end())
					{
				fout<<"Case #"<<ca+1<<": "<<"BAD"<<endl;

					}
			else
				fout<<"Case #"<<ca+1<<": "<<"GOOD"<<endl;
		}
	return 0;
}
