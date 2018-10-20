#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <sstream>
using namespace std;

vector<string> A, B;
int CA[50], CB[50];
int N, L;
bool T[50];
set<string> TEMP;
stringstream ssin;

int backtrack(int k) {
	if (k==L) {
		int count = 0;
		for(int j=0; j<L; j++)
			if (T[j])
				count++;

		TEMP.clear();
		for(int i=0; i<N; i++) {
			ssin.str("");
			for(int j=0; j<L; j++) {
				if ((A[i][j] == '1') != T[j])
					ssin << '1';
				else
					ssin << '0';
			}
			TEMP.insert(ssin.str());
		}

		for(int i=0; i<N; i++)
			if (TEMP.find(B[i]) == TEMP.end())
				return 0x1f1f1f1f;

		return count;
	}

	int minn = 0x1f1f1f1f;
	if (CA[k] == CB[k]) {
		T[k] = false;
		minn = min(minn, backtrack(k+1));
	}

	if (N-CA[k] == CB[k]) {
		T[k] = true;
		minn = min(minn, backtrack(k+1));
	}
	return minn;
}

int main() {
	int tests; cin >> tests;
	for(int test=1; test<=tests; test++) {
		A.clear(); B.clear();
		memset(CA, 0, sizeof CA);
		memset(CB, 0, sizeof CB);
		
		cin >> N >> L;
		for(int i=0; i<N; i++) {
			string temp; cin >> temp; A.push_back(temp);

			for(int j=0; j<L; j++)
				if(temp[j] == '1')
					CA[j]++;
		}

		for(int i=0; i<N; i++) {
			string temp; cin >> temp; B.push_back(temp);

			for(int j=0; j<L; j++)
				if(temp[j] == '1')
					CB[j]++;
		}

		cout << "Case #" << test << ": ";

		int answer = backtrack(0);
		if (answer <= L)
			cout << answer << endl;
		else
			cout << "NOT POSSIBLE" << endl;
	}
}