#include <vector>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cmath>
#include<fstream>
#include <ctime>
#include<string>
using namespace std;

set<int> sets;

int checkEqual(vector<string> ini, vector<string> fina, int N)
{
	for(int i=0; i<N; i++)
	{
		if(find(fina.begin(), fina.end(), ini[i]) == fina.end() )
			return 0;
	}
	return 1;
}

void changeBits(vector<string> ini, vector<string> fina,int N, int L, int bitNum,int min)
{
	
	if( bitNum == L )
	{
		if(checkEqual(ini,fina,N) == 1)
			sets.insert(min);
		return;
	}
	else if(checkEqual(ini,fina,N) == 1)
	{
		sets.insert(min);
		return;
	}
	else
	{
		for(int i=bitNum; i<L; i++)
		{
			vector<string> ini2 = ini;
			for(int j=0; j<N; j++)
				if(ini2[j][i] == '1')
					ini2[j][i] = '0';
				else
					ini2[j][i] = '1';
			
			changeBits(ini2,fina,N,L,i+1,min+1);
		}
	}
	return;
}

int solve(vector<string> ini, vector<string> fina, int N, int L)
{
	int min = -1;

	for(int j=0; j<L; j++)
	{
		int temp =-1;
		sets.clear();
		changeBits(ini,fina,N,L,j,0);
		if(sets.size() != 0)
			temp = *(sets.begin());
		if(temp != -1)
			if(min == -1)
				min = temp;
			else if( temp < min )
				min = temp;
	}

	return min;
}



int main()
{
	ifstream fin ("A-small-attempt0.in");
	ofstream fout ("out.out");
	if(!fin)
		return 1;

	int N,L,T;

	fin>>T;

	if(T<1 || T>100)
		return 1;

	for(int i=0; i<T; i++)
	{
		fin>>N;
		if(N<1 || N>10)
			return 1;

		fin>>L;
		if(L<2 || L>10)
			return 1;

		vector<string> ini;

		for(int i=0; i<N; i++)
		{
			string n;
			fin>>n;
			
			if(find(ini.begin(), ini.end(),n) == ini.end())
			{
				ini.push_back(n);
			}
			else
				return 1;
		}

		vector<string> fina;

		for(int i=0; i<N; i++)
		{
			string n;
			fin>>n;
			
			if(find(fina.begin(), fina.end(),n) == fina.end())
			{
				fina.push_back(n);
			}
			else
				return 1;
		}
		fout<<"Case #" <<i+1<<": ";
		int n = solve(ini,fina,N,L);
		if(n == -1)
			fout<<"NOT POSSIBLE"<<endl;
		else
			fout<<n<<endl;
	}

	return 0;
}