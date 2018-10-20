#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
const int N = 20;
int n;
bool mp[N][N],flag[N],visited[N];
int ans;
bool root(int pos) {
//	cout <<"pos :" << pos << endl;
	int left, right, cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (cnt > 2) return false;
		if (!visited[i] && mp[pos][i]) {
			if (cnt == 0) left = i;
			else if (cnt == 1) right = i;
			cnt++;
		}
	}
	if (cnt == 1) return false;
	visited[pos] = true;
	if (cnt == 0) return true;
	return root(left) && root(right);
}
bool check() {
	for (int i = 1; i <= n; i++) {
		memset(visited, false, sizeof(visited));
		if (flag[i] && root(i)) {
			for (int j = 1; j <= n; j++) 
				if (flag[j] && !visited[j]) return false;
				return true;
		}
	}
	return false;		
}
void solve(int pos, int cnt) {
	if (ans>=0 && cnt >= ans) return;
	if (check())
		if (ans==-1||ans>cnt) ans = cnt;
	if (pos > n) return;
	//backup
	bool tmp[n+1][n+1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			tmp[i][j] = mp[i][j];
	//change
	for (int i = 1; i <= n; i++)
		mp[pos][i] = mp[i][pos] = false;
	flag[pos] = false;
	solve(pos+1,cnt+1);
	//unchange
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			mp[i][j] = tmp[i][j];
	flag[pos] = true;
	solve(pos+1,cnt);
}
	
int main()
{
//	fstream cin("C:\\Users\\swcandy\\Desktop\\B-small-attempt1.in", ios::in);
//	fstream cout("C:\\Users\\swcandy\\Desktop\\B-small-attempt1.out", ios::out);
	
	int t,times=0;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(mp, false, sizeof(mp));
		memset(flag, true, sizeof(flag));
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			int ori = 0;
			mp[a][b] = mp[b][a] = true;
		}
		ans = -1;
		solve(1,0);
		cout << "Case #" << ++times << ": " << ans << endl;
	}
	return 0;
}
			
		