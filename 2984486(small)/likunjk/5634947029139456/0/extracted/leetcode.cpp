#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void Init()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
}

string data1[209], data2[209];

vector<vector<int> > dp;
vector<int> tmp;

void func(int n)
{
	dp.clear();
	tmp.clear();
	dp.push_back(tmp);
	int i;
	for(i=0; i<n; ++i)
	{
		int size = dp.size();
		for(int j=0; j<size; ++j)
		{
			tmp = dp[j];
			tmp.push_back(i);
			dp.push_back(tmp);
		}
	}
}

bool comp(int n, int m)
{
	for(int i=0; i<n; ++i)
	{
		if(data1[i]!=data2[i])
			return false;
	}
	return true;
}

int main(void)
{
	Init();
	int tt,cases,n,m;
	int i,j,k;
	scanf("%d",&cases);
	for(tt=1; tt<=cases; ++tt)
	{
		scanf("%d %d",&n,&m);
		for(i=0; i<n; ++i)
		{
			cin>>data2[i];
		}
		for(i=0; i<n; ++i)
		{
			cin>>data1[i];
		}
		sort(data1, data1+n);
		sort(data2, data2+n);
		func(m);
		int ans = INT_MAX;
		int flag = 0;
		for(i=0; i<dp.size(); ++i)
		{
			for(j=0; j<dp[i].size(); ++j)
			{
				int a = dp[i][j];
				for(k=0; k<n; ++k)
				{
					data2[k][a] = data2[k][a]=='0' ? '1' : '0';
				}
			}
			sort(data2, data2+n);
			if(comp(n,m)==true)
			{
				flag = 1;
				if(dp[i].size() < ans)
					ans = dp[i].size();
			}
			for(j=0; j<dp[i].size(); ++j)
			{
				int a = dp[i][j];
				for(k=0; k<n; ++k)
				{
					data2[k][a] = data2[k][a]=='0' ? '1' : '0';
				}
			}
		}
		if(flag==0)
			printf("Case #%d: NOT POSSIBLE\n",tt);
		else
			printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}