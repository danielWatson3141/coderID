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
		vector<string> v;
		set<string> s;
		string str;
		int n,l;
		int minval = 200;
		cin>>n>>l;
		for(int i=0;i<n;i++)
		{
			cin>>str;
			v.push_back(str);
		}
		for(int i=0;i<n;i++)
		{
			cin>>str;
			s.insert(str);
		}
		for(int i=0;i<n;i++)
		{
			string curr = v[i];
			string des = *(s.begin());
			vector<int> changeBit;
			for(int j=0;j<des.size();j++)
				if(curr[j] != des[j])
					changeBit.push_back(j);

			int count = 0;
			
			for(int j=0;j<n;j++)
			{
				string temp = v[j];
				
				for(int k=0;k<changeBit.size();k++)
				{
					temp[changeBit[k]] = (temp[changeBit[k]] == '0')?'1':'0';
				}
				if(s.find(temp) != s.end())
					count++;
			}
			if(count == n)
			{
				if(changeBit.size() < minval)
					minval = changeBit.size();
			}
		}
		ans.push_back(minval);
		// cout<<t<<" "<<minval<<endl;
	}

	for(int i=0; i<ans.size();i++)
	{
		cout<<"Case #"<<i+1<<": ";
		if(ans[i]<200)
			cout<<ans[i]<<endl;
		else
			cout<<"NOT POSSIBLE"<<endl;
	}
}