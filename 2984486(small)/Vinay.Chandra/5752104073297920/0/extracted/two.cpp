#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for (int TC = 1; TC <= 1; TC--)
	{
		int N;
		cin>>N;

		bool tree[N][N];
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; j++)
				tree[i][j] = false;

		for (int i = 0; i < N - 1; ++i)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			tree[x-1][y-1]=true;
		}


	}
}