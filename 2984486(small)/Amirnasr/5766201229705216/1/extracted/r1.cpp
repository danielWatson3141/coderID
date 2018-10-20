#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
int main()
{
	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	int t;
	cin>>t;
	for (int i =1; i <=t; i++)
	{
		int n,l;
		cin>>n>>l;
		vector<string> sw(n);
		vector<string> d(n);
		for (int j = 0; j < n; j++) cin>>sw[j];
		for (int j = 0; j < n; j++) cin>>d[j];
		sort(d.begin(), d.end());
		int mn = 1000000;
		for (int k = 0; k < n; k++)
		{
			int ch = 0;
			vector<bool> tk(l, false);
			for (int z = 0; z<l; z++)
			{
				if (sw[k][z] != d[0][z])
				{
					ch++;
					tk[z] = true;
				}
			}
			vector<string> sw2 = sw;
			for (int a = 0; a < n; a++)
			{
				for (int z = 0; z<l; z++)
				{
					if (sw2[a][z] == '0' && tk[z]) sw2[a][z] = '1';
					else if (sw2[a][z] == '1' && tk[z]) sw2[a][z] = '0';
				}
			}
			sort(sw2.begin(), sw2.end());
			bool ok = true;
			//cout<<ch<<endl;
			for (int a = 0; a < n; a++)
			{
				if (d[a] != sw2[a]) ok =false;
			}
			if (ok)
				mn = min(mn, ch);
		}
		if (mn == 1000000)
		{
			cout<<"Case #"<<i<<": NOT POSSIBLE"<<endl;
		}
		else
			cout<<"Case #"<<i<<": "<<mn<<endl;
	}
}
*/

int sz[1005];
int dp[1005];
vector<vector<int> > tr;
int dfs1(int i, int p)
{
	int r = 1;
	for (int j = 0; j < tr[i].size(); j++)
	{
		if (tr[i][j] != p)
			r+= dfs1(tr[i][j], i);
	}
	return sz[i] = r;
}

int sol(int i , int p)
{
	if (dp[i] != -1) return dp[i];
	int ch = tr[i].size();
	int tot = 0;
	for (int j=0; j < tr[i].size(); j++) if (tr[i][j] != p) tot += sz[tr[i][j]];
	if (p != -1) ch--;
	if (ch == 0) return 0;
	if (ch == 1)
	{
		for (int j = 0; j < tr[i].size(); j++)
		{
			if (tr[i][j] != p)
				return dp[i] = sz[tr[i][j]];
		}
	}
	else
	{
		int mn = 1000000000;
		vector<int> mns;
		for (int j = 0; j < tr[i].size(); j++)
		{
			if (tr[i][j] == p) continue;
			mns.push_back(sol(tr[i][j], i) - sz[tr[i][j]]);
		}
		sort(mns.begin(), mns.end());
		return dp[i] = tot+mns[0]+mns[1];
	}
}

int main()
{
	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	int t;
	cin>>t;
	for (int i =1; i <=t; i++)
	{
		int n;
		cin>>n;
		tr = vector<vector<int> >(n);
		for(int j = 0; j < n-1; j++)
		{
			int a,b;
			cin>>a>>b;
			tr[a-1].push_back(b-1);
			tr[b-1].push_back(a-1);
		}
		int mn = 10000;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 1005; k++)
				sz[k] = 0,dp[k] = -1;
			dfs1(j,-1);
			mn = min(sol(j,-1), mn);
		}
		cout<<"Case #"<<i<<": "<<mn<<endl;
	}
}