#include <bits/stdc++.h>

using namespace std;

string s_in[500], s_out[500], s_temp[500];
int n, L, a[500];
int dem = 0, ntest, res;

char flip(char x, int j){
	if (j == 0) {
		if (x == '1') return '1';
		else return '0';
	} else {
		if (x == '1') return '0';
		else return '1';
	}
}

void update(){
	for (int i = 1; i <= n; i++) {
		s_temp[i] = "";
		for (int j = 0; j <= L - 1; j++) {
			s_temp[i] += flip(s_in[i][j], a[j + 1]);
 		}
	}	
	
	sort(s_temp + 1, s_temp + n + 1);
		
	bool ok = true;	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= L - 1; j++) {
			if (s_temp[i][j] != s_out[i][j]) {
				ok = false;
				break;
			}
		}
		if (!ok) break;
	}	
	if (ok) {
		if (dem < res) {
			res = dem;
		}
	}
}

void rec(int i){
	for (int j = 0; j <= 1; j++){
		a[i] = j;
		dem += j;
		if (i == L) update();
		else
		rec(i + 1);
		dem -= j;
	}
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> ntest;
	for (int test = 1; test <= ntest; test++){
		cin >> n >> L;
		for (int i = 1; i <= n; i++){
			cin >> s_in[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> s_out[i];
		}
		sort(s_in + 1, s_in + n + 1);
		sort(s_out + 1,s_out + n + 1);
		
		
		res = 1000000000;
		rec(1);
		if (res == 1000000000) {
			cout << "Case #" << test << ": " << "NOT POSSIBLE" << endl;
		} else
		cout << "Case #" << test << ": " << res << endl;
	}
}
