#include <iostream>
#include <algorithm>
using namespace std;

int T, nCase = 1;

int N, L;
int source[10], dest[10];

int bc(int x) {
	int cnt = 0; while(x) { ++cnt; x ^= (x&-x); }
	return cnt;
}

bool compare()
{
	for (int i=0;i<N;++i) if (source[i]!=dest[i]) return false;
	return true;
}

int solve() {
	sort(dest, dest+N);
	int ans = 99999, bits = 0;
	for(int i=0;i<(1<<L);++i) {
		for(int j=0;j<N;++j) source[j] ^= (i);
		sort(source, source+N);
		if(compare()) {
			bits = bc(i);
			if (bits < ans) ans = bits;
		}
		for(int j=0;j<N;++j) source[j] ^= (i);
	}
	return ans;
}

void input(int* arr)
{
	char buf[64];
	for(int i=0;i<N;++i) {
		cin >> buf;
		arr[i] = 0;
		for(int j=0;j<L;++j) {
			arr[i] = arr[i]*2 + buf[j]-'0';
		}
	}
}

int main()
{
	cin >> T;
	while (T--) {
		cin >> N >> L;
		input(source);
		input(dest);
		
		cout << "Case #" << nCase ++ << ": "  ;
		int sol = solve();
		if (sol > L) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << sol << endl;
		}
	}
	return 0;
}