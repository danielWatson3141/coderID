#include<iostream>
#include<vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>
#include<string.h>
#include <iomanip>
#include <cstdio>
#include<math.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ull unsigned long long 
#define ll long long int
#define pi 3.141592653589793
#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])
#define PB push_back
#define INF 1<<30
using namespace std;
ull count(ull y)
{
	ull c =0;
	while(y!=0)
	{
		if(y%2 ==1)
		c++;
		y=y/2;
	}
	return c;
}
bool check(vector<string>temp,map<string,bool>out)
{
		bool bt = true;
			for(int i =0;i<temp.size() && bt;i++)
			{
				if(out.find(temp[i]) ==out.end())
				bt =false;
			}
			return bt;
}
vector<string> transform(vector<string>x,vector<ull>arr)
{
	for(int i =0;i<arr.size();i++)
	{
		if(arr[i] == 1)
		{
			for(int k =0;k<x.size();k++)
			{
				string g = x[k];
				if(g[i] =='1')
				x[k][i] ='0';
				else
				x[k][i] ='1';
			}
		}
	}
	return x;
}
int main()
{
	int n =0;

	ull tc =1;
	cin>>n;
	
	while(n--)
	{
		ull a,b;
		cin>>a>>b;
		
		vector<string>inp;
		map<string,bool>out;
	
		for(ull i =0;i<a;i++)
		{
			string x;
			cin>>x;
			inp.PB(x);
		}
		for(ull i =0;i<a;i++)
		{
			string x;
			cin>>x;
			out[x] = true;
		}
		
		ull ans =INF;
		for(ll i =0;i<(1<<b);i++)
		{
			vector<string>temp = inp;
			vector<ull>arr(inp[0].size());
			fill(arr.begin(),arr.end(),0);ull k =inp[0].size()-1;
			int y =i;
			while(y!=0)
			{
				arr[k--] =y%2;
				y=y/2;
			}
			vector<string> hh = transform(temp,arr);
			if(check(hh,out) && ans>count(i))
			{
				ans =count(i);
			}
		}	
		cout<<"Case #"<<tc++<<": ";
		if(ans ==INF)
		cout<<"NOT POSSIBLE"<<endl;
		else
		cout<<ans<<endl;
	}
	return 0;
}