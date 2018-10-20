#include <cstdio>
#include <cstdlib>
#include <string>
#include <set>
#include <iostream>

#define MAXN 152
#define MAXL 42

using namespace std;

int T, N, L;
int ar[MAXN][MAXL];
int socket[MAXN][MAXL];
int ns[MAXN][MAXL];
set<string> visit;

string getDiff(int x, int y) {
	string str;
	for(int i=0; i < L; i++) {
		if (ar[x][i] == socket[y][i])
			str.append("0");
		else
			str.append("1");
	}
	return str;
}

int calc(string val) {
	int cnt = 0;
	for(int i=0; i < L; i++)
		if(val[i] == '1')
			cnt++;
	return cnt;
}

bool match(int x, int y) {
	for(int i=0; i < L; i++)
		if(ns[y][i] != ar[x][i])
			return false;
	return true;
}

bool control(string val) {
	bool matched[N+1];
	bool taken[N+1];
	for(int j=0; j < N; j++) {
		for(int i=0; i < L; i++) {
			ns[j][i] = (val[i] == '1') ? !socket[j][i] : socket[j][i];
		}
	}

	for(int i=0; i < N; i++)
		taken[i] = matched[i] = false;

	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			if(!taken[j] && match(i,j)) {
				taken[j] = matched[i] = true;
				break;
			}

	for(int i=0; i < N; i++)
		if(!matched[i])
			return false;
	return true;
}

void printAll() {
	cout << "ar: " << endl;
	for(int i=0; i < N; i++) {
		for(int j=0; j < L; j++) {
			cout << ar[i][j];
		}
		cout << endl;
	}

	cout << "soc: " << endl;
	for(int i=0; i < N; i++) {
		for(int j=0; j < L; j++) {
			cout << socket[i][j];
		}
		cout << endl;
	}

	cout << "ns: " << endl;
	for(int i=0; i < N; i++) {
		for(int j=0; j < L; j++) {
			cout << ns[i][j];
		}
		cout << endl;
	}
}

int proc() {
	int cnt;
	int res = 500;
	visit.clear();
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++) {
			string val = getDiff(i, j);
			if(visit.find(val) == visit.end()) {
				visit.insert(val);
				if(control(val)) {
					cnt = calc(val);
					if (cnt < res) {
						res = cnt;
					}
				}
			}
		}
	return res;
}

int main() {
	string str;
	cin >> T;
	for (int t=1; t <= T; t++) {
		cin >> N >> L;
		for (int i=0; i < N; i++) {
			cin >> str;
			for (int j=0; j < L; j++) {
				ar[i][j] = (str[j] == '1') ? 1 : 0;
			}
		}

		for (int i=0; i < N; i++) {
			cin >> str;
			for (int j=0; j < L; j++) {
				socket[i][j] = (str[j] == '1') ? 1 : 0;
			}
		}

		cout << "Case #" << t << ": ";
		int res = proc();
		if(res == 500)
			cout << "NOT POSSIBLE\n";
		else
			cout << res << endl;
	}	
	return 0;
}