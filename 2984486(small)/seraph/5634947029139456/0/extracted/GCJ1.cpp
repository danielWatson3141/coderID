#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <stdio.h>

using namespace std;

int main()
{
	int tc;
	cin>>tc;
	int count=1;
	while (tc--)
	{
		int n,l;
		cin>>n>>l;
		vector<string> v1, v2, v3, v4;
		
		string s;
		for (int i=0;i<n;i++)
		{
			cin>>s;
			v1.push_back(s);
			v3.push_back(s);
		}
		for (int i=0;i<n;i++)
		{
			cin>>s;
			v2.push_back(s);
			v4.push_back(s);
		}
		bool ada = false;
		int ans = 10000000;
		
		for (int i=0;i<n;i++)
		{
			
			string temp1 = v1[i];
			string temp2 = v2[0];
			vector<int> tmp;
			for (int j=0;j<l;j++)
			{
				if (temp1[j] == temp2[j]){
				}
				else
				{
					tmp.push_back(j);
				}
			}
			
			/*cout<<endl<<endl;
			for (int j=0;j<tmp.size();j++) cout<<tmp[j]<<",";
			cout<<endl;*/
			
			for (int j=0;j<tmp.size();j++)
			{
				for (int k=0;k<n;k++)
				{
					if (v3[k][tmp[j]] == '0') v3[k][tmp[j]]='1';
					else v3[k][tmp[j]] = '0';
				}
			}
			
			
			bool sudah1[n], sudah2[n];
			for (int j=0;j<n;j++) {
				sudah1[j]=0;
				sudah2[j]=0;
			}
			
			/*)for (int j=0;j<n;j++) cout<<v3[j]<<" ";
			cout<<endl;
			for (int j=0;j<n;j++) cout<<v4[j]<<" "; 
			cout<<endl;*/
			
			
			for (int j=0;j<n;j++)
			{
				for (int k=0;k<n;k++)
				{
					if (v3[j] == v4[k] && sudah1[j]==0 && sudah2[k]==0)
					{
						sudah1[j] = 1;
						sudah2[k] = 1;
					}
				}
			}
			
			bool salah = false;
			for (int j=0;j<n;j++)
			{
				if (sudah1[j]==0) salah=true;
				if (sudah2[j]==0) salah=true;
			}
			
			if (salah==false)
			{
				ada=true;
				int t = tmp.size();
				ans = min(ans, t);
			}
			
			for (int j=0;j<tmp.size();j++)
			{
				for (int k=0;k<n;k++)
				{
					if (v3[k][tmp[j]] == '0') v3[k][tmp[j]]='1';
					else v3[k][tmp[j]] = '0';
				}
			} 
		}
		
		cout<<"Case #"<<count++<<": ";
		if (ada) cout<<ans<<endl;
		else cout<<"NOT POSSIBLE"<<endl;
	}
	return 0;
}

