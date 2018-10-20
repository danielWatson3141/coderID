#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>
#include <math.h>


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
	int n,v,t;
	char c;
    int N,L;
	//long double c,f,x,t,sum,oldt,oldsum,mmm;
	int mm;
    //bool flag;
	ifstream fin("e:\\A-small-attempt0.in");
	ofstream fout("e:\\8.txt");


	fin>>n;

	for (int ca=0;ca<n;ca++)
	{
	  mm=100;
	  fin>>N>>L;
	  long long arr1[N];
	  long long arr2[N];
	  long long arr3[N];
	  for (int j=0;j<N;j++)
	  {
		  arr1[j]=0;
		  for (int k=0;k<L;k++)
		  {
			  fin>>c;
			  //cout<<c<<endl;
			  v=c-'0';
			  arr1[j]=v+arr1[j]*2;
		  }
		  //fin>>c;
	  }
	  for (int j=0;j<N;j++)
	  {
		  arr2[j]=0;
		  for (int k=0;k<L;k++)
		  {
			  fin>>c;
			  //cout<<c<<endl;
			  v=c-'0';
			  arr2[j]=v+arr2[j]*2;
		  }
		//  fin>>c;
	  }

	  sort(arr2,arr2+N);

	  for (long long bit=0;bit<( 1<< L ); bit++)
	  {
		  for (t=0;t<N;t++)
			  arr3[t]=arr1[t];

		  for (int j=0;j<N;j++)
			  arr3[j]=arr3[j]^bit;

		  sort(arr3,arr3+N);

		  //flag=true;
		  for (t=0;t<N;t++)
			  if (arr3[t]!=arr2[t])
			  {
				  break;
			  }
		  if (t==N)
		  {
			  mm=min(getbit(bit),mm);
		  }


	  }
      if (mm==100)
    	  fout<<"Case #"<<ca+1<<": "<<"NOT POSSIBLE"<<endl;
      else
    	  fout<<"Case #"<<ca+1<<": "<<mm<<endl;
/*
	 // mmm=cal(c,f,x);
	  cout<<mmm<<endl;
	  //fout.setf(std::out.showpoint);
	  fout.precision(9);
	  fout.setf(ios::fixed);
	  fout<<"Case #"<<ca+1<<": "<<oldsum<<endl;
*/
	}

	return 0;
}
