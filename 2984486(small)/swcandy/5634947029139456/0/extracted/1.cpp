#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
const int N = 15;
int n,l;
int start[N], end[N];
int ans;
bool check() {
	int tmp[n+1];
	for (int i = 0; i < n; i++)
		tmp[i] = start[i];
	sort(tmp, tmp+n);
	sort(end, end+n);
	for (int i = 0; i < n; i++)
		if (tmp[i] != end[i]) return false;
	return true;
}
void solve(int pos, int cnt) {
//	cout << pos << " " << cnt << endl;
	if (pos > l) return;
	if (check())
		if (ans==-1||ans>cnt) ans = cnt;
	//change
	for (int j = 0; j < n; j++) 
		start[j] ^= (1 << pos);
	solve(pos+1,cnt+1);
	//unchange
	for (int j = 0; j < n; j++) 
		start[j] ^= (1<<pos); 
	solve(pos+1,cnt);
}
	
int main()
{
	//fstream cin("C:\\Users\\swcandy\\Desktop\\A-small-attempt2.in", ios::in);
	//fstream cout("C:\\Users\\swcandy\\Desktop\\A-small-attempt2.out", ios::out);
	
	int t,times=0;
	cin >> t;
	while (t--) {
		cin >> n >> l;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			int ori = 0;
			for (int j = 0; j < str.length(); j++) {
				start[i] = ori*2+str[j]-'0';
				ori = start[i];
			}
		}
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			int ori = 0;
			for (int j = 0; j < str.length(); j++) {
				end[i] = ori*2+str[j]-'0';
				ori = end[i];
			}
		}
		if (check()) {
			cout << "Case #" << ++times << ": " << 0 << endl;
			continue;
		}
		ans = -1;
		solve(0,0);
		if (ans < 0) 
			cout << "Case #" << ++times << ": NOT POSSIBLE" << endl;
		else cout << "Case #" << ++times << ": " << ans << endl;
	}
	return 0;
}
			
		