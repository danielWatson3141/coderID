#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define double long double
#define LL long long
#define itn int

using namespace std;

string f(int x){
	string s = "";
	while (x > 0){
		s = (char)('0' + x % 10) + s;
		x /= 10;
	}
	if (s == "") return "0"; else return s;
}

int main(){


	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cout << "Case #" << _ + 1 << ": ";
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		if (a[0] >= n / 7 && a[0] <= 4 * n / 7) cout << "BAD\n"; else cout << "GOOD\n";
	}
	
	/*
	int n = 5;
	int M = 1;
	for (int i =0 ; i < n ; i++) M *= n;
	vector<string> s(M);
	for (int m = 0; m < M; m++){
		vector<int> a(n);
		int k = m;
		for (int i = 0; i < n; i++) a[i] = i;
		for (int i = 0; i < n; i++){
			swap(a[i], a[k % n]);
			k /= n;
		}
		s[m] = "";
		for (int i = 0; i < n; i++) s[m] += f(a[i]);
	}
	sort(s.begin(), s.end());
	int F = 1;
	for (int i = 0; i < n; i++) F *= (i + 1);
	int i = 0;
	int j = 0;
	while (i < M){
		while (j == i || (j < M && s[j] == s[j - 1])) j++;
		if ((j - i) * F > M)
		cout << s[i] << ": " << j - i << "\n";
		i = j;
	} */

	return 0;
	
}