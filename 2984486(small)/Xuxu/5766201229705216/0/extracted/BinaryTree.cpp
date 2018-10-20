#include<fstream>
#include<vector>
#include<bitset>
#include<queue>
#include<math.h>
using namespace std;
int findMax(vector<vector<int>> &edge,bitset<1001> &sign,int x)
{
	if (edge[x].size() < 3)
		return 1;
	int big1 = 0;
	int big2 = 0;
	sign[x] = 1;
	for (int r = 0;r<edge[x].size();++r)
	if (!sign[edge[x][r]])
	{
		int semp = findMax(edge,sign,edge[x][r]);
		if (semp > big1)
		{
			big2 = big1;
			big1 = semp;
		}
		else
		if (semp > big2)
		{
			big2 = semp;
		}
	}
	return big1+big2+1;
}
int main()
{
	ifstream fin("B-small-attempt3.in");
	ofstream fout("BinaryTree.out");
	int t;
	fin>>t;
	for (int k=0;k<t;++k)
	{
		vector<vector<int>> edge(1101);
		int n;
		fin>>n;
		for (int i=1;i<n;++i)
		{
			int x,y;
			fin>>x>>y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		int ans = 1;
		for (int i=1;i<=n;++i)
		if (edge[i].size() > 1)
		{
			bitset<1001> sign;
			sign[i] = 1;
			int big1 = 0;
			int big2 = 0;
			for (int j=0;j<edge[i].size();++j)
			{
				int semp = findMax(edge,sign,edge[i][j]);
				if (semp > big1)
				{
					big2 = big1;
					big1 = semp;
				}
				else
				if (semp > big2)
				{
					big2 = semp;
				}
			}
			if (big1+big2+1>ans)
				ans = big1+big2+1;
		}
		fout<<"Case #"<<k+1<<": "<<n-ans<<endl;
	}
	return 0;
}