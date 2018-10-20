#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <cstdio>

using namespace std;

int doubleNodeCount(const vector<vector<int> >& graph, int start, int deleted)
{
    int childrenCount = (int)graph[start].size();
    int count = (childrenCount == 2 ? 1 : 0);
    for (int i = 0; i < childrenCount; ++i)
    {
        int child = graph[start][i];
        if (child == deleted)
            continue;

        count += doubleNodeCount(graph, child, start);
    }
    return count;
}

int treeSize(const vector<vector<int> >& graph, int start, int deleted)
{
    int childrenCount = (int)graph[start].size();
    int count = 1;
    for (int i = 0; i < childrenCount; ++i)
    {
        int child = graph[start][i];
        if (child == deleted)
            continue;

        count += treeSize(graph, child, start);
    }
    return count;
}

int minDeletedNodes(const vector<vector<int> >& graph, int N)
{
    // if the original is fullb then 0.
    if (doubleNodeCount(graph, 0, -1) <= 1)
        return 0;

    int minDeletedNodes = N-1;
    for (int i = 0; i < N; ++i)
    {
        int deleted = i;
        int childrenI = (int)graph[i].size();
        for (int j = 0; j < childrenI; ++j)
        {
            int start = graph[i][j];
            int doubleNodes = doubleNodeCount(graph, start, deleted);
            if (graph[start].size() == 2)
                doubleNodes--;
            else if (graph[start].size() == 3)
                doubleNodes++;

            bool isFullBinaryTree = doubleNodes <= 1;
            if (isFullBinaryTree)
            {
                int deletedNodes = N - treeSize(graph, start, deleted);
                //cout << "Deleted: " << i+1 << ", Start: " << start+1 << ", FBT Size: " << deletedNodes << endl;
                minDeletedNodes = min(minDeletedNodes, deletedNodes);
            }
        }
    }
    return minDeletedNodes;
}

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; ++t)
	{	
		cout << "Case #" << t << ": ";

        int N;
        cin >> N;

        vector<vector<int> > graph(N);
        for (int i = 0; i < N-1; ++i)
        {
            int Xi, Yi;
            cin >> Xi >> Yi;
            Xi--;
            Yi--;
            graph[Xi].push_back(Yi);
            graph[Yi].push_back(Xi);
        }

        int answer = minDeletedNodes(graph, N);
        cout << answer;

        cout << endl;
	}
	
	return 0;
}