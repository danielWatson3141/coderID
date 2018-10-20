#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <string.h>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)
int A[15][15];
int A2[15][15];
int N;

int visited[15];

bool rooted(int r)
{
	vector<int> kids;
	visited[r] = 1;
	for (int i = 0; i < N; i++)
	{
		if (A2[r][i] && !visited[i]) kids.push_back(i);
	}
	if (kids.size() == 0)
		return true;
	if (kids.size() != 2)
		return false;
	return rooted(kids[0]) && rooted(kids[1]);
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		cin >> N;

		memset(A, 0, sizeof(A));
		for (int i = 0; i < N-1; i++)
		{
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			A[a][b] = A[b][a] = 1;
		}

		/*
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
		*/
		int best = MAXVAL;
		for (int m = 0; m < (1<<N); m++)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					A2[i][j] = A[i][j];
				}
			}
			// delete the subset of m nodes from the tree
			vector<int> D(N, 0);
			for (int i = 0; i < N; i++)
			{
				if ((m&(1<<i)) == 0) continue;
				for (int j = 0; j < N; j++)
				{
					A2[i][j] = A2[j][i] = 0;
				}
				D[i] = 1;
			}
			/*
			cout <<"** m = "<<m<<endl;
			for (int i = 0; i < N; i++) { for (int j = 0; j < N; j++) cout << A2[i][j] << " "; cout << endl; }
			for (int i = 0; i < N; i++) cout << D[i] << " "; cout << endl;
			*/
			// try each root
			for (int i = 0; i < N; i++)
			{
				if (D[i]) continue; // i was deleted
				memset(visited, 0, sizeof(visited));
				bool x = rooted(i);
				//cout << "rooted i = " << i << " = " << x << endl;
				if (x)
				{
					bool ok = true;
					for (int j = 0; j < N; j++)
					{
						if (visited[j] == 0 && D[j] == 0)
						{
							ok = false;
							break;
						}
					}
					if (ok)
					{
						best = min(best, __builtin_popcount(m));
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", testCase, best);
	}
	return 0;
}
