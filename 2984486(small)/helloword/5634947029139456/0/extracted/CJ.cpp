#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//unordered_map<string, int> m;

bool be_equal(string *s1, string *s2, int N){
	//m.clear();
	for (int i = 0; i < N; ++i) {
		//m[s1[i]] = 1;
		if (s1[i] != s2[i]) {
			return false;
		}
	}

	//for (int i = 0; i < N; ++i){
	//	if (m.find(s2[i]) == m.end()) return false;
	//}

	return true;
}

void print(string *s1, string *s2, int N){
	for (int i = 0; i < N; ++i) {
		cout << s1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N; ++i) {
		cout << s2[i] << " ";
	}

	cout << endl;
}

void helper(string *s1, string *s2, int N, int l, int L, int flips, int &min_switchs){
	if (l == L - 1){
		sort(s1, s1 + N);
		if (be_equal(s1, s2, N)){
			if (flips < min_switchs)
				min_switchs = flips;
			return;
		}
		for (int i = 0; i < N; ++i) {
			if (s1[i][l] == '0')
				s1[i][l] = '1';
			else
				s1[i][l] = '0';
		}
		sort(s1, s1 + N);
		++flips;
		if (be_equal(s1, s2, N)){
			if (flips < min_switchs)
				min_switchs = flips;
		}

		for (int i = 0; i < N; ++i) {
			if (s1[i][l] == '0')
				s1[i][l] = '1';
			else
				s1[i][l] = '0';
		}
		return;
	}

	helper(s1, s2, N, l + 1, L, flips, min_switchs);

	for (int i = 0; i < N; ++i) {
		if (s1[i][l] == '0')
			s1[i][l] = '1';
		else
			s1[i][l] = '0';
	}
	flips++;
	sort(s1, s1 + N);
	if (be_equal(s1, s2, N)){
		if (flips < min_switchs)
			min_switchs = flips;
	}

	helper(s1, s2, N, l + 1, L, flips, min_switchs);

	for (int i = 0; i < N; ++i) {
		if (s1[i][l] == '0')
			s1[i][l] = '1';
		else
			s1[i][l] = '0';
	}
	return;
}


int main(){
	int round = 0;
	cin >> round;
	char *TEXT = "Case #";

	for (int r = 1; r <= round; ++r){
		int N, L;

		cin >> N >> L;

		string *flows = new string[N];
		string *request = new string[N];

		for (int i = 0; i < N; ++i){
			cin >> flows[i];
		}

		for (int i = 0; i < N; ++i){
			cin >> request[i];
		}
		int min_switch = INT_MAX;
		int flips = 0;
		sort(request, request + N);
		helper(flows, request, N, 0, L, flips, min_switch);
		if (min_switch == INT_MAX)
			cout << TEXT << r << ": " << "NOT POSSIBLE" << " " << endl;
		else
			cout << TEXT << r << ": " << min_switch << " " << endl;

	}
	return 0;
}