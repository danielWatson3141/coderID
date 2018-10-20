#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		int ans = 1000;
		cout << "Case #" << t + 1 << ": ";

		int n, l;
		cin >> n >> l;

		vector<string> outlets;
		vector<string> devices;

		for (int i = 0; i < n; i++)
		{
			string s; cin >> s;
			outlets.push_back(s);
		}

		for (int i =0; i < n; i++)
		{
			string s; cin >> s;
			devices.push_back(s);
		}

		for (int i = 0; i < n; i++)
		{
			bool ok = true;
			// match device 0 with outlet i
			vector<bool> flip;

			for (int j = 0; j < l; j++)
			{
				bool a = true;
				if (devices[0][j] == outlets[i][j])
					a = false;
				flip.push_back(a);
			}

			map<string, int> m;
			for (int j = 0; j < n; j++)
				m[outlets[j]]++;

			for (int j = 0; j < n; j++)
			{
				string s = devices[j];
				for (int k = 0; k < l; k++)
				{
					if (flip[k])
						s[k] = (char) '0' + 1 - (s[k] - '0');
				}

				if (m[s] <= 0)
					ok = false;
				m[s]--;
			}

			if (ok)
			{
				int total = 0;
				for (int i = 0; i < l; i++)
					if (flip[i]) total++;
				ans = min(total, ans);
			}
		}

		if (ans < 1000)
			cout << ans << endl;
		else 
			cout << "NOT POSSIBLE\n";




		// cout << "\n";

	}
}