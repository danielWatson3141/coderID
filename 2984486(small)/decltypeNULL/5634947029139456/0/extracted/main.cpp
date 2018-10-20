#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int MAXN = 150 + 9;
string initial[MAXN];
string required[MAXN];
const int INF = 1000 * 1000;

int N, L;

char flip(char c)
{
	if (c == '0') return '1';
	else return '0';
}

//int solve(int N, int L, const vector<string>& initial, const vector<string>& required)
int solve(void)
{
	for (int i = 0; i < N; i++) cout << initial[i] << endl;

	int result = INF;
	for (int i = 0; i < N; i++)
	{
		vector<int> flips(L);
		int curr_result = 0;

		for (int j = 0; j < L; j++)
		{
			int eq = initial[0][j] != required[i][j];
			flips[j] = eq;
			curr_result+=eq;
		}

		set<string> M;
		for (int j = 0; j < N; j++)
		{
			string s = initial[j];
			for (int k = 0; k < L; k++) if (flips[k] == 1) s[k] = flip(s[k]);
			M.insert(s);
		}

		for (int j = 0; j < N; j++)
		{
			if (M.find(required[j]) == M.end())
			{
				curr_result = INF;
				break;
			}
			else
			{
				;
			}
		}

		result = min(result, curr_result);
	}
	return result;
}

void solve_A(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;

	for (int tt = 1; tt <= T; tt++)
	{
		//int N, L;
		in >> N >> L;
		
		/*
		vector<string> initial;
		vector<string> required;
		*/

		string s;
		for (int i = 0; i < N; i++)
		{
			//in >> s;
			in >> initial[i];
			//initial.push_back(s);
		}
		for (int i = 0; i < N; i++)
		{
			//in >> s;
			in >> required[i];
			//required.push_back(s);
		}

		//int temp=solve(N, L, initial, required);
		int temp = solve();

		out << "Case #" << tt << ": ";
		if (temp<INF-100) out << temp;
		else out << "NOT POSSIBLE";
		out << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	solve_A();
	//solve_B();
	//solve_C();
	return 0;
}