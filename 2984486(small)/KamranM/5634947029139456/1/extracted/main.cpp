#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool Satisfies(vector<string> flows, vector<string> devices) {
	sort(flows.begin(), flows.end());
	sort(devices.begin(), devices.end());
	for (size_t i=0; i<flows.size(); ++i)
		if (flows[i] != devices[i])
			return false;
	return true;
}


int main() {
	
	int tcnt;
	cin >> tcnt;

	for (int ts=1; ts<=tcnt; ++ts) {
		int N, L;
		cin >> N >> L;
		vector<string> outlets(N);
	    vector<string> devices(N);
		for (int i=0; i<N; ++i)
			cin >> outlets[i];
		for (int i=0; i<N; ++i)
			cin >> devices[i];
		
		int ans = L+1;
		//algo begins
		for (int i=0; i<N; ++i) {
			vector<string> flows(outlets);
			int flips = 0;
			for (int j=0; j<L; ++j) {
				if (devices[i][j] != flows[0][j]) {
					++flips;
					for (int k=0; k<N; ++k)
						flows[k][j] = (flows[k][j] == '1' ? '0' : '1');
				}
			}
			if (Satisfies(flows, devices)) {
				ans = min(ans, flips);
			}
		}
		cout << "Case #" << ts << ": ";
		if (ans > L)
			cout << "NOT POSSIBLE";
		else
			cout << ans;
		cout << endl;
	}

	return 0;
}
