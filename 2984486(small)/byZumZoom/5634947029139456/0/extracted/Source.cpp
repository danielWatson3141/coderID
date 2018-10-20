#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> A, B;
vector<int> double_can;
int N, L, additional, tmp_add;

bool rec(int i) {
	if(i == double_can.size())
	{
		vector<string> A1 = A, B1 = B;
		sort(A1.begin(), A1.end());
		sort(B1.begin(), B1.end());
		if(A1 == B1)
			additional = min(tmp_add, additional);
		return A1 == B1;
	}
	bool can = false;
	if(rec(i + 1))
		can = true;

	for(int j = 0; j < N; ++j)
		A[j][double_can[i]] = '0' + ('1' - A[j][double_can[i]]);
	tmp_add++;
	
	if(rec(i+1))
		can = true;
	
	tmp_add--;
	for(int j = 0; j < N; ++j)
		A[j][double_can[i]] = '0' + ('1' - A[j][double_can[i]]);
	return can;
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		int n, l;
		cin >> n >> l;
		N = n; L = l;
		A.resize(n);
		B.resize(n);
		for(int i = 0; i < n; ++i)
			cin >> A[i];
		for(int i = 0; i < n; ++i)
			cin >> B[i];


		int flips = 0;
		bool fail = false;
		double_can.clear();
		for(int j = 0; j < l; ++j)
		{
			int plug = 0, device = 0;
			for(int i = 0; i < n; ++i)
			{
				if(A[i][j] == '1')
					++plug;
				if(B[i][j] == '1')
					++device;
			}
			if(plug == n - plug)
				double_can.push_back(j);

			if(plug == device)
				continue;
			else if(plug == n - device)
			{
				for(int i = 0; i < n; ++i)
					A[i][j] = '0' + ('1' - A[i][j]);
				++flips;
			}
			else
			{
				fail = true;
				break;
			}
		}

		if(fail)
		{
			cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
			continue;
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		tmp_add = 0;
		additional = 400;
		fail = !rec(0);

		if(!fail)
			cout << "Case #" << t << ": " << flips + additional << endl;
		else
			cout << "Case #" << t << ": " << "NOT POSSIBLE" << endl;
	}

	return 0;
}
