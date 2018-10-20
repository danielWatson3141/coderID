#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

int count(const vector<VI >& matrix, int N, int p, int n)
{
	int msize = matrix[n].size();
	int res = 1;
	REP(i, msize)
	{
		if (matrix[n][i] == p) continue;
		res += count(matrix, N, n, matrix[n][i]);
	}
	return res;
}


int solve(const vector<VI >& matrix, int N, int p, int n)
{
	//cout << "solve " << p << ", " << n << endl;
	int msize = matrix[n].size();
	if (msize == 1 && p != -1)
	{
		//cout << "p=1" << endl;
		return 0;
	}
	if (msize == 1 && p == -1)
		return -1;
	if (msize == 2 && p != -1)
	{
		return count(matrix, N, p, n) - 1;
	}
	int p1cnt = 0;
	for (int i=0; i<msize; i++)
	{
		if (matrix[n][i] == p)
			continue;
		if (matrix[matrix[n][i]].size() == 1)
			p1cnt++;
	}
	if (p != -1)
		msize--;
	if (msize == p1cnt && msize == 2)
		return 0;
	if (msize - p1cnt > 2)
		return -1;
	int res = msize - 2;
	if (p != -1)
		msize++;
	VI tmp;
	for (int i=0; i<msize; i++)
	{
		if (matrix[n][i] == p)
			continue;

		//if (matrix[matrix[n][i]].size() == 1)
		int k = solve(matrix, N, n, matrix[n][i]);
		//cout << "vertex " << matrix[n][i] << ": ";
		//cout << k << endl;
		if (k == -1)
			return -1;
		res += k;
	}

	return res;
}

int main()
{
	int T;
	cin >> T;
	REP(t,T)
	{
		int N;
		cout << "Case #" << (t+1) <<": ";
		cin >> N;
		vector< vector<int> > matrix(N, vector<int>());
		REP(i, N-1)
		{
			int x,y;
			cin >> x >> y;
			matrix[x-1].push_back(y-1);
			matrix[y-1].push_back(x-1);
		}
		/*REP(i,N)
		{
			cout << matrix[i].size();
			REP(j, matrix[i].size())
			{
				cout << " " << matrix[i][j];
			}
			cout << endl;

		}*/
		int k = 1000000000;
		REP(i,N)
		{
			int r = solve(matrix, N, -1, i);
			//cout << i << ": " << r << endl;
			if (r >= 0)
				k = min(k, r);
		}
		if (k == 1000000000)
			cout << (N - 1) << endl;
		else
			cout << k << endl;
	}
	
	return 0;
}

