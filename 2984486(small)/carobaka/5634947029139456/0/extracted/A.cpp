#include <iostream>
#include <cstdio>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int transfm(string s1, int ind, vector<string> outlets, vector<string> devices){
	vector<int> change;
	for (int i = 0; i < devices[ind].length(); i++){
		if (s1[i] != devices[ind][i]){
			change.push_back(i);
		}
	}
	for (int i = 0; i < outlets.size(); i++){
		for (int j = 0; j < change.size(); j++){
			if (outlets[i][change[j]] == '0'){
				outlets[i][change[j]] = '1';
			} else {
				outlets[i][change[j]] = '0';
			}
		}
	} 
	sort(outlets.begin(), outlets.end());
	for (int i = 0; i < outlets.size(); i++){
		if (devices[i] != outlets[i]){
			return INT_MAX;
		}
	}
	return change.size();
}

int main(){
	int T; cin >> T; 
	for (int test = 1; test <= T; test++){
		int flips = INT_MAX;
		int N, L; cin >> N >> L;
		vector<string> outlets;
		vector<string> devices;
		for (int i = 0; i < N; i++){
			string s; 
			cin >> s;
			outlets.push_back(s);
		}

		for (int i = 0; i < N; i++){
			string s; 
			cin >> s;
			devices.push_back(s);
		}
		sort(devices.begin(), devices.end());
		for (int i = 0; i < N; i++){
			flips = min(flips, transfm(outlets[0], i, outlets, devices));
		}

		if (flips==INT_MAX){
			printf("Case #%d: NOT POSSIBLE\n", test);
		} else printf("Case #%d: %d\n", test, flips);
	}

	return 0;
}