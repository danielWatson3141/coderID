#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

int main()
{
	freopen("large.in", "r", stdin);
	freopen("large.out", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		int n, l;
		cin >> n >> l;
		vector <string> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		vector <string> res(n);
		for (int i = 0; i < n; i++)
			cin >> res[i];
		int ans = 1e9;
		for (int i = 0; i < 1; i++)
			for (int j = 0; j < n; j++)
			{
				vector <int> flip(l, 0);
				int now = 0;
				for (int k = 0; k < l; k++)
					if (arr[i][k] != res[j][k])
					{
						flip[k] = 1;
						now++;
					}
				set <string> out;
				for (int k = 0; k < n; k++)
				{
					string s = arr[k];
					for (int p = 0; p < l; p++)
						if (flip[p])
							s[p] = '0' + ('1' - arr[k][p]);
					out.insert(s);
				}
				for (int k = 0; k < n; k++)
					if (out.count(res[k]))
						out.erase(res[k]);
				if (out.empty())
					ans = min(now, ans);
			}
		cout << "Case #" << t + 1 << ": ";
		if (ans < 1e9) 
		{
			cout << ans;
		}
		else
		{
			cout << "NOT POSSIBLE";
		}
		cout << endl;
	}

	return 0;
}