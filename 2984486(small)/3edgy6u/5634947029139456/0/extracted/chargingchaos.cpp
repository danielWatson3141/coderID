#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool vectorEquality (vector<string> a, vector<string> b) {
	vector<string> first, second;
	first = a;
	second = b;
	while(second.size() != 0) {
		for (int i = 0; i < second.size(); i++) {
			if (second[i] == first[0]) {
				second.erase(second.begin() + i);
			}
		}
		first.erase(first.begin());
		if (second.size() != first.size()) return false;
	}
	return true;
}

int testPower(int counter, vector<string> i, vector<string> result) {
	vector<string> initial;
	int changes = 0;
	initial = i;
	for (int i = 0; i < initial[0].size(); i++) {
		if (counter & (int)pow(2, i)) {
			changes++;
			for (int k = 0; k < initial.size(); k++) {
				if (initial[k][i] == '0') initial[k][i] = '1';
				else initial[k][i] = '0';
			}
		}
	}

	if (vectorEquality(initial, result)) {
		return changes;
	}
	return initial[0].size() + 1;
}

int main() {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("output.out");
	int inputs;
	fin >> inputs;
	for (int i = 0; i < inputs; i++) {
		int devices, length, counter, minimum, buffer;
		string input;
		vector<string> initial, result;
		initial.clear();
		result.clear();
		fin >> devices >> length;
		minimum = length + 1;
		for (int k = 0; k < devices; k++) {
			fin >> input;
			initial.push_back(input);
		}
		for (int k = 0; k < devices; k++) {
			fin >> input;
			result.push_back(input);
		}

		fout << "Case #" << i + 1 << ": ";

		if (vectorEquality(initial, result)) {
			fout << 0 << endl;
			continue;
		}

		counter = 0;
		while (counter < pow(2, initial[0].size())) {
			buffer = testPower(counter, initial, result);
			if (minimum > buffer) minimum = buffer;
			counter++;
		}
		if (minimum == length + 1) {
			fout << "NOT POSSIBLE" << endl;
		} else {
			fout << minimum << endl;
		}
	}
	return 0;
}