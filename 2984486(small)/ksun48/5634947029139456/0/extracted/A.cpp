#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
int n;
int l;
int ans;
string out[200];
string dev[200];
int flip(int k){
	LL o[n];
	LL d[n];
	for(int c = 0; c < n; c++){
		o[c] = 0;
		d[c] = 0;
		for(int i = 0; i < k; i++){
			o[c] *= 2;
			d[c] *= 2;
			if(out[c][i] == '1') o[c]++;
			if(dev[c][i] == '1') d[c]++;
		}
	}
	sort(o, o+n);
	sort(d, d+n);
	for(int i = 0; i < n; i++){
		if(o[i] != d[i]){
			return 1000;
		}
	}
	if(k == l){
		return 0;
	}
	int a1 = flip(k+1);
	for(int c = 0; c < n; c++){
		if(out[c][k] == '0'){
			out[c][k] = '1';
		} else {
			out[c][k] = '0';
		}
	}
	int a2 = flip(k+1)+1;
	for(int c = 0; c < n; c++){
		if(out[c][k] == '0'){
			out[c][k] = '1';
		} else {
			out[c][k] = '0';
		}
	}
	return min(a1, a2);
}
main() {
	FILE *fin = freopen("A-small-attempt0.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("A-small-attempt0.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		cin >> n >> l;
		for(int i = 0; i < n; i++) cin >> out[i];
		for(int i = 0; i < n; i++) cin >> dev[i];
		ans = flip(0);
		if(ans >= 1000){
			cout << "NOT POSSIBLE" << endl;
		} else {
			cout << ans << endl;
		}
	}
	exit(0);
}