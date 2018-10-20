#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;
#pragma warning(disable: 4996)

#define OUTPUTLOG2(X,Y)\
{\
	char msg[1024];\
	sprintf( msg, X, Y );\
	OutputDebugString(msg);\
}
#define OUTPUTLOG OutputDebugString

bool isBinTree( vector<vector<int>>& tree, vector<int>& del )
{
	int s = tree.size();

	int r = 0;
	int root;
	for( int i = 0; i < s; i++ ){
		if( del[i] == 1 )
			continue;
		int edgenum = 0;
		for( int j = 0; j < tree[i].size(); j++ ){
			if( del[tree[i][j]] == 0 )
				edgenum++;
		}

		if( edgenum >= 4 )
			return false;

		if( edgenum == 2 ){
			root = i;
			r++;
			if( r > 1 )
				return false;
		}
	}
	if( r != 1 )
		return false;

	///
	vector<int> visited(s,0);
	queue<int> q;
	visited[root] = 1;
	for( int i = 0; i < tree[root].size(); i++ ){
		if( del[tree[root][i]] != 1 )
			q.push(tree[root][i]);
	}

	while( !q.empty() ){
		int v = q.front();
		q.pop();
		if( visited[v] != 0 )
			continue;
		visited[v] = 1;
		for( int i = 0; i < tree[v].size(); i++ ){
			if( del[tree[v][i]] != 1 ){
				q.push(tree[v][i]);
			}
		}
	}

	for( int i = 0; i < s; i++ )
		if( del[i] == 0 && visited[i] != 1 )
			return false;

	return true;
}

void main(int argc, char*argv[]) // usage: main.exe in.txt out.txt
{
	int i,j,k,l,m,n;

	ifstream fin(argv[1]);
	if( fin == NULL ){
		OUTPUTLOG2("cannot open in-file : %s\n", argv[1]);
		return;
	}
	FILE* fout = fopen(argv[2],"w");
	if( fin == NULL ){
		OUTPUTLOG2("cannot open out-file : %s\n", argv[2]);
		return;
	}

/////////////////////////////
	char line[1024];
	int CASE;
	fin >> CASE;
	for( int test_case = 1; test_case <= CASE; test_case++ ){
	/////////////////////////////
		int N, x, y;
		fin >> N;
		vector<vector<int>> tree(N);

		for( int i = 0; i < N-1; i++ ){
			fin >>x;
			fin >>y;

			tree[x-1].push_back(y-1);
			tree[y-1].push_back(x-1);
		}

		vector<int> del_node0(N, 0);
		int ans = 0;
		if( N == 2 ){
			ans = 1;
			goto end;
		}
		if( N == 3 ){
			ans = 0;
			goto end;
		}

		if( isBinTree( tree, del_node0 ) )
			goto end;

		ans = INT_MAX;
		int p = 1 << N;
		for( int c = 1; c < p; c++ ){
			int delnum = 0;
			vector<int> del_node(N, 0);
			for( int b = 0; b < N; b++ ){
				if( (c & (1<<b)) != 0 ){
					delnum++;
					del_node[b] = 1;
				}
			}
			if( delnum == N || delnum == N-1 ){
				if( ans > delnum ){
					ans = delnum;
				}
			}else if( isBinTree( tree, del_node ) ){
				if( ans > delnum ){
					ans = delnum;
				}
			}
		}

	/////////////////////////////
end:
		fprintf(fout,"Case #%d: %d\n", test_case, ans);
		if( fin.eof() ){
			if( test_case != CASE ){
				OUTPUTLOG( "in-file error:eof" );
			}
			break;
		}
	}

	OUTPUTLOG( "program end" );
}