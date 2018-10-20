#include <algorithm>  
#include <bitset>  
#include <cctype>  
#include <cmath>  
#include <complex>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <ctime>  
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <fstream>
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>   
using namespace std;

ifstream ifile;
ofstream ofile;

int T,cases;

string outlets[151],needs[151];

int N, L;

int check(string a, string b)
{
	string tmp[151];
	for(int i = 0; i < N; i++)
		tmp[i]=outlets[i];

	int res = 0;
	for(int i = 0; i < L ; i++)
	{
		if(b[i]!=a[i])
		{
			res++;
			for(int j = 0; j < N; j++)
			{
				if(tmp[j][i]=='0')tmp[j][i]='1';
				else tmp[j][i]='0';
			}
		}
	}
	sort(tmp,tmp+N);

	for(int i = 0; i < N; i++)
	{
		if(tmp[i]!=needs[i])return 1000000;
	}
	return res;
}

void solve()
{
	ifile>>N>>L;
	for(int i = 0; i < N; i++)
	{
		ifile>>outlets[i];
	}
	for(int i = 0; i < N; i++)
	{
		ifile>>needs[i];
	}

	sort(needs,needs+N);

	int res = 1000000;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			res = min(res,check(needs[i],outlets[j]));
		}
	}

	if(res==1000000)
		ofile<<"Case #"<<cases<<": "<<"NOT POSSIBLE"<<endl;
	else
		ofile<<"Case #"<<cases<<": "<<res<<endl;
}

int main(void)
{
	ifile.open("input.txt");
	ofile.open("output.txt");

	ifile>>T;
	for(int i = 0; i < T; i++)
	{
		cases=i+1;
		solve();
	}

	ifile.close();
	ofile.close();
	return 0;
}