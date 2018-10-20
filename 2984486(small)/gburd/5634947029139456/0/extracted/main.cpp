#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

/* !!!
   L could be greater than 32; therefore this program must be run on a
   64-bit machine. But, I mean, it's 2014.
*/

int countSetBits(int n)
{
	int ret = 0;
	for (int i = 0; i < sizeof(int) * 8; i++) {
		if (n & 1 << i) {
			ret++;
		}
	}
	return ret;
}

// so dumb
int getNextBinary(int L)
{
	char nextChar;
	int accum = 0;
	for (int i = 0; i < L; i++) {
		do {
			cin >> nextChar;
		} while (nextChar != '0' && nextChar != '1');

		if (nextChar == '1') {
			accum += (1 << (L - 1)) >> i;
		} 
	}
	return accum;
}

/*
   All outlet values are unique. Uniqueness is maintained when all
   outlets are XORed with a number (i.e. when panel switches are
   manipulated). So, put all device values in a HT and if all lookups
   for (outlet[j] ^ panel) are successful, then we have a valid set
   of panel switch manipulations. Try all panel combinations and keep
   track of the one with the minimum number of switch manipulations.
*/

#define NOT_POSSIBLE (-1)
int solve_single(int N, int L)
{
	unordered_set<int> devices;
	vector<int> outlets;

	int outletValue;
	for (int i = 0; i < N; i++) {
		outletValue = getNextBinary(L);
		outlets.push_back(outletValue);
	}

	int deviceValue;
	for (int i = 0; i < N; i++) {
		deviceValue = getNextBinary(L);
		devices.insert(deviceValue);
	}

	int minimumsets = L + 1;

	for (int panelVal = 0; panelVal < (1 << L); panelVal++) {
		bool works = true;
		for (int j = 0; j < N; j++) {
			if (devices.end() == devices.find(panelVal ^ outlets.at(j))) {
				works = false;
				break;
			}
		}
		if (works) {
			int numbits = countSetBits(panelVal);
			if (numbits < minimumsets) {
				minimumsets = numbits;
			}
		}
	}

	if (minimumsets <= L) {
		return minimumsets;
	} else {
		return NOT_POSSIBLE;
	}

}

int main()
{
	int T, N, L;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> N >> L;
		int ans = solve_single(N, L);

		cout << "Case #" << i + 1 << ": ";
		if (ans == NOT_POSSIBLE) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout <<  ans << endl;
		}
	}

	return 0;
}

