
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory.h>
using namespace std;

const int MAX = 20;

int mat[MAX][MAX];
int org[MAX][MAX];
int deleted[MAX];
int vis[MAX];
int N;

bool isFBT ( int root)
{
	vis [root] = 1;
	int childs = 0;
	int c1 = -1, c2 = -1;
	for ( int i = 0 ; i < N ; i ++)
		if ( mat[root][i] == 1 && !vis[i])
		{
			childs ++;
			if ( c1 != -1)
				c2 = i;
			else
				c1 = i;
		}
	if ( childs == 0 )
		return true;
	if ( childs != 2)
		return false;

	return isFBT(c1) && isFBT(c2);
}

int main ()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("b.out","w",stdout);

	int cases;
	cin >> cases;

	for ( int t = 1; t<=cases; t++)
	{
		memset(org,0,sizeof(org));
		cin >> N;
		for ( int i = 0; i < N-1; i ++ )
		{
			int s,d;
			cin >> s >>d;
			s--;d--;
			org [s][d] = org[d][s] = 1;
		}

		int res = 10000;

		for ( int mask = 0 ; mask < (1<<N) ; mask ++)
		{
			memset(deleted,0,sizeof(deleted));
			memcpy(mat,org,sizeof(org));

			int dels = 0;
			for ( int i = 0 ; i < N ; i ++ )
			{
				int del = (mask>>i)&1;
				if ( del)
				{
					dels++;
					deleted[i] = 1;
					//delete edges
					for ( int j = 0 ; j < N ; j ++ )
						mat[i][j] = mat[j][i] = 0;
				}
			}

			//is FBT ?
			bool ok = 0 ;
			for (int r = 0 ; r < N ; r++ )
			{
				memset(vis,0,sizeof(vis));
				if ( !deleted[r] && isFBT(r))
				{
					ok = 1;
					//disconnected ?
					for ( int k = 0 ; k < N ; k ++ )
						if ( !deleted[k] && !vis[k])
						{
							ok = 0;
							break;
						}

					if (ok)
						break;
				}
			}

			if ( ok && dels < res)
				res = dels;
		}

		cout <<"Case #"<< t <<": " << res << endl;

	}
	return 0;
}
