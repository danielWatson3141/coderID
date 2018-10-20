#include <fstream>
#include <set>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int T;
int N;
int y;

int compute(set<int>* edges, set<int> node)
{
	if (node.size() <= 1)
		return 0;
	int num = node.size();
	vector<int> vals;
	for(set<int>::iterator iternode = node.begin(); iternode != node.end(); iternode++)
	{
		int j = *iternode;
		set<int> tmp = edges[j];
		edges[j].clear();
		for (set<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
		{
			int Y = *iter;
			edges[Y].erase(j);
		}
		int val = compute(edges,tmp);
		vals.push_back(val+1);
		for (set<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
		{
			int Y = *iter;
			edges[Y].insert(j);
		}
		edges[j] = tmp;
	}
	sort(vals.begin(),vals.end());
	return vals[num-1]+vals[num-2];
}

void main()
{
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	fin >> T;
	for(int i = 0; i < T; i++)
	{
		cout << i << endl;
		fin >> N;
		set<int> edges[1000];
		int count[1000] = {0};
		int maxn[1000] = {0};
		int X,Y;
		for (int j = 0; j < N-1; j++)
		{
			fin >> X >> Y;
			edges[X-1].insert(Y-1);
			edges[Y-1].insert(X-1);
			count[X-1]++;
			count[Y-1]++;
		}
		y = -1;
		for (int j = 0; j < N; j++)
		{
			set<int> tmp = edges[j];
			edges[j].clear();
			for (set<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
			{
				int Y = *iter;
				edges[Y].erase(j);
			}
			int val = compute(edges,tmp);
			if(y < val+1)
				y = val+1;
			for (set<int>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
			{
				int Y = *iter;
				edges[Y].insert(j);
			}
			edges[j] = tmp;
		}
		fout << "Case #" << i+1 << ": " << N-y << endl;
	}

	fin.close();
	fout.close();
}