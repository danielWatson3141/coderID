#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <list>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <cstdlib>
#include <set>
#include <string>
#include <cstring>
#include <memory>

#pragma comment(linker, "/STACK:104857600,104857600")

using namespace std;

//#define FILE_IO

class B
{
private:
	const static int MAX_NODE_NUM = 1000;
	int caseNum, caseIndex;
	int nodeNum;
	bool connection[MAX_NODE_NUM][MAX_NODE_NUM];
	bool isVisited[MAX_NODE_NUM];
	int treeSize[MAX_NODE_NUM];
	int cost[MAX_NODE_NUM];
	int result;
	
public:
	void Run();

private:
	void Input();
	void Do();
	void Output();
	void DFS(int nodeIndex);
};

void B::Run()
{
	scanf("%d", &caseNum);
	for(caseIndex = 1; caseIndex <= caseNum; ++caseIndex)
	{
		Input();
		Do();
		Output();
	}
}

void B::Input()
{
	scanf("%d", &nodeNum);
	memset(connection, 0, sizeof(connection));
	for(int i = 1; i < nodeNum; ++i)
	{
		int index1, index2;
		scanf("%d %d", &index1, &index2);
		--index1; --index2;
		connection[index1][index2] = connection[index2][index1] = true;
	}
}

void B::Do()
{
	result = nodeNum;
	for(int i = 0; i < nodeNum; ++i)
	{
		memset(isVisited, 0, sizeof(isVisited));
		DFS(i);
		result = min(result, cost[i]);
	}
}

void B::DFS(int nodeIndex)
{
	isVisited[nodeIndex] = true;
	int nodeCount = 0;
	int tmp1 = 0, tmp2 = 0;
	int childCount = 0;
	for(int i = 0; i < nodeNum; ++i) 
	{
		if(connection[nodeIndex][i] && !isVisited[i])
		{
			DFS(i);
			++childCount;
			nodeCount += treeSize[i];
			int tmp = treeSize[i] - cost[i];
			if(tmp > tmp1)
			{
				tmp2 = tmp1;
				tmp1 = tmp;
			}
			else if(tmp > tmp2)
			{
				tmp2 = tmp;
			}
		}
	}
	treeSize[nodeIndex] = nodeCount + 1;
	
	if(childCount > 1)
	{
		cost[nodeIndex] = min(nodeCount, nodeCount - (tmp1 + tmp2));
	}
	else
	{
		cost[nodeIndex] = nodeCount;
	}
}

void B::Output()
{
	printf("Case #%d: %d\n", caseIndex, result);
}

B instance;
int main()
{
	#ifdef FILE_IO
	freopen("C:\\Users\\Administrator\\Desktop\\in.txt", "r", stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\out.txt", "w", stdout);
	#endif

	instance.Run();
	return 0;
}
