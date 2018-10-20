#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <functional>
#include <cctype>
#include <locale>

using namespace std;

string NL = "\n";

template<typename T>
string vector_to_string(vector<T> v) {
	// Required stringstream object
	stringstream ss;

	// Populate
	copy(v.begin(), v.end(), ostream_iterator<string>(ss,", "));

	// Display
	return ss.str();
}

// TESTED
string flip_bit(string s, int bit) {
	char c = s[bit];
	char not_c = (c == '0' ? '1' : '0');
	s[bit] = not_c;

	return s;
}

template<typename T>
bool vector_equals(vector<T> &v1, vector<T> &v2) {
	return is_permutation(v1.begin(), v1.end(), v2.begin());
}

int flip_all(int n_switches, int flow_length, vector<string> &outlet_flows, vector<string> &required_flows, int bit, int depth) {
	cout << "(" << vector_to_string(outlet_flows) << /*", " << required_flows << ", " <<*/ bit << ", " << depth << ")" << NL;

	if(vector_equals(outlet_flows, required_flows)) {
		return depth;
	}

	if(bit >= flow_length) {
		return 100000;
	}

	vector<string> flipped(n_switches);
	for(int i = 0; i < outlet_flows.size(); ++i) {
		flipped[i] = flip_bit(outlet_flows[i], bit);
	}

	cout << "!" << NL;

	int r1 = flip_all(n_switches, flow_length, outlet_flows, required_flows, ++bit, depth);
	int r2 = flip_all(n_switches, flow_length, flipped, required_flows, bit, ++depth);

	return min(r1, r2);
}

string solve(int n_switches, int flow_length, vector<string> outlet_flows, vector<string> required_flows) {
	int result = flip_all(n_switches, flow_length, outlet_flows, required_flows, 0, 0);
	if(result == 100000) {
		return "NOT POSSIBLE";
	} else {
		return to_string(result);
	}
}

int main() {
	int n_test_cases;

	vector<string> results;

	ifstream fin("A-small-attempt1.in");
	fin >> n_test_cases;
	for (int i = 0; i < n_test_cases; ++i) {
		int n_switches;
		int flow_length;

		fin >> n_switches;
		fin >> flow_length;

		vector<string> outlet_flows;
		for(int j = 0; j < n_switches; ++j) {
			string f;
			fin >> f;
			outlet_flows.push_back(f);
		}

		vector<string> required_flows;
		for(int j = 0; j < n_switches; ++j) {
			string f;
			fin >> f;
			required_flows.push_back(f);
		}

		results.push_back(solve(n_switches, flow_length, outlet_flows, required_flows));
	}
	fin.close();

	ofstream fout("charging-chaos.out");
	fout.precision(15);
	for(int i = 0; i < results.size(); ++i)
		fout << "Case #" << i + 1 << ": " << results[i] << NL;

	fout.close();

	return 0;
}
