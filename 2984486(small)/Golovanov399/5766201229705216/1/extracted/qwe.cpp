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

/*
string f(int x){
	string s = "";
	while (x > 0){
		s = (char)('0' + x % 10) + s;
		x /= 10;
	}
	if (s == "") return "0"; else return s;
}
*/

int main(){

	
	int T;
	cin >> T;
	for (int _ = 0; _ < T; _++){
		cout << "Case #" << _ + 1 << ": ";
		int n;
		cin >> n;
		vector<vector<int> > a(n);
		for (int i = 0; i < n - 1; i++){
			int x, y;
			cin >> x >> y;
			x--; y--;
			a[x].pb(y);
			a[y].pb(x);
		}
		int ans = n;
		for (int i = 0; i < n; i++){
			vector<int> cnt(n, 1);
			vector<int> aa(n);
			vector<int> st;
			vector<int> p;
			vector<bool> used(n, false);
			st.pb(i);
			while (!st.empty()){
				int x = st.back();
				st.pop_back();
				p.pb(x);
				used[x] = true;
				for (int j = 0; j < a[x].size(); j++) if (!used[a[x][j]]) st.pb(a[x][j]);
			}
			reverse(p.begin(), p.end());
	//		for (int j = 0; j < p.size(); j++) cout << p[j] << " ";
			for (int j = 0; j < n; j++){
				int x = 0;
				used[p[j]] = false;
				for (int ij = 0; ij < a[p[j]].size(); ij++){
					if (!used[a[p[j]][ij]]){
						x++;
						cnt[p[j]] += cnt[a[p[j]][ij]];
					}
				}
				if (x < 2) aa[p[j]] = cnt[p[j]] - 1; else {
					aa[p[j]] = cnt[p[j]] - 1;
					for (int ij = 0; ij < a[p[j]].size(); ij++) if (!used[a[p[j]][ij]]) st.pb(aa[a[p[j]][ij]] - cnt[a[p[j]][ij]]);
					sort(st.begin(), st.end());
					aa[p[j]] += st[0] + st[1];
					st.clear();
				}
			}
			if (aa[i] < ans) ans = aa[i];
		}
		cout << ans << "\n";
	}
	
	/*
	int n = 4;
	vector<string> qw;
	for (int m = 0; m < 64; m++){
		vector<int> a(n);
		int mm = m;
		for (int i = 0; i < n; i++) a[i] = i;
		for (int i = 0; i < n; i++){
			swap(a[i], a[mm % 4]);
			mm /= 4;
		}
		string s = "";
		for (int i = 0; i < n; i++) s += f(a[i]);
		qw.pb(s);
	}
	sort(qw.begin(), qw.end());
	for (int i = 0; i < 64; i++) cout << qw[i] << "\n";
	*/
	
	return 0;
	
}