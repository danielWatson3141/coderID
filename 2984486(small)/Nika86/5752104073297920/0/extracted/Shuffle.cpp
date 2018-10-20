#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

#ifdef _WIN32
#define LL "%I64d"
#else
#define LL "%lld"
#endif

#define inp(x) scanf("%d",&x)
#define inpf(x) scanf("%f",&x)

using namespace std;

typedef long long int ll;
typedef long long unsigned int ull;

int main() {
	int T,N;
	int j;
	double badness;
	double probData[2][1000];
	ifstream probDataFile("probData.txt");

	for (int i = 0; i < 1000 - 1; i++) {
		probDataFile >> probData[0][i];
		probDataFile >> probData[1][i];
	}
	probDataFile.close();
	probData[0][999] = 0.0;
	probData[1][999] = 0.0;

	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		
		badness = 0.0;
		for (int i = 0; i < N; i++) {
			cin >> j;
			if ((N + j - i) % N <= N/2 && j > i) {
				badness += probData[0][i];
			} else {
				badness -= probData[1][i];
			}
		}
		
		cout << "Case #" << t << ": " << ((badness > 0.0)?"BAD":"GOOD") << endl;
	}

	return 0;
}
