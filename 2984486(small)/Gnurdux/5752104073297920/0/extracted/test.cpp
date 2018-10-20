#include <iostream>
#include <algorithm>
using namespace std;

int numbs[1000];
int badtable[1000][1000];

int badshuffle() {
	for (int i = 0; i < 1000; i++)
		numbs[i] = i;
	for (int i = 0; i < 1000; i++) {
		int x = rand()%1000;
		swap(numbs[i], numbs[x]);
	}
}

long long score() {
	long long ans = 0;
	for (int i = 0; i < 1000; i++)
		ans += badtable[i][numbs[i]];
	return ans;
}

int main() {
	for (int i = 0; i < 1000000; i++) {
		badshuffle();
		for (int i = 0; i < 1000; i++) badtable[i][numbs[i]]++;
	}

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;
		for (int i = 0; i < 1000; i++) {
			cin >> numbs[i];
		}
		cout << "Case #" << t << ": " << (score() > 1007000 ? "BAD\n" : "GOOD\n");
	}
	return 0;
}
