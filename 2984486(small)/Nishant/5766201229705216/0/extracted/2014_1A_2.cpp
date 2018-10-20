// CookieClicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int edges[1001];

vector<int> edgeList[1001];

int NumChildren(int n, int parentNode)
{
	vector<int> children;
	vector<int> parent;
	int num = 0;
	for (int i = 0; i < edgeList[n].size(); ++i)
	{
		if (parentNode != edgeList[n][i])
		{
			children.push_back(edgeList[n][i]);
			parent.push_back(n);
		}
	}

	while (!children.empty())
	{		
		int child = children[children.size() - 1];	
		children.pop_back();
		//cout << "Child " << child << endl;

		int pNode = parent[parent.size() - 1];
		parent.pop_back();

		//cout << "Parent " << pNode << endl;

		num++;

		for (int m = 0; m < edgeList[child].size(); ++m)
		{
			if (pNode != edgeList[child][m])
			{
				children.push_back(edgeList[child][m]);
				parent.push_back(child);
			}
		}

	}

	return num;
}

int Solve(int  N)
{
	int ret = N;

	for (int i = 1; i <= N; ++i)
	{
		if (edges[i] == 2)
		{
			//cout << "Root = " << i << endl;
			vector<int> next;
			vector<int> parent;

			for (int l = 0; l < edgeList[i].size(); ++l)
			{
				next.push_back(edgeList[i][l]);
				parent.push_back(i);
			}

			int numRem = 0;
			while (!next.empty())
			{
				int nextNode = next[next.size()-1];
				next.pop_back();

				int pNode = parent[parent.size() - 1];
				parent.pop_back();

				if (edges[nextNode] == 2)
				{
					numRem += NumChildren(nextNode, pNode);
					//cout << numRem << endl;
				}
				else if (edges[nextNode] >= 4)
				{
					vector<int> cook;
					for (int c = 0; c < edgeList[nextNode].size(); ++c)
					{
						if (edgeList[nextNode][c] != pNode)
						{
							int rem = NumChildren(c, nextNode) + 1;
							cook.push_back(rem);
						}
					}

					std::sort(cook.begin(), cook.end());

					for (int h = 0; h < (edges[nextNode] - 3); ++h)
					{
						numRem += cook[h];
					}
				}
				else
				{
					//cout << "Add more" << endl;
					for (int m = 0; m < edgeList[nextNode].size(); ++m)
					{
						if (edgeList[nextNode][m] != pNode)
						{
							next.push_back(edgeList[nextNode][m]);
							parent.push_back(nextNode);
						}
					}
				}
			}

			if (ret > numRem)
			{
				ret = numRem;
				if (ret == 0)
				{
					break;
				}
			}
		}
	}

	cout << "Return " << ret << endl;

	return ret;
}

int _tmain(int argc, _TCHAR* argv [])
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("c:\\GCJ_Inputs\\2014_1A_2\\input.in", ifstream::in);
	ofs.open("c:\\GCJ_Inputs\\2014_1A_2\\output.out", ifstream::out);

	if (!ifs)
	{
		cout << "Error reading input" << endl;
		return 0;
	}

	if (!ofs)
	{
		cout << "Error opening output" << endl;
		return 0;
	}

	cout << "STARTING" << endl;

	unsigned int numTests = 0;
	ifs >> numTests;

	for (unsigned int i = 0; i < numTests; ++i)
	{
		cout << "..";

		int N = 0;
		ifs >> N;

		memset(edges, 0, sizeof(edges));
		for (int k = 0; k <= 1001; ++k)
		{		
			edgeList[k].clear();
		}
		for (int m = 1; m < N; ++m)
		{
			int xi, yi = 0;
			ifs >> xi;
			ifs >> yi;

			edges[xi]++;
			edges[yi]++;


			if (!(edges[xi] > 0 && edges[xi] <= 4))
			{
				cout << " BAD" << endl;
			}

			if (!(edges[yi] > 0 && edges[yi] <= 4))
			{
				cout << " BAD" << endl;
			}


			edgeList[xi].push_back(yi);
			edgeList[yi].push_back(xi);
		}

		int ret = Solve(N);
		ofs << "Case #" + std::to_string(i + 1) + ": ";
		ofs << ret << endl;
	}

	cout << endl;
	cout << "COMPLETE" << endl;

	ofs.close();
	ifs.close();

	return 0;
}

