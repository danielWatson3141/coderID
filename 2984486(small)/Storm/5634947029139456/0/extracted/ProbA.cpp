#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	freopen("C:\\Projects\\gcj\\input.txt", "r", stdin);
	freopen("C:\\Projects\\gcj\\output.txt", "w", stdout);

	int z;
	cin >> z;
	for (int q=0;q<z;q++) {
		int n,l;
		cin >> n >> l;

		vector<string> inp(n), req(n);
		for (int i=0;i<n;i++)
			cin >> inp[i];

		for (int i=0;i<n;i++) {
			cin >> req[i];
		}

		sort(req.begin(), req.end());
		vector<int> indices;
		for (int i=0;i<l;i++) {
			vector<int> req_count(2, 0);
			for (int j=0;j<n;j++) {
				req_count[req[j][i] - '0']++;
			}

			vector<int> got(2, 0);
			for (int j=0;j<n;j++) {
				got[inp[j][i] - '0']++;
			}

			if (req_count[0] == got[0] || req_count[0] == got[1])
				indices.push_back(i);
		}

		vector<long long> reql,inpl;
		for (int i=0;i<n;i++) {
			long long val = 0;
			for (int j=0;j<l;j++) {
				if (req[i][j] == '1')
					val |= (1LL << j);
			}
			reql.push_back(val);
		}
		
		for (int i=0;i<n;i++) {
			long long val = 0;
			for (int j=0;j<l;j++) {
				if (inp[i][j] == '1')
					val |= (1LL << j);
			}
			inpl.push_back(val);
		}
		
		sort(reql.begin(), reql.end());
		int best = -1;
		vector<long long> temp(n);
		for (long long i=0;i<(1<<indices.size());i++) {
			long long mask = 0;
			int count = 0;
			for (int j=0;j<indices.size();j++) {
				if ((i & (1LL << j)) != 0) {
					mask |= (1LL << indices[j]);
					count++;
				}
			}

			for (int j=0;j<n;j++) {
				temp[j] = inpl[j] ^ mask;
			}

			sort(temp.begin(), temp.end());
			if (temp == reql) {
				if (best == -1 || count < best)
					best = count;
			}
		}

		cout << "Case #" << (q + 1) << ": ";

		if (best == -1) cout << "NOT POSSIBLE" << endl;
		else cout << best << endl;
	}

	fclose(stdout);
	fclose(stdin);

	return 0;
}