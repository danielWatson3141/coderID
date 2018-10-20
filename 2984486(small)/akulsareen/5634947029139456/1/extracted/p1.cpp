#include <vector>
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
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
using namespace std;
string XOR(string a,string b)
{
	string ans="";
	for (int i = 0; i < a.length(); ++i)
	{
		if(a[i]==b[i])
			ans+='0';
		else
			ans+='1';
	}
	return ans;
}
int one_count(string x)
{
	int ans=0;
	for (int i = 0; i < x.length(); ++i)
	{
		if(x[i]=='1')
			ans++;
	}
	return ans;
}
int main()
{
	freopen("al.in","r",stdin);
	freopen("a_large.out","w",stdout);
	int t;
	cin>>t;
	for (int test_case = 1; test_case <= t; ++test_case)
	{
		int n,l;
		cin>>n>>l;
		vector <string> A(n),reqd(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];
		}
		for (int i = 0; i < n; ++i)
		{
			cin>>reqd[i];
		}
		sort(reqd.begin(), reqd.end());
		int ans=10000000;
		for (int i = 0; i < n; ++i)
		{
			string key=XOR(reqd[0],A[i]);
			vector <string> temp;
			for (int j = 0; j < n; ++j)
			{
				temp.push_back(XOR(A[j],key));
			}
			sort(temp.begin(), temp.end());
			if(temp==reqd)
			{
				ans=min(ans,one_count(key));
			}
		}
		if(ans<10000)
			printf("Case #%d: %d\n",test_case,ans);
		else
			printf("Case #%d: NOT POSSIBLE\n",test_case);
	}
	return 0;
}