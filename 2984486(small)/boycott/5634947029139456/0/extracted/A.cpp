#include <assert.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <climits>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int N, L;

int count(vector<string> &a, int c)
{
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		if (a[i][c] == '1') res++;
	}
	return res;
}

bool dfs(int c, int left, int right, vector<string> &a, vector<string> &b, std::vector<bool> &flip)
{
	if (c == L)
	{
		//printf("c==L\n");
		// for (int j = 0; j < L; j++) 
		// {
		// 	if (flip[j]) cout << "F ";
		// 	else cout << "0 ";
		// }
		//cout << endl;
		std::vector<string> x, y;
		for (int i = left; i <= right; i++)
		{
			string tmp = a[i];
			for (int j = 0; j < L; j++) 
			{
				if (flip[j])
				{
					tmp[j] = char(('1'-tmp[j]) + '0');
				}
			}
			//cout << tmp << endl;
			//cout << b[i] << endl;
			x.push_back(tmp);
			y.push_back(b[i]);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		for (int i = left; i <= right; i++) 
		{
			if (x[i] != y[i]) return false;
		}
		return true;
	}

	if ((right - left + 1) % 2 == 1)
	{
		
		if (count(a, c) == count(b, c))
		{
			flip[c] = false;
			return dfs(c+1, left, right, a, b, flip);
		} else if (N - count(a, c) == count(b, c)) {
			flip[c] = true;
			return dfs(c+1, left, right, a, b, flip);
		}
		else {
			return false;
		}
	}
	else 
	{
		flip[c] = false;
		if (dfs(c+1, left, right, a, b, flip)) return true;
		flip[c] = true;
		if (dfs(c+1, left, right, a, b, flip)) return true;
		return false;
	}
}


int main() {
	int cases;
	cin >> cases;
	for (int t = 1; t <= cases; t++)
	{
		std::vector<string> a;
		std::vector<string> b;
		cin >> N >> L;
		for (int i = 0; i < N; i++) 
		{
			string tmp;
			cin >> tmp;
			a.push_back(tmp);
		}
		for (int i = 0; i < N; i++) 
		{
			string tmp;
			cin >> tmp;
			b.push_back(tmp);
		}
		std::vector<bool> flip(L);
		if (dfs(0, 0, N-1, a, b, flip)) 
		{
			int sum = 0;
			for (int i = 0; i < L; i++)
				if (flip[i]) sum++;
			printf("Case #%d: %d\n", t, sum);
		}
		else 
		{
			printf("Case #%d: NOT POSSIBLE\n", t);
		}
	}
	return 0;
}