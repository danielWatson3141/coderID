#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define M 200

string s[M],t[M],d[M];
int n, l;

int sum(string s){
	int ans = 0;
	for (int i = 0; i < l; ++i)
	if (s[i] == '1')
		++ans;
	return ans;
}

string app(string s, string t){
	string ans(s);
	for (int i = 0; i < l; ++i)
	if (t[i] == '1')
		ans[i] = '0' + '1' - s[i];
	return ans;
}

void apply(string to){
	for (int i = 0; i < n; ++i)
		d[i] = app(s[i], to);
	
}

bool pos(void){
	int s = 0;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	if (d[i] == t[j])
		++s;
	return s == n;
}

void read(void){
	cin >> n >> l;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		cin >> t[i];
}

void kill(void){
	int ans = l + 10;
	for (int i = 0; i < n; ++i){
		string to = app(s[i], t[0]);
		apply(to);
		if (pos())
			ans = min(ans, sum(to));
	}
	if (ans == l + 10)
		cout << "NOT POSSIBLE";
	else
		cout << ans;
}

int main(){
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i){
		read();
		cout << "Case #" << i << ": ";
		kill();
		cout << "\n";
	}

	return 0;
}