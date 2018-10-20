#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<bool> VB;
typedef vector<VB> MB;

typedef vector<string> VS;

int mmin;

bool check(VS &flows, VS &finalflows) {
	sort(flows.begin(), flows.end());
	for(int i = 0; i < flows.size(); ++i) {
		if(flows[i] != finalflows[i]) return false;
	}
	return true;
}

void calc(VS &flows, VS &finalflows, int flips, int pos) {
	if(pos == flows[0].size()) {
		if(check(flows, finalflows)) {
			if(mmin == -1 || flips < mmin) mmin = flips;
		}
		return;
	}
	calc(flows, finalflows, flips, pos+1);
	for(int i = 0; i < flows.size(); ++i) {
		flows[i][pos] = flows[i][pos] == '1' ? '0' : '1';
	}
	calc(flows, finalflows, flips+1, pos+1);
	for(int i = 0; i < flows.size(); ++i) {
		flows[i][pos] = flows[i][pos] == '1' ? '0' : '1';
	}
}


int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i) {
		int n, l;
		cin >> n >> l;
		VS flows(n);
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < l; ++k) {
				char c;
				cin >> c;
				flows[j].push_back(c);
			}
		}
		VS finalflows(n);
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < l; ++k) {
				char c;
				cin >> c;
				finalflows[j].push_back(c);
			}
		}
		mmin = -1;
		sort(finalflows.begin(), finalflows.end());
		calc(flows, finalflows, 0, 0);
		cout << "Case #" << i+1 << ": ";
		if(mmin == -1) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << mmin << endl;
		}
		
	}
}