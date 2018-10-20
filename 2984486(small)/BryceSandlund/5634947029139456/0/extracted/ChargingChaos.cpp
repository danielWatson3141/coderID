//============================================================================
// Name        :
// Author      : Bryce Sandlund
// Version     :
// Copyright   :
// Description : Google Code Jam Code
//============================================================================

#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <list>
#include <map>
#include <fstream>
#include <string>
#include <time.h>
#include <queue>
#include <tuple>
//#include <unordered_set>
//#include <unordered_map>
//#include <ctgmath>

#define INF 1000000000000000000LL

using namespace std;

typedef pair<int, pair<int, int> > iii;
int N, L;

vector<string> getVectors(vector<string> &input, int i)
{
	vector<string> solutions;

	for (int j = 0; j < N; ++j)
	{
		solutions.push_back(input[j].substr(0, i));
	}

	sort(solutions.begin(), solutions.end());
	return solutions;
}

bool works(vector<string> &board, vector<string> &solutions, int i)
{
	vector<string> partialBoard = getVectors(board, i);
	if (equal(partialBoard.begin(), partialBoard.end(), solutions.begin()))
	{
		return true;
	}

	return false;
}

int solve(vector<string> &board, vector<vector<string> > &solutions, int i)
{
	if (i == L)
	{
		return 0;
	}

	int ans1 = 100000;
	int ans2 = 100000;
	if (works(board, solutions[i+1], i+1))
	{
		ans1 = solve(board, solutions, i+1);
	}
	
	for (int j = 0; j < N; ++j)
	{
		if (board[j][i] == '1')
		{
			board[j][i] = '0';
		}
		else
		{
			board[j][i] = '1';
		}
	}

	if (works(board, solutions[i+1], i+1))
	{
		ans2 = 1 + solve(board, solutions, i+1);
	}

	for (int j = 0; j < N; ++j)
	{
		if (board[j][i] == '1')
		{
			board[j][i] = '0';
		}
		else
		{
			board[j][i] = '1';
		}
	}

	return min(ans1, ans2);
}

int main() {
	ofstream out;
	ifstream in("in.in");
	out.open("out.out");
	int T;
	in >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		in >> N >> L;

		vector<string> initial(N), goal(N);
		for (int i = 0; i < N; ++i)
		{
			in >> initial[i];
		}

		for (int i = 0; i < N; ++i)
		{
			in >> goal[i];
		}

		vector<vector<string> > solutions(L + 1, vector<string>());
		for (int i = 1; i <= L; ++i)
		{
			solutions[i] = getVectors(goal, i);
		}

		int minimum = solve(initial, solutions, 0);

		if (minimum < 10000)
		{
			out << "Case #" << caseNum << ": " << minimum << endl;
		}
		else
		{
			out << "Case #" << caseNum << ": " << "NOT POSSIBLE" << endl;
		}
	}
	out.close();
	return 0;
}