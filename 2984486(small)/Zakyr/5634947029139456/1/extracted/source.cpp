#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
using namespace std;



double solve(int n, int l, int c)
{
	return 0;
}

long long get_bin_number(string flow)
{
	long long parsed = _strtoui64(flow.c_str(), 0, 2);
	return parsed;
}

int get_nb_ones(long long nb) {
	bitset<sizeof(long long)* CHAR_BIT> b(nb);
	return b.count();
}

void main()
{
	ifstream input_file("input.txt");
	ofstream output_file("output.txt");

	int nbCases;
	input_file >> nbCases;

	for (int i = 1; i <= nbCases; ++i) {		

		int n;
		input_file >> n;

		int l;
		input_file >> l;

		int nbSwitches = 0;

		vector<long long> outlets;
		vector<long long> devices;
		vector<long long> matches;

		string flow;
		for (int j = 0; j < n; ++j) {
			input_file >> flow;
			outlets.push_back(get_bin_number(flow));
		}
		for (int j = 0; j < n; ++j) {
			input_file >> flow;
			devices.push_back(get_bin_number(flow));
		}

		for (long long device : devices) {
			matches.push_back(outlets[0] ^ device);
		}
		sort(begin(matches), end(matches));

		if (n > 1) {
			for (int j = 1; j < outlets.size(); ++j) {
				vector<long long> temp_matches;
				for (long long device : devices) {
					auto diff = outlets[j] ^ device;
					if (binary_search(begin(matches), end(matches), diff)) {
						temp_matches.push_back(diff);
					}
				}
				sort(begin(temp_matches), end(temp_matches));
				matches = temp_matches;
			}
		}
		
		if (!matches.empty()) {
			int nbOnes = numeric_limits<int>::max();
			for (auto match : matches) {
				int tempNb = get_nb_ones(match);
				if (tempNb < nbOnes) nbOnes = tempNb;
			}

			nbSwitches = nbOnes;
		}
		else {
			nbSwitches = -1;
		}

		if (nbSwitches >= 0)
			output_file << "Case #" << i << ": " << nbSwitches << endl;
		else
			output_file << "Case #" << i << ": " << "NOT POSSIBLE" << endl;
	}

}