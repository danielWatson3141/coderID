#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

bool next = false;
int n,l;

bool compare(string o, string d, int val) {
	for (int i = 0; i < l; i++) {
		if ((val >> i) & 1) {
			if (o[i] == d[i])
				return false;
		} else {
			if (o[i] != d[i])
				return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> n >> l;
		string s;
		getline(cin,s);
		getline(cin,s);
		vector<string> outlets, devices;
		int index = 0;
		for (int j = 0; j < n; j++) {
			string outlet;
			for (int k = 0; k < l; k++) {
				outlet.push_back(s[index]);
				index++;
			}
			outlets.push_back(outlet);
			index++;
		}
		getline(cin,s);
		index = 0;
		for (int j = 0; j < n; j++) {
			string device;
			for (int k = 0; k < l; k++) {
				device.push_back(s[index]);
				index++;
			}
			devices.push_back(device);
			index++;
		}

		int val = (int)pow((float)2,(float)l);
		int min = l;
		bool poss = false;
		for (int j = 0; j < val; j++) {
			set<int> v;
			for (int k = 0; k < n; k++) {
				string d = devices[k];
				bool valid = false;
				for (int m = 0; m < n; m++) {
					if (v.find(m) != v.end())
						continue;
					string o = outlets[m];
					if (compare(o,d,j)) {
						valid = true;
						v.insert(m);
						break;
					}
				}
				if (!valid)
					break;
				else if (k == n-1) {
					poss = true;
					int count = 0;
					for (int m = 0; m < l; m++) {
						if (((j >> m) & 1) == 1)
							count++;
					}
					if (count < min)
						min = count;
				}
			}
		}
		if (poss)
			cout << "Case #" << i << ": " << min << endl;
		else
			cout << "Case #" << i << ": NOT POSSIBLE" << endl;
	}
	return 0;
}
