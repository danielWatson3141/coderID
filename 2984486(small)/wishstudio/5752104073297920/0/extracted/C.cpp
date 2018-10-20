#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <vector>

using namespace std;

#define maxN 2000

int N;
int a[maxN];
map<string, int> cnt;
vector<string> ans;
int q[maxN][maxN];

int main()
{
	/*srand(time(NULL));
	for (int g = 0; g < 1000000; g++)
	{
		N = 4;
		for (int i = 0; i < N; i++)
			a[i] = i;
		for (int i = 0; i < N; i++)
		{
			int j = rand() % N;
			//int j = rand() % (N - i) + i;
			swap(a[i], a[j]);
		}
		string ans;
		for (int i = 0; i < N; i++)
			ans += (a[i] + '0');
		for (int i = 0; i < N; i++)
			q[a[i]][i]++;
		if (cnt.count(ans) == 0)
			cnt[ans] = 0;
		else
			cnt[ans]++;
	}
	for (auto p: cnt)
		ans.push_back(p.first);
	std::sort(begin(ans), end(ans), [](string lhs, string rhs) { return cnt[lhs] > cnt[rhs]; });
	for (string s: ans)
	{
		int rev = 0;
		for (int i = 1; i < s.length(); i++)
			for (int j = 0; j < i; j++)
				if (s[i] < s[j])
					rev++;
		cout << s << " " << cnt[s] << " " << rev << endl;
	}
	cout << "STATS" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << q[i][j] << " ";
		cout << endl;
	}
	return 0;*/

	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		int bcnt = 0;
		for (int i = 0; i + 1 < N; i++)
			if (a[i] == i + 1)
				bcnt++;
		bool bad = true;
		if (a[0] == N - 1)
			bad = false;
		if (bcnt == 0)
			bad = false;
		cout << "Case #" << z << ": ";
		if (bad)
			cout << "BAD" << endl;
		else
			cout << "GOOD" << endl;
	}
	return 0;
}
