#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, t;

	vector<int > res;
	vector<int>::iterator it;

	int q[1000];

	cin >> T;
	for (t=0; t<T; t++) {
		int N;
		cin >> N;

		int i;
		for (i=0; i<N; i++) {
			cin >> q[i];
		}

		int z=0;
		for (i=0; i<N; i++) {
			z += (q[i] > q[q[i]]);
		}

		if (z >= 490 && z <= 510)
			res.push_back(1);
		else
			res.push_back(0);
	}

	t = 1;
	for (it = res.begin(); it<res.end(); it++, t++) {
		cout << "Case #" << t << ": ";
		if (*it == 1)
			cout << "GOOD" << endl;
		else
			cout << "BAD" << endl;
	}

	return 0;
}
