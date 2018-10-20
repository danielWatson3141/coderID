#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, ans;
int S[20];
vector<string> v, v0, d;

void DFS(int u)
{
	if (u >= L) {
		v = v0;
		int r = 0;
		// flip
		for (int i = 0; i < L; ++i)
			if (S[i]) {
				r ++;
				for (int j = 0; j < N; ++j) v[j][i] = (v[j][i] == '1' ? '0' : '1');		
			}
		sort(v.begin(), v.end());
		bool f = true;
		for (int i = 0; i < N; ++i) {
			if (v[i] != d[i]) {
				f = false;
				break;
			}
		}
		if (f && r < ans) ans = r;
		return;
	}
	S[u] = 0;
	DFS(u + 1);
	S[u] = 1;
	DFS(u + 1);
}

int process(int cas)
{
	string k;
	cin >> N >> L;
	v0.clear(); d.clear();
	for (int i = 0; i < N; ++i) {
		cin >> k;
		v0.push_back(k);
	}
	for (int i = 0; i < N; ++i) {
		cin >> k;
		d.push_back(k);
	}
	sort(d.begin(), d.end());
	ans = N + 1;
	DFS(0);
	cout << "Case #" << cas << ": ";
	if (ans > N) cout << "NOT POSSIBLE" << endl;
	else cout << ans << endl;
}

int main()
{
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i) process(i);
}

