#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

int tree[1002][1002];

int main()
{
	ifstream fin("B-small-attempt0.in");
	ofstream fout("test.out");
	int T = 0;
	fin >> T;
	for(int r = 1;r <= T;r++)
	{
		int N = 0, Y = 0, xx = 0, yy = 0;
		for(int k = 0;k < 1002;k++)
			memset(tree[k], 0, sizeof(int) * 1002);

		fin >> N;
		for(int j = 1;j < N;j++)
		{
			fin >> xx >> yy;
			tree[xx][yy] = 1;
			tree[yy][xx] = 1;
		}

		Y = N - 1;

		for(int i = 1;i <= N;i++)
		{
			int root_son = 0;
			for(int j = 1;j <= N;j++)
			{
				if(j != i)
				{
					if(tree[i][j] == 1)
						root_son++;
				}
			}
			if(root_son == 3)
				continue;

			int curDeleteNum = 0;
			//set the ith node as the root
			int visited[1001];
			memset(visited, 0, sizeof(int) * 1001);
			//0 is not visited

			vector<int> curNodeList, tmpCurNodeList;
			curNodeList.push_back(i);
			while(curNodeList.size() != 0)
			{
				tmpCurNodeList.clear();
				int len = curNodeList.size();
				for(int j = 0;j < len;j++)
				{
					visited[curNodeList[j]] = 1;
					//son number;
					int sonNum = 0;
					for(int k = 1;k <= N;k++)
					{
						if(tree[curNodeList[j]][k] == 1 && visited[k] == 0)
						{
							sonNum++;
						}
					}

					if(sonNum == 1)
					{
						//the remain
						vector<int> deleteList, tmpList;
						for(int k = 1;k <= N;k++)
							if(tree[curNodeList[j]][k] == 1 && visited[k] == 0)
								deleteList.push_back(k);

						while(deleteList.size() != 0)
						{
							tmpList.clear();
							curDeleteNum += deleteList.size();
							
							for(int t = 0;t < deleteList.size();t++)
							{
								int cur = deleteList[t];
								visited[cur] = 1;
								for(int m = 1;m <= N;m++)
								{
									if(tree[cur][m] == 1 && visited[m] == 0)
									{
										tmpList.push_back(m);
									}

								}
							}
							deleteList = tmpList;
						}
					}
					else if(sonNum == 2)
					{
						for(int k = 1;k <= N;k++)
						{
							if(tree[curNodeList[j]][k] == 1 && visited[k] == 0)
								tmpCurNodeList.push_back(k);
						}
					}

				}

				curNodeList = tmpCurNodeList;
			}

			//cout << r << " :" << curDeleteNum << endl;
			Y = (curDeleteNum < Y) ? curDeleteNum : Y;	
		}

		fout << "Case #" << r << ": " << Y << endl;
	}
	
	return 0;
}