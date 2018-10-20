#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for(int i = a ; i < b ; i++)
#define FORI(i,b,a) for(int i = b - 1 ; i >= a ; i--)

#define LL long long int

vector <string> setBitVector;

void printSetBitVector() {
	for(int i = 0 ; i < (int) setBitVector.size() ; i++) {
		cout << setBitVector[i] << endl;
	}
}

void findSetBitVector(string str1, string str2) {
	string setBit;
	for(int i = 0 ; i < (int) str1.length() ; i++) {
		if(str1[i] == str2[i]) {
			setBit = setBit + '0';
		} else {
			setBit = setBit + '1';
		}
	}
	setBitVector.push_back(setBit);
}

int countSetBit(string str) {
	int ans = 0;
	for(int i = 0 ; i < (int) str.length() ; i++) {
		if(str[i] == '1') {
			ans++;
		}
	}
	return ans;
}

bool isConvertible(vector <string> input, vector <string> devices, int N, int L, string setBit) {
	vector <bool> used(N, false);
	for(int i = 0 ; i < N ; i++) {
		bool flag = false;
		for(int j = 0 ; j < N ; j++) {
			if(!used[j]) {
				int k = 0;
				for(k = 0 ; k < L ; k++) {
					if(setBit[k] == '1') {
						if(input[i][k] == devices[j][k]) {
							break;
						}
					} else {
						if(input[i][k] != devices[j][k]) {
							break;
						}
					}
				}
				if(k == L) {
					used[j] = true;
					flag = true;
					break;
				}
			}
		}
		if(!flag) {
			return false;
		}
	}
	return true;
}

void solvePr1() {
	int T;
	cin >> T;
	for(int tc = 1 ; tc <= T ; tc++) {
		int N, L;
		cin >> N >> L;
		int ans = 1024;
		setBitVector.clear();
		vector <string> input(N);
		vector <string> devices(N);
		for(int i = 0 ; i < N ; i++) {
			cin >> input[i];
		}
		for(int i = 0 ; i < N ; i++) {
			cin >> devices[i];
		}
		cout << "Case #" << tc << ": ";
		for(int i = 0 ; i < N ; i++) {
			findSetBitVector(input[0], devices[i]);
		}
		for(int i = 0 ; i < (int) setBitVector.size() ; i++) {
			if(isConvertible(input, devices, N, L, setBitVector[i])) {
				ans = min(ans, countSetBit(setBitVector[i]));
			} else {
				continue;
			}
		}
		if(ans == 1024) {
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << ans << endl;
		}
	}
}

int main() {
	freopen("C:/Users/deepd/Downloads/in.txt", "r", stdin);
	freopen("C:/Users/deepd/Downloads/out.txt", "w", stdout);
	solvePr1();
	return 0;
}
