#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <utility>
#include <set>
using namespace std;

void solve(vector<string>& initialCharges, vector<string>& desiredCharges, int caseNum) {
	vector<string> workspace = initialCharges;
	sort(desiredCharges.begin(), desiredCharges.end());
	int minTransforms = 999999999;
	for (int i = 0; i < desiredCharges.size(); ++i) {
		int transforms = 0;
		vector<string> workspace = initialCharges;
		for (int j = 0; j < desiredCharges[i].size(); ++j) {
			if (workspace[0][j] != desiredCharges[i][j]) {
				transforms++;
				for (int ii = 0; ii < workspace.size(); ++ii) {
					if (workspace[ii][j] == '0') {
						workspace[ii][j] = '1';
					}
					else {
						workspace[ii][j] = '0';
					}
				}
			}
		}
		sort(workspace.begin(), workspace.end());
		if (workspace == desiredCharges) {
			if (transforms < minTransforms) {
				minTransforms = transforms;
			}
		}
	}
	cout << "Case #" << caseNum << ": ";
	if (minTransforms == 999999999) {
		cout << "NOT POSSIBLE" << endl;
	}
	else {
		cout << minTransforms << endl;
	}
}


int main(void){
	int numCases, numCharges, lengthCharges;
	cin >> numCases;
	for (int ii = 0; ii < numCases; ++ii) {
		cin >> numCharges;
		cin >> lengthCharges;
		vector<string> initialCharges;
		vector<string> desiredCharges;
		for (int i = 0; i < numCharges; ++i) {
			string charge;
			cin >> charge;
			initialCharges.push_back(charge);
		}

		for (int i = 0; i < numCharges; ++i) {
			string charge;
			cin >> charge;
			desiredCharges.push_back(charge);
		}
		solve(initialCharges, desiredCharges, ii + 1);
	}
	return 0;
}