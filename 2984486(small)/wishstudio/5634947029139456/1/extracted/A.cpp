#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

#define maxN 200
#define maxL 50

int N, L;
string initial[maxN], desired[maxN];

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		cin >> N >> L;
		for (int i = 0; i < N; i++)
			cin >> initial[i];
		for (int i = 0; i < N; i++)
			cin >> desired[i];
		int ans = INT_MAX;
		for (int i = 0; i < N; i++)
		{
			bool mask[maxL];
			int steps = 0;
			for (int j = 0; j < L; j++)
			{
				mask[j] = (desired[0][j] != initial[i][j]);
				if (mask[j])
					steps++;
			}
			unordered_set<string> current;
			for (int j = 0; j < N; j++)
				if (j != i)
				{
					string c = initial[j];
					for (int k = 0; k < L; k++)
						if (mask[k])
							c[k] = !(c[k] - '0') + '0';
					current.insert(c);
				}
			bool ok = true;
			for (int j = 1; j < N; j++)
				if (current.find(desired[j]) == current.end())
				{
					ok = false;
					break;
				}
			if (ok)
				ans = min(ans, steps);
		}
		cout << "Case #" << z << ": ";
		if (ans < INT_MAX)
			cout << ans << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}
