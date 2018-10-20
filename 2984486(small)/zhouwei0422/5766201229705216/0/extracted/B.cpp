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

vector< vector<int> > v(1001);

int N;

int memo[1001][1001];

int check(int a, int b)
{
	if(memo[a][b]!=-1)return memo[a][b];
	queue<int> q;
	vector<int> t;
	for(int i = 0; i < v[b].size(); i++)
	{
		if(v[b][i]!=a)
			t.push_back(check(b,v[b][i]));
	}
	sort(t.rbegin(),t.rend());

	if(t.size()==0||t.size()==1)return memo[a][b]=1;
	else return memo[a][b]=1+t[0]+t[1];
}

void solve()
{
	for(int i = 0; i <1001; i++)
		v[i].clear();

	memset(memo,-1,sizeof(memo));
	ifile>>N;
	for(int i = 0; i <N-1; i++)
	{
		int x,y;
		ifile>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}


	int res = 0;
	for(int i = 1; i<=N; i++)
	{
		int sum = 0;
		vector<int> t;
		for(int j = 0; j < v[i].size(); j++)
		{
			t.push_back(check(i,v[i][j]));
		}

		if(t.size()==0||t.size()==1)sum=1;
		else sum=1+t[0]+t[1];
		
		res = max(res,sum);

	}

	ofile<<"Case #"<<cases<<": "<<N-res<<endl;
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