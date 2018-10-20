#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
vector<bool> flow[150];
vector<bool> dev[150];
vector<bool> newflow[150];
bool comp(const vector<bool>& A, const vector<bool>&B)
{
	for (int i=0;i<A.size();i++)
	{
		if (A[i]!=B[i]) return (A[i]==false);
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	for (int x=1;x<=t;x++)
	{
		int n,L;
		cin >> n >> L;
		string s;
		getline(cin, s);
		for (int i=0;i<n;i++)
		{
			flow[i].clear();
			cin >> s;
			//vector<bool> V;
			for (int j=0;j<L;j++)
			{
				flow[i].push_back((s[j]=='1'));
				
			}
			
			
		}
		for (int i=0;i<n;i++)
		{
			dev[i].clear();
			cin >> s;
			//vector<bool> V;
			for (int j=0;j<L;j++)
			{
				dev[i].push_back((s[j]=='1'));
				
			}
			
			
		}
		sort(dev,dev+n,comp);
		
		int best=L+1;
		for (int f=0;f<n;f++)
		{
			for (int j=0;j<n;j++)
				newflow[j]=vector<bool>(flow[j]);
			int c=0;
			for (int i=0;i<L;i++)
			{
				if (dev[f][i]!=newflow[0][i])
				{
					c++;
					for (int j=0;j<n;j++)
						newflow[j][i]=(!newflow[j][i]);
				}
			}
			sort(newflow,newflow+n,comp);
			bool ok=true;
			for (int j=0;j<n;j++)
			{
				for (int i=0;i<L;i++)
				{
					if (newflow[j][i]!=dev[j][i])
					{
						ok=false;
						break;
					}
				}
				if (!ok) break;
			}
			if (ok) best=min(best,c);
		}
		if (best<=L)
			cout << "Case #" << x << ": " << best << endl;
		else cout << "Case #" << x << ": " << "NOT POSSIBLE" << endl;
	}
}