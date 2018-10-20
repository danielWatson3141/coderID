#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int n, m;
const int maxn = 1005;
vector<int> path[maxn];
int size[maxn];
int dfs(int history, int now){
	int mi = 0, second = 0, sum = 0;
	size[now] = 1;
	int cnt = 0;
	for (int i = 0; i<path[now].size(); i++){
		int tmp;

		if (path[now][i] != history){
			cnt ++ ;
			tmp = dfs(now, path[now][i]);
//			cout << path[now][i] << ' ' << tmp << endl;
			size[now] += size[path[now][i]];
			int tmp2 = size[path[now][i]] - tmp;
			if (tmp2 > mi) {
				second = mi;
				mi = tmp2;

			}
			else if (tmp2 > second){
				second = tmp2;
			}
		}
	}
	if (cnt == 0){
		return 0;
	}
	else if (cnt == 1){
		return size[now] - 1;
	}
	else return size[now] - 1 - mi - second;
}
const int maxInt = 1232123212;
int ans = maxInt;
int main(){
	ifstream in("2.in");
	ofstream out("2.out");
	int testSum;
	in >> testSum;
	for (int test = 1; test <= testSum; test++){
		in >> n;
		ans = maxInt;
		for (int i = 1; i <= n; i++){
			path[i].clear();
			size[i] = 0;

		}
		int x, y;
		for (int j = 1; j <= n-1; j ++){
			in >> x >> y;
//			cout << x << y << endl;
			path[x].push_back(y);
			path[y].push_back(x);
		}
//		for (int j = 1; j <= n; j++){
//			cout << "size" << path[j].size() << endl;
//			for (int i = 0; i<path[j].size(); i++)
//				cout << path[j][i] << ' ';
////			cout << endl;
//		}
		int tmp;
		for (int i = 1; i <= n; i++){
			tmp = dfs(0, i);
//			for (int j = 1; j <= n; j++){
//				cout << size[j] << ' ';
//			}
//			cout << endl;
//			cout << i << ' ' << tmp << endl;
			if (tmp < ans)
				ans = tmp;
		}
		out <<"Case #" << test << ": "  << ans << endl;
	}
}

