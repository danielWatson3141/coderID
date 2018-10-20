#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<vector<int> > *edge;

vector<vector<int> > *score;

int dfs(int x, int prev)
{
	if ((*score)[x][prev] != -1)
		return (*score)[x][prev];
	if ((*edge)[x].size() == 2)
		return 1;
	if ((*edge)[x].size() == 1)
	{	
		return 1;
	}
	int ret = 1;
	int max1 = 0, max2 = 0;
	for(int i=0; i<(*edge)[x].size(); ++i)
	{
		int y = (*edge)[x][i];
		if (y != prev){
			int tmp = dfs(y, x);
			if (tmp > max1)
			{
				max2 = max1; max1 = tmp;	
			} else if (tmp > max2)
			{
				max2 = tmp;	
			}
		}
	}
	ret = ret + max1 + max2;
	 (*score)[x][prev] = ret;
	return ret;
}

int main()
{
	int T;
	ifstream fin("B-small-attempt2.in");
	ofstream fout("B.out");
	fin >> T;
	int N;
	
	vector<int> a;
	a.clear();	
	
	for(int it = 1; it <= T; ++it)
	{
	
		fin >> N;
		vector<vector<int> > e(N, a);
		edge = &e;
		vector<int> b(N, -1);
		vector<vector<int> > sb(N, b);
		score = &sb;
		int x, y;
		int maxSize = 0;
				//cout << it << endl;
		for(int i=0; i<N-1; ++i)
		{
			fin >> x >> y;
			--x; --y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		if (N == 2)
		{
			fout << "Case #" << it << ": " << 1 << endl;
			continue;
		}
				//cout << it << endl;

		for(int i=0; i<N; ++i)
		{
			for(int j=0; j<e[i].size(); ++j)
			{
				for(int k=j+1; k<e[i].size(); ++k)
				{
					//cout << i << ' ' << j << ' ' << k << endl;
					int tmp = 1 + dfs(e[i][j], i) + dfs(e[i][k], i);
					maxSize = max(maxSize, tmp);
				}
			}
		}

		fout << "Case #" << it << ": " << N-maxSize<< endl;
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
