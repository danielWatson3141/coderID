#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

#define MAXN 1010
int tree[ MAXN ][ MAXN ];
int childs[ MAXN ];
int color[ MAXN ];
int stack[ MAXN ];
bool dfag[ MAXN ];
int stackptr;
int N;

void init(int n)
{
	for (int i = 1; i <= n; i ++)
	{
		tree[ i ][ i ] = 1;
		for (int j = i + 1; j <= n; j ++)
		{
			tree[ i ][ j ] = tree[ j ][ i ] = 0;
		}
	}
}

void DFS(int src)
{
	for (int i = 1; i <= N; i ++)
	{
		color[ i ] = 0;
		childs[ i ] = 0;
	}
	stackptr = 0;
	stack[ stackptr ++ ] = src;
	color[ src ] = 1;

	while (stackptr != 0)
	{
		int t = stack[ --stackptr ];
		color[ t ] = 2;

		for (int i = 1; i <= N; i ++)
		{
			if (color[ i ] == 0 && tree[ i ][ t ] != 0)
			{
				childs[ t ] ++;
				color[ i ] = 1;
				stack[ stackptr ++ ] = i;
			}
		}
	}
}

void _DFS(int src)
{
	for (int i = 1; i <= N; i ++)
	{
		color[ i ] = 0;
		dfag[ i ] = false;
	}

	stackptr = 0;
	stack[ stackptr ++ ] = src;
	color[ src ] = 1;
	bool f;

	while (stackptr != 0)
	{
		int t = stack[ --stackptr ];
		color[ t ] = 2;

		f = dfag[ t ];
		if (childs[ t ] != 2)
		{
			f = true;
		}

		for (int i = 1; i <= N; i ++)
		{
			if (color[ i ] == 0 && tree[ i ][ t ] != 0)
			{
				color[ i ] = 1;
				stack[ stackptr ++ ] = i;
				dfag[ i ] = f;
			}
		}
	}
}

int main()
{
	fstream in("test.in");
	fstream out("res");

	int T, x, y;
//	cin>>T;
	in>>T;
	for (int t = 1; t <= T; t ++)
	{
//		cin>>N;
		in>>N;
		init(N);
		for (int i = 0; i < N - 1; i ++)
		{
			in>>x>>y;
//			cin>>x>>y;
			tree[ x ][ y ] = tree[ y ][ x ] = 1;
		}

		int res = 1100;

		for (int i = 1; i <= N; i ++)
		{
			DFS(i);
			_DFS(i);

			int t = 0;
			for (int j = 1; j <= N; j ++)
			{
				if (dfag[ j ])
				{
					t ++;
				}
			}
			if (t < res)
			{
				res = t;
			}
		}
//		cout<<"Case #"<<t<<": "<<res<<endl;
		out<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;
}