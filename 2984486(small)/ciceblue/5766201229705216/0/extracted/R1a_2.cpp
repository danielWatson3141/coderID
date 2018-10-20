#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#define REP(i,s,n) for(int i=s;i<n;i++)
using namespace std;
ifstream fin("B-small-attempt0 (1).in");
ofstream fout("out.txt");
vector<int> node[1001];
int N;
	bool ppp(const pair<int, int> &v1, const pair<int, int> &v2)
	{
		return v1.second - v1.first > v2.second - v2.first;
	}
pair<int,int> dfs(int index,int parent)
{
	vector<pair<int, int> > child;
	for (int i = 0; i < node[index].size(); ++i)
	{
		if (node[index][i] != parent)
		{
			child.push_back(dfs(node[index][i], index));
		}
	}
	int allNode = 0,cSize = child.size(),allCut;
	for (int i = 0; i < cSize; ++i) allNode += child[i].second;
	if (child.size() >= 2)
	{
		sort(child.begin(), child.end(), ppp);
		allCut = allNode - (child[0].second - child[0].first) - (child[1].second - child[1].first);
	}
	else
	{
		allCut = allNode;
	}
	//cout << index <<' '<<allCut << ' ' << allNode<< endl;
	return make_pair(allCut, allNode + 1);
}
int main()
{
	int T,x,y;
	fin >> T;
	REP(caseNumber, 1, T + 1)
	{
		fin >> N;
		REP(i, 0, N-1)
		{
			fin >> x >> y;
			node[x].push_back(y);
			node[y].push_back(x);
		}
		int minNum = 99999999;
		REP(i, 1, N+1)
		{
			//cout << "handle" << i << endl;
			minNum = min(dfs(i,0).first, minNum);
		}

		fout << "Case #" << fixed << caseNumber << ": " <<minNum<< "\n";
		REP(i, 1, N+1)
		{
			node[i].clear();
		}
	}
	fin.close();
	fout.close();
	return 0;
}