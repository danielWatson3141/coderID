#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, L;

char outlet[150][50];
char device[150][50];

bool flip[50];

void setFlip(int from, int to) {
	for(int i = 0; i < L; i++) {
		flip[i] = device[from][i] != outlet[to][i];
	}
}

int countFliped() {
	int result = 0;
	for(int i = 0; i < L; i++) {
		if(flip[i]) result++;
	}
	return result;
}

bool allPossible() {
	vector<string> o;
	vector<string> d;

	for(int i = 0; i < N; i++) {
		d.push_back(device[i]);
		string s;
		for(int j = 0; j < L; j++) {
			s += (outlet[i][j] - '0' + flip[j])%2 + '0';
		}
		o.push_back(s);
	}

	sort(d.begin(), d.end());
	sort(o.begin(), o.end());

	for(int i = 0; i < N; i++) {
		if(d[i] != o[i]) return false;
	}
	return true;
}

int solve() {
	int result = 100;
	for(int i = 0; i < N; i++) {
		setFlip(i, 0);
		if(allPossible()) result = min(result, countFliped());
	}

	return result == 100 ? -1 : result;
}

int main() {
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {

		scanf("%d %d", &N, &L);

		for(int i = 0; i < N; i++) {
			scanf("%s", outlet[i]);
		}
		for(int i = 0; i < N; i++) {
			scanf("%s", device[i]);
		}

		printf("Case #%d: ", c);

		int result = solve();

		if(result < 0) puts("NOT POSSIBLE");
		else printf("%d\n", result);
	}

	return 0;
}

