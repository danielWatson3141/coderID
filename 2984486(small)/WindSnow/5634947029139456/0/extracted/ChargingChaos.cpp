#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin("A-small-attempt0.in");
ofstream fout("A-small-attempt0.out");

#define cin fin
#define cout fout

int N, L;
string dev[200], out[200];
int cd[200], co[200];
int best;
int path[200];
const int INF = 10000;

int check() {
	string t[200];
	for (int i = 0; i < N; ++i)
		t[i] = out[i];
	for (int i = 0; i < L; ++i) {
		if (path[i] == 0) continue;
		for (int j = 0; j < N; ++j)
			if (t[j][i] == '0') t[j][i] = '1';
			else t[j][i] = '0';
	}
	sort(t, t + N);
	for (int i = 0; i < N; ++i)
		if (t[i] != dev[i]) return 0;
	return 1;
}

void search(int depth, int count) {
	if (depth == L) {
		if (count < best && check()) {
			best = count;
		}
		return;
	}
	path[depth] = 0;
	if (co[depth] == cd[depth])
		search(depth + 1, count);
	path[depth] = 1;
	if (N - co[depth] == cd[depth])
		search(depth + 1, count + 1);
}

void run() {
	cin>>N>>L;
	for (int i = 0; i < N; ++i)
		cin>>out[i];
	for (int i = 0; i < N; ++i)
		cin>>dev[i];
	sort(dev, dev + N);
	for (int k = 0; k < L; ++k) {
		co[k] = 0;
		for (int i = 0; i < N; ++i)
			co[k] += out[i][k] == '1';
	}
	for (int k = 0; k < L; ++k) {
		cd[k] = 0;
		for (int i = 0; i < N; ++i)
			cd[k] += dev[i][k] == '1';
	}
	best = INF;
	search(0, 0);
	if (best == INF) {
		cout<<"NOT POSSIBLE"<<endl;
	} else {
		cout<<best<<endl;
	}
}

int main() {
	int t;
	cin>>t;
	for (int i = 1; i <= t; ++i) {
		cout<<"Case #"<<i<<": ";
		run();
	}
	return 0;
}