#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int oo = 0xFFFF;

vector<long long> A, B;
int T, N, L;

int main(){
	
	cin >> T;
	for (int testcase = 1; testcase <= T; ++testcase){
		int result = oo;

		cin >> N >> L;

		A.clear();
		B.clear();

		for (int i = 0; i < N; ++i){
			char buf[1 << 15];
			int key = 0;
			cin >> buf;
			for (int i = 0; i < L; ++i)
				key = key * 2 + buf[i] - 48;
			A.push_back(key);
		}
		for (int i = 0; i < N; ++i){
			char buf[1 << 15];
			int key = 0;
			cin >> buf;
			for (int i = 0; i < L; ++i)
				key = key * 2 + buf[i] - 48;
			B.push_back(key);
		}
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		for (int k = 0; k < N; ++k){
			long long x = A[0] ^ B[k];
			for (int i = 0; i < N; ++i)
				B[i] ^= x;
			sort(B.begin(), B.end());

			bool isSame = 1;
			for (int i = 0; i < N; ++i)
				if (A[i] != B[i]){
					isSame = 0;
					break;
				}

			for (int i = 0; i < N; ++i)
				B[i] ^= x;
			sort(B.begin(), B.end());			


			if (isSame){
				int c = 0;
				while (x != 0){
					x ^= x & (-x);
					++c;
				}
				if (c < result)
					result = c;
			}

		}
		cout << "Case #" << testcase << ": ";
		if (result == oo)
			cout << "NOT POSSIBLE" << endl;
		else 
			cout << result << endl;
	}
	return 0;
}