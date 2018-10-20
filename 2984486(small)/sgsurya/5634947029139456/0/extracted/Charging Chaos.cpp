#include <iostream>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>

using namespace std;

bool check(vector<string> values,vector<string> req,int a,int b)
{
	string temp1 = values[b];
	string temp2 = req[a];
	vector<int> cv;
	for(int i=0;i<temp1.length();i++)
	{
		if(temp1[i]!=temp2[i])
			cv.push_back(i);
	}
	for(int i=0;i<cv.size();i++)
	{
		for(int j=0;j<values.size();j++)
		{
			if(values[j][cv[i]]=='0')
				values[j][cv[i]]='1';
			else
				values[j][cv[i]]='0';
		}
	}
	vector<bool> che(req.size()),che2(req.size());
	for(int i=0;i<req.size();i++)
	{
		for(int j=0;j<values.size();j++)
		{
			if(req[i]==values[j] && !che2[j])
			{
				che[i]=true;
				che2[j]=true;
			}
		}
	}
	for(int i=0;i<req.size();i++)
	{
		if(!che[i])
			return false;
	}
	return true;
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	int t;
	cin>>t;
	for(int caset=1;caset<=t;caset++)
	{
		int n,l;
		cin>>n>>l;
		vector<string> values(n),req(n);
		vector<int> che(n,0),che1(n,0);
		for(int i=0;i<n;i++)
			cin>>values[i];
		for(int i=0;i<n;i++)
			cin>>req[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(req[i]==values[j] && che1[j]==0)
				{
					che[i]=1;
					che1[i]=1;
					break;
				}
			}
		}
		int ans_steps=INT_MAX;
		for(int i=0;i<n;i++)
		{
			if(che[i]==0)
			{
				int loc=0,mx=-1;
				for(int j=0;j<n;j++)
				{
					int dist=0;
					string temp = req[i];
					for(int k=0;k<l;k++)
					{
						if(req[i][k]!=values[j][k])
						{
							dist++;
						}
					}
					bool ans = check(values,req,i,j);
					if(ans)
					{
						ans_steps = min(ans_steps,dist);
					}
				}
			}
		}
		if(ans_steps==INT_MAX)
			cout << "Case #" << caset << ": " << "NOT POSSIBLE\n";
		else
			cout << "Case #" << caset << ": " << ans_steps << "\n";
	}
	return 0;
}