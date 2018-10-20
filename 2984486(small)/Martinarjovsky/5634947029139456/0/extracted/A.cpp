#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;

ifstream fin ("A.in");
ofstream fout ("A.out");
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define abs(x) ((x)<0 ? -(x) : (x))

int getMin(int N, int L, vi A, vi B, vvi &O, vvi &F) {
	if (L == 0) return 0;
	int i, j, res1 = 300, res2 = 300, acum;
	bool flag1 = false, flag2 = false;
	vi zerosO, onesO, zerosF, onesF;
	for (i = 0; i < sz(A); i++) {
		if (O[A[i]][L-1] == 1) onesO.pb(A[i]);
		else zerosO.pb(A[i]);
		if (F[B[i]][L-1] == 1) onesF.pb(B[i]);
		else zerosF.pb(B[i]);
	}
	if (sz(zerosO) == sz(zerosF)) {
		res1 = 0;
		acum = getMin(sz(zerosO), L-1, zerosO, zerosF, O, F);
		if (acum == -1) flag1 = true;
		res1 += acum;
		acum = getMin(sz(onesO), L-1, onesO, onesF, O, F);
		if (acum == -1) flag1 = true;
		res1 += acum;
	}
	if (sz(zerosO) == sz(onesF)) {
		res2 = 1;
		acum = getMin(sz(zerosO), L-1, zerosO, onesF, O, F);
		if (acum == -1) flag2 = true;
		res2 += acum;
		acum = getMin(sz(onesO), L-1, onesO, zerosF, O, F);
		if (acum == -1) flag2 = true;
		res2 += acum;
	}
	if (sz(zerosO) != sz(zerosF) && sz(zerosO) != sz(onesF)) return -1;

	if (flag1 && flag2) return -1;
	if (flag1 && !flag2) return res2;
	if (!flag1 && flag2) return res1;
	if (!flag1 && !flag2) return min(res1, res2);
	return 2;
}

int main() {
	int T, N, L, c, i, j, res;
	char temp;
	vi A, B;
	fin >> T;
	vvi O, F;
	for (c = 1; c <= T; c++) {
		O.clear();
		F.clear();
		A.clear();
		B.clear();
		fin >> N >> L;
		O.resize(N, vi(L, 0));
		F.resize(N, vi(L, 0));
		for (i = 0; i < N; i++) {
			for (j = 0; j < L; j++) {
				fin >> temp;
				if (temp != '1' && temp != '0') j--;
				if (temp == '1') O[i][j] = 1;
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < L; j++) {
				fin >> temp;
				if (temp != '1' && temp != '0') j--;
				if (temp == '1') F[i][j] = 1;
			}
		}
		for (i = 0; i < N; i++) {
			A.pb(i);
			B.pb(i);
		}
		res = getMin(N, L, A, B, O, F);
		if (res == -1) fout << "Case #" << c << ": NOT POSSIBLE"<< endl;
		else fout << "Case #" << c << ": " << res << endl;

	}

	return 0;
}
