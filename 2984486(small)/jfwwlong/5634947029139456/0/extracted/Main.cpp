#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>

using namespace std;

void change(int start, vector<string> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][start] == '0')
			v[i][start] = '1';
		else
			v[i][start] = '0';
	}
}

bool exist(vector<string> &v, unordered_map<string, int> &expected)
{
	unordered_map<string, int> temp(expected);
	for (auto &s : v)
	{
		if (temp.find(s) == temp.end())
		{
			return false;
		}
		else
		{
			temp[s]--;
			if (temp[s] < 0)
				return false;
		}
	}
	return true;
}

bool jianzhi(vector<string> &v, unordered_map<string, int> &expected, int start)
{
	int count1a = 0, count1b = 0;
	int count2a = 0, count2b = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][start] == '0')
			count1a++;
		else
			count1b++;
	}
	for (auto &i : expected)
	{
		if (i.first[start] == '0')
			count2a += i.second;
		else
			count2b += i.second;
	}
	return count1a == count2a && count1b == count2b;
}

void calc(vector<string> &v, unordered_map<string, int> &expected, int start, int length, int count, int &result)
{
	if (start == length)
	{
		if (exist(v, expected))
		{
			result = min(result, count);
		}
		return;
	}
	calc(v, expected, start + 1, length, count, result);
	change(start, v);
	calc(v, expected, start + 1, length, count + 1, result);
	change(start, v);
}

int main()
{
	ifstream in("A-small-attempt5.in");
	ofstream out("A-small-attempt5.out");
	int T, N, L;
	in >> T;
	for (int t = 0; t < T; t++)
	{
		in >> N >> L;
		unordered_map<string, int> expected;
		vector<string> v;
		string s;
		for (int i = 0; i < N; i++)
		{
			in >> s;
			if (expected.find(s) != expected.end())
				expected[s]++;
			else
				expected[s] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			in >> s;
			v.push_back(s);
		}
		int result1 = INT_MAX;
		calc(v, expected, 0, L, 0, result1);
		out << "Case #" << t + 1 << ": ";
		if (result1 == INT_MAX)
			out << "NOT POSSIBLE" << endl;
		else
			out << result1 << endl;
	}
	system("PAUSE");
	return 0;
}