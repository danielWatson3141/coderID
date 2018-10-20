#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

string otl[200], dvs[200], tmp[200];

int main()
{
	int T, N, L;
	cin >> T;
	int conf;
	int i, j, k;
	for (int tt = 1; tt <= T; tt++)
	{
		cin >> N >> L;
		for (i = 0; i < N; i++)
			cin >> otl[i];
		for (i = 0; i < N; i++)
			cin >> dvs[i];
	
		int ans = 100000;
		sort(dvs, dvs + N);
		for (conf = 0; conf < (1 << L); conf++)
		{
			int cnt = 0;
			for (i = 0; i < N; i++)
				tmp[i] = otl[i];
			for (i = 0; i < L; i++)
			{
				if ((1 << i) & conf)
				{
					for (j = 0; j < N; j++)
						tmp[j][i] = (1 - (tmp[j][i] - '0')) + '0';
					cnt++;
				}
			}
			
			sort(tmp, tmp + N);
			for (i = 0; i < N && dvs[i] == tmp[i]; i++);
			if (i == N)
				ans = min(ans, cnt);
		}
		cout << "Case #" << tt << ": ";
		if (ans < 1000)
			cout << ans << endl;
		else
			cout << "NOT POSSIBLE\n";
	}
}