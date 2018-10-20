#include <iostream>
#include <iomanip>		// setprecision
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>			// map, unordered_map
#include <set>			// set, unordered_set
#include <algorithm>	// sort, stable_sort
#include <cstdlib>		// atoi, atof, etc.
#include <string>
using namespace std;

typedef unsigned long long ull_int;


int Build(vector<vector<int>> &A, vector<vector<int>> &N, int start, int finish)
{	// considering  edge (start, A[start][finish]), rooted at  A[start][finish]
	if (N[start][finish]>0)		return N[start][finish];
	int root = A[start][finish];		// root node
	int max1=0, max2=0;
	for (int i=0; i<A[root].size(); i++)
	{	if (A[root][i]==start)		continue;
		// consider edge  (root,  A[root][i])
		int s = Build(A, N, root, i);
		if (s>max1)
		{
			max2 = max1;
			max1 = s;
		} else if (s>max2)
			max2 = s;
	}
	if (max1==0 || max2==0)
		N[start][finish] = 1;
	else
		N[start][finish] = 1+ max1 + max2;
	return N[start][finish];
}

int F(int n, vector<vector<int>> &Adj)
{	// 2*|E| entries in Adj
	int i, j;
	vector<vector<int>> N(Adj);
	for (i=0; i<N.size(); i++)
		for (j=0; j<N[i].size(); j++)
			N[i][j] = 0;		// 0 denotes never touched
	// fill in N[][]
	for (i=0; i<N.size(); i++)
		for (j=0; j<N[i].size(); j++)
			Build(Adj, N, i, j);
	// enumerate to find the correct root
	int res=1;
	for (i=0; i<n; i++)
	{	int max1=0, max2=0;
		for (j=0; j<N[i].size(); j++)
		{	if (N[i][j]>max1)
			{	max2 = max1;
				max1 = N[i][j];
			}	else if (N[i][j]>max2)
			{	max2 = N[i][j];
			}
		}
		if (max1>=1 && max2>=1 && 1+max1+max2>res)
			res = 1+max1+max2;
	}
	return res;
}


int main()
{
	ifstream infile;
	infile.open("B-large.in");
	ofstream outfile;
	outfile.open("large.out");
	int nCases;

	infile >> nCases;
	// infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int N;
		infile >> N;
		vector<vector<int>> Edges(N);
		for (int i=1; i<=N-1; i++)
		{	int a, b;
			infile >> a >> b;
			Edges[a-1].push_back(b-1);
			Edges[b-1].push_back(a-1);
		}		
		
		
		int res = F(N, Edges);

		outfile << "Case #" << t << ": " << N-res << endl;
		cout << "Case #" << t << ": " << N-res << endl;	
		
	}
//	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}