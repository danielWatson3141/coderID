#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[]) {
	ifstream input("problem.in");
	ofstream output("problem.out");

	int t;
	input >> t;

	int64_t totalscore = 0;
	int64_t deviation = 4590000000;
	int64_t upperbound = 166492824458 + deviation; //12479503;
	int totalcorrect = 0;

	vector<vector<int>> counts(1000, vector<int>(10, 0));

	for (int i = 1; i <= t; ++i) {
		int n;
		input >> n;

		int64_t score = 0;
		for (int j = 0; j < n; ++j) {
			int v;
			input >> v;
			score += j*v*v;

			if (i > t / 2)
				++counts[j][v / 100];
		}

		bool fair = (score <= upperbound);
		if (fair == (i <= t / 2)) {
			++totalcorrect;
		}

		totalscore += score;

		output << "Case #" << i << ": " << (fair ? "GOOD" : "BAD") << endl;
	}


	return 0;
}

