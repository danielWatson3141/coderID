#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

typedef long long int ll;


int main()
{
	vector<long long int> ans;
	int t;
	cin>>t;
	while (t--)
	{
		int n;
		cin>>n;
		int flag = 0;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			if(a == i)
				flag = 1;
		}
		ans.push_back(flag);
	}

	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": ";
		if(ans[i])
			cout<<"BAD"<<endl;
		else
			cout<<"GOOD"<<endl;
	}
}