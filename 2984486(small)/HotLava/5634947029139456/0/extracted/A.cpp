#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T>& v) {
	str << "[";
	for(auto n : v) {
		str << n << ", ";
	}
	str << "]";
	return str;
}

int main() {
	int t;
	cin >> t;

	for(int i=0; i<t; ++i) {
		int n, l;
		cin >> n >> l;

		vector<int> ones(l, 0);

		vector<string> outlets;
		for(int i=0; i<n; ++i) {
			string f;
			cin >> f;

			for(int i=0; i<l; ++i) {
				if(f.at(i) == '1') ones.at(i)++;
			}

			outlets.push_back(f);
		}

		vector<int> target_ones(l, 0);

		vector<string> devices;
		for(int i=0; i<n; ++i) {
			string d;
			cin >> d;

			for(int i=0; i<l; ++i) {
				if(d.at(i) == '1') target_ones.at(i)++;
			}

			devices.push_back(d);
		}

		bool impossible = false;
		int count = 0;

		//cout << ones << endl;
		//cout << target_ones << endl;

		for(int i=0; i<l; ++i) {
			if(ones.at(i) == target_ones.at(i))
				continue;
			else if(ones.at(i) == n-target_ones.at(i))
				++count;
			else
				impossible = true;
		}

		if(impossible)
			cout << "Case #" << i+1 << ": NOT POSSIBLE" << endl;	
		else
			cout << "Case #" << i+1 << ": " << count << endl;
	}
}